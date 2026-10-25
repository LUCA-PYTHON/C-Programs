#!/usr/bin/env python3
"""
Erzeugt LERNPFAD.md automatisch aus den Headern der C-Dateien.

- C-Dateien direkt im Themenordner werden als Übungen angezeigt.
- Unterordner mit .c-Dateien werden als Projekte innerhalb des Kapitels angezeigt.
- Projektdateien (.c und .h) werden einzeln verlinkt.
- Unterstützt --add-missing, --check und --strict.

Aufrufe im Repository-Hauptverzeichnis:
    python tools/build_lernpfad.py
    python tools/build_lernpfad.py --add-missing
    python tools/build_lernpfad.py --check
    python tools/build_lernpfad.py --strict
"""

from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path
from urllib.parse import quote

ROOT = Path(__file__).resolve().parent.parent

# Einstellungen ---------------------------------------------------------------
FOLDER_PATTERN = re.compile(r"^\d{2}_")
EXCLUDE_DIRS: set[str] = set()
SKIP_PARTS = {"build", "bin", "obj"}
LEVELS = {1: "Einsteiger", 2: "Fortgeschritten", 3: "Professionell"}
KEYS = {"titel", "nr", "schwierigkeit", "level", "themen"}
OUTPUT_FILE = "LERNPFAD.md"

HEADER_RE = re.compile(r"\A\ufeff?\s*/\*(.*?)\*/", re.S)
LINE_RE = re.compile(r"^\s*\*?\s*(\w+)\s*:\s*(.*?)\s*$")


@dataclass
class Program:
    path: Path
    titel: str
    nr: tuple[int, ...] | None = None
    level: int | None = None
    themen: list[str] = field(default_factory=list)
    missing: list[str] = field(default_factory=list)


@dataclass
class Folder:
    name: str
    programs: list[Program]

    @property
    def number(self) -> str:
        return self.name.split("_", 1)[0]

    @property
    def title(self) -> str:
        return folder_title(self.name)


# Header lesen ----------------------------------------------------------------
def folder_title(name: str) -> str:
    if "_" not in name:
        return name
    return name.split("_", 1)[1].replace("_", " ").title()


def parse_header(text: str) -> dict[str, str]:
    match = HEADER_RE.match(text)
    if not match:
        return {}

    data: dict[str, str] = {}

    for line in match.group(1).splitlines():
        match_line = LINE_RE.match(line)

        if match_line and match_line.group(1).lower() in KEYS:
            data[match_line.group(1).lower()] = match_line.group(2)

    if "schwierigkeit" in data:
        data.setdefault("level", data.pop("schwierigkeit"))

    return data


def missing_keys(data: dict[str, str]) -> list[str]:
    missing = []

    if not data.get("titel"):
        missing.append("titel")

    level = data.get("level", "")

    if not level.isdigit() or int(level) not in LEVELS:
        missing.append("schwierigkeit")

    return missing


def parse_nr(value: str) -> tuple[int, ...] | None:
    """'3.10' wird als (3, 10) interpretiert, damit es nach 3.9 kommt."""
    parts = value.strip().split(".")

    if parts and all(part.isdigit() for part in parts):
        return tuple(int(part) for part in parts)

    return None


def read_program(path: Path) -> Program:
    text = path.read_bytes().decode("utf-8", errors="replace")
    data = parse_header(text)
    level = data.get("level", "")

    return Program(
        path=path,
        nr=parse_nr(data.get("nr", "")),
        titel=data.get("titel") or path.stem.replace("_", " "),
        level=int(level) if level.isdigit() and int(level) in LEVELS else None,
        themen=[
            topic.strip()
            for topic in data.get("themen", "").split(",")
            if topic.strip()
        ],
        missing=missing_keys(data),
    )


# Ordner und Dateien finden ---------------------------------------------------
def number_dirs() -> list[Path]:
    return sorted(
        path
        for path in ROOT.iterdir()
        if path.is_dir()
        and FOLDER_PATTERN.match(path.name)
        and path.name not in EXCLUDE_DIRS
    )


def c_files(folder: Path) -> list[Path]:
    """Nur C-Dateien direkt im Themenordner als Übungen behandeln."""
    return sorted(
        path
        for path in folder.glob("*.c")
        if not SKIP_PARTS.intersection(path.relative_to(folder).parts)
    )


def all_c_files(folder: Path) -> list[Path]:
    """Alle C-Dateien rekursiv finden, unter anderem für --add-missing."""
    return sorted(
        path
        for path in folder.rglob("*.c")
        if not SKIP_PARTS.intersection(path.relative_to(folder).parts)
    )


def project_dirs(folder: Path) -> list[Path]:
    """
    Direkte Unterordner mit C-Dateien erkennen.

    So werden beispielsweise main.c und rechner.c innerhalb von
    00_projektstrukturen als zusammengehöriges Projekt dargestellt.
    """
    return sorted(
        path
        for path in folder.iterdir()
        if path.is_dir()
        and path.name not in SKIP_PARTS
        and any(path.glob("*.c"))
    )


def collect() -> list[Folder]:
    folders = []

    for directory in number_dirs():
        programs = [read_program(path) for path in c_files(directory)]

        programs.sort(
            key=lambda program: (
                program.nr is None,
                program.nr or (),
                program.level if program.level is not None else 99,
                program.path.name.lower(),
            )
        )

        if programs or project_dirs(directory):
            folders.append(Folder(directory.name, programs))

    return folders


# Fehlende Header ergänzen ----------------------------------------------------
def add_header(path: Path) -> bool:
    raw = path.read_bytes()
    bom = b"\xef\xbb\xbf" if raw.startswith(b"\xef\xbb\xbf") else b""
    body = raw[len(bom):]

    if "titel" in parse_header(body.decode("utf-8", errors="replace")):
        return False

    newline = "\r\n" if b"\r\n" in body else "\n"
    top_folder = path.relative_to(ROOT).parts[0]

    lines = [
        "/*",
        f" * titel: {path.stem.replace('_', ' ')}",
        " * schwierigkeit: 1",
        f" * themen: {folder_title(top_folder).lower()}",
        " */",
    ]

    header = (newline.join(lines) + newline + newline).encode("utf-8")
    path.write_bytes(bom + header + body)

    return True


# Markdown-Ausgabe ------------------------------------------------------------
def cell(text: str) -> str:
    return text.replace("|", r"\|") or "–"


def link(path: Path) -> str:
    return quote(path.relative_to(ROOT).as_posix())


def render_lernpfad(folders: list[Folder]) -> str:
    total = sum(len(folder.programs) for folder in folders)

    out = [
        "# Lernpfad",
        "",
        "> Diese Datei wird automatisch von `tools/build_lernpfad.py` erzeugt. "
        "Änderungen bitte in den Headern der `.c`-Dateien machen.",
        "",
        f"**{total} Übungen in {len(folders)} Themenblöcken.** "
        "Empfohlene Reihenfolge: von oben nach unten.",
        "",
    ]

    for folder in folders:
        out += [
            f"## {folder.number} · {folder.title}",
            "",
            f"Ordner: [`{folder.name}/`]({quote(folder.name)}/)",
            "",
            "| Titel | Schwierigkeit | Themen |",
            "| --- | --- | --- |",
        ]

        if folder.programs:
            for program in folder.programs:
                level = LEVELS.get(program.level, "–")

                out.append(
                    f"| [{cell(program.titel)}]({link(program.path)}) | {level} "
                    f"| {cell(', '.join(program.themen))} |"
                )
        else:
            out.append("| – | – | – |")

        out.append("")

        # Projekte direkt im jeweiligen Kapitel darstellen.
        projects = project_dirs(ROOT / folder.name)

        for project_index, project in enumerate(projects, start=1):
            relative_path = project.relative_to(ROOT).as_posix()
            project_link = quote(relative_path) + "/"
            project_number = f"{folder.number}.{project_index}"
            project_title = folder_title(project.name)

            out += [
                f"### Projekt {project_number} · "
                f"[{project_title}]({project_link})",
                "",
                f"Ordner: [`{project.name}/`]({project_link})",
                "",
                "| Datei | Zweck |",
                "| --- | --- |",
            ]

            # C-Dateien und Header-Dateien sammeln.
            project_files = sorted(
                [*project.glob("*.c"), *project.glob("*.h")],
                key=lambda item: (
                    item.suffix.lower() != ".c",
                    item.name.lower(),
                ),
            )

            for project_file in project_files:
                file_link = quote(
                    project_file.relative_to(ROOT).as_posix()
                )

                if project_file.suffix.lower() == ".h":
                    purpose = "Header: Funktionsdeklarationen"
                elif project_file.stem.lower() == "main":
                    purpose = "Hauptprogramm"
                else:
                    purpose = "C-Quelldatei"

                out.append(
                    f"| [{cell(project_file.name)}]({file_link}) "
                    f"| {purpose} |"
                )

            out.append("")

    return "\n".join(out).rstrip() + "\n"


# Dateien lesen und schreiben -------------------------------------------------
def read_normalized(path: Path) -> tuple[str, str]:
    if not path.exists():
        return "", "\n"

    raw = path.read_bytes().decode("utf-8")
    newline = "\r\n" if "\r\n" in raw else "\n"

    return raw.replace("\r\n", "\n"), newline


def write_normalized(path: Path, content: str, newline: str) -> None:
    path.write_bytes(content.replace("\n", newline).encode("utf-8"))


def rel(path: Path) -> str:
    return path.relative_to(ROOT).as_posix()


# Hauptprogramm ---------------------------------------------------------------
def main() -> int:
    parser = argparse.ArgumentParser(
        description="Erzeugt LERNPFAD.md aus den Headern der .c-Dateien."
    )

    parser.add_argument(
        "--add-missing",
        action="store_true",
        help="fügt fehlende Header als Gerüst in .c-Dateien ein",
    )

    parser.add_argument(
        "--check",
        action="store_true",
        help="schreibt nichts; Fehlercode 1, wenn Dateien veraltet sind",
    )

    parser.add_argument(
        "--strict",
        action="store_true",
        help="Fehlercode 1, wenn Header fehlen oder unvollständig sind",
    )

    args = parser.parse_args()

    for stream in (sys.stdout, sys.stderr):
        if hasattr(stream, "reconfigure"):
            stream.reconfigure(encoding="utf-8")

    if args.add_missing:
        added = [
            path
            for directory in number_dirs()
            for path in all_c_files(directory)
            if add_header(path)
        ]

        for path in added:
            print(f"Header ergänzt: {rel(path)}")

        print(
            f"{len(added)} Header ergänzt. "
            "Bitte Schwierigkeit und Themen prüfen."
        )

    folders = collect()

    if not folders:
        print(
            "Keine nummerierten Ordner mit .c-Dateien oder Projekten gefunden.",
            file=sys.stderr,
        )
        return 1

    incomplete = [
        program
        for folder in folders
        for program in folder.programs
        if program.missing
    ]

    for program in incomplete:
        print(
            f"Warnung: {rel(program.path)} – Header unvollständig "
            f"({', '.join(program.missing)})",
            file=sys.stderr,
        )

    output_path = ROOT / OUTPUT_FILE
    output_content = render_lernpfad(folders)
    current_content, newline = read_normalized(output_path)

    changed = current_content != output_content
    strict_fail = args.strict and bool(incomplete)

    if args.check:
        if changed:
            print(f"Veraltet: {rel(output_path)}")
        else:
            print("Alles aktuell.")

        return 1 if changed or strict_fail else 0

    if changed:
        write_normalized(output_path, output_content, newline)
        print(f"Aktualisiert: {rel(output_path)}")
    else:
        print("Alles aktuell.")

    return 1 if strict_fail else 0


if __name__ == "__main__":
    sys.exit(main())