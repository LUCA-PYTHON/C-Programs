#!/usr/bin/env python3
"""Erzeugt den Lernpfad für das C-Programs-Repository.

Liest den Kommentar-Header am Anfang jeder .c-Datei in den nummerierten
Ordnern (00_..., 01_..., ...) und erzeugt daraus

  * LERNPFAD.md  (eigene Datei, wird komplett neu geschrieben)


Header-Format (ganz am Dateianfang):

    /*
     * titel: for-Schleife
     * schwierigkeit: 1
     * themen: schleifen, for
     */

schwierigkeit: 1 = Einsteiger, 2 = Aufbau, 3 = Fortgeschritten
("level" funktioniert als Schlüsselwort ebenfalls)

Aufrufe (aus dem Repo-Hauptverzeichnis):

    python tools/build_lernpfad.py                 # Dateien erzeugen/aktualisieren
    python tools/build_lernpfad.py --add-missing   # fehlende Header als Gerüst einfügen
    python tools/build_lernpfad.py --check         # nur prüfen, ob alles aktuell ist
    python tools/build_lernpfad.py --strict        # Fehlercode, wenn Header unvollständig
"""
from __future__ import annotations

import argparse
import re
import sys
from dataclasses import dataclass, field
from pathlib import Path
from urllib.parse import quote

ROOT = Path(__file__).resolve().parent.parent

# Einstellungen -------------------------------------------------------------
FOLDER_PATTERN = re.compile(r"^\d{2}_")      # nur Ordner wie 03_Schleifen
EXCLUDE_DIRS: set[str] = set()               # z. B. {"00_test_projekt"}
SKIP_PARTS = {"build", "bin", "obj"}         # Unterordner, die ignoriert werden
LEVELS = {1: "Einsteiger", 2: "Fortgeschritten", 3: "Professionel"}
KEYS = {"titel", "schwierigkeit", "level", "themen"}
OUTPUT_FILE = "LERNPFAD.md"

HEADER_RE = re.compile(r"\A\ufeff?\s*/\*(.*?)\*/", re.S)
LINE_RE = re.compile(r"^\s*\*?\s*(\w+)\s*:\s*(.*?)\s*$")


@dataclass
class Program:
    path: Path
    titel: str
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


# Header lesen --------------------------------------------------------------
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
        m = LINE_RE.match(line)
        if m and m.group(1).lower() in KEYS:
            data[m.group(1).lower()] = m.group(2)
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


def read_program(path: Path) -> Program:
    text = path.read_bytes().decode("utf-8", errors="replace")
    data = parse_header(text)
    level = data.get("level", "")
    return Program(
        path=path,
        titel=data.get("titel") or path.stem.replace("_", " "),
        level=int(level) if level.isdigit() and int(level) in LEVELS else None,
        themen=[t.strip() for t in data.get("themen", "").split(",") if t.strip()],
        missing=missing_keys(data),
    )


# Dateien finden ------------------------------------------------------------
def number_dirs() -> list[Path]:
    return sorted(
        p for p in ROOT.iterdir()
        if p.is_dir() and FOLDER_PATTERN.match(p.name) and p.name not in EXCLUDE_DIRS
    )


def c_files(folder: Path) -> list[Path]:
    return sorted(
        p for p in folder.rglob("*.c")
        if not SKIP_PARTS & set(p.relative_to(folder).parts)
    )


def collect() -> list[Folder]:
    folders = []
    for d in number_dirs():
        programs = [read_program(p) for p in c_files(d)]
        programs.sort(key=lambda p: (p.level if p.level is not None else 99, p.path.name.lower()))
        if programs:
            folders.append(Folder(d.name, programs))
    return folders


# Fehlende Header ergänzen --------------------------------------------------
def add_header(path: Path) -> bool:
    raw = path.read_bytes()
    bom = b"\xef\xbb\xbf" if raw.startswith(b"\xef\xbb\xbf") else b""
    body = raw[len(bom):]
    if "titel" in parse_header(body.decode("utf-8", errors="replace")):
        return False
    nl = "\r\n" if b"\r\n" in body else "\n"
    top = path.relative_to(ROOT).parts[0]
    lines = [
        "/*",
        f" * titel: {path.stem.replace('_', ' ')}",
        " * schwierigkeit: 1",
        f" * themen: {folder_title(top).lower()}",
        " */",
    ]
    header = (nl.join(lines) + nl + nl).encode("utf-8")
    path.write_bytes(bom + header + body)
    return True


# Ausgabe erzeugen ----------------------------------------------------------
def cell(text: str) -> str:
    return text.replace("|", "\\|") or "–"


def link(path: Path) -> str:
    return quote(path.relative_to(ROOT).as_posix())


def render_lernpfad(folders: list[Folder]) -> str:
    total = sum(len(f.programs) for f in folders)
    out = [
        "# Lernpfad",
        "",
        "> Diese Datei wird automatisch von `tools/build_lernpfad.py` erzeugt. "
        "Änderungen bitte in den Headern der `.c`-Dateien machen.",
        "",
        f"**{total} Programme in {len(folders)} Themenblöcken.** "
        "Empfohlene Reihenfolge: von oben nach unten.",
        "",
    ]
    for f in folders:
        out += [
            f"## {f.number} · {f.title}",
            "",
            f"Ordner: [`{f.name}/`]({quote(f.name)}/)",
            "",
            "| Titel | Schwierigkeit | Themen |",
            "| --- | --- | --- |",
        ]
        for p in f.programs:
            level = LEVELS.get(p.level, "–")
            out.append(
                f"| [{cell(p.titel)}]({link(p.path)}) | {level} "
                f"| {cell(', '.join(p.themen))} |"
            )
        out.append("")
    return "\n".join(out).rstrip() + "\n"


# Dateien lesen/schreiben (Zeilenenden bleiben erhalten) --------------------
def read_normalized(path: Path) -> tuple[str, str]:
    if not path.exists():
        return "", "\n"
    raw = path.read_bytes().decode("utf-8")
    nl = "\r\n" if "\r\n" in raw else "\n"
    return raw.replace("\r\n", "\n"), nl


def write_normalized(path: Path, content: str, nl: str) -> None:
    path.write_bytes(content.replace("\n", nl).encode("utf-8"))


def rel(path: Path) -> str:
    return path.relative_to(ROOT).as_posix()


# Hauptprogramm -------------------------------------------------------------
def main() -> int:
    ap = argparse.ArgumentParser(description="Erzeugt LERNPFAD.md aus den Headern der .c-Dateien.")
    ap.add_argument("--add-missing", action="store_true",
                    help="fügt fehlende Header als Gerüst in .c-Dateien ein")
    ap.add_argument("--check", action="store_true",
                    help="schreibt nichts, Fehlercode 1 wenn Dateien veraltet sind")
    ap.add_argument("--strict", action="store_true",
                    help="Fehlercode 1, wenn Header fehlen oder unvollständig sind")
    args = ap.parse_args()

    for stream in (sys.stdout, sys.stderr):
        if hasattr(stream, "reconfigure"):
            stream.reconfigure(encoding="utf-8")

    if args.add_missing:
        added = [p for d in number_dirs() for p in c_files(d) if add_header(p)]
        for p in added:
            print(f"Header ergänzt: {rel(p)}")
        print(f"{len(added)} Header ergänzt. Bitte Schwierigkeit und Themen prüfen.")

    folders = collect()
    if not folders:
        print("Keine nummerierten Ordner mit .c-Dateien gefunden.", file=sys.stderr)
        return 1

    incomplete = [p for f in folders for p in f.programs if p.missing]
    for p in incomplete:
        print(f"Warnung: {rel(p.path)} – Header unvollständig ({', '.join(p.missing)})",
              file=sys.stderr)

    outputs: dict[Path, tuple[str, str]] = {
        ROOT / OUTPUT_FILE: (render_lernpfad(folders), "\n"),
    }
    changed = [p for p, (content, _) in outputs.items() if read_normalized(p)[0] != content]
    strict_fail = args.strict and bool(incomplete)

    if args.check:
        for p in changed:
            print(f"Veraltet: {rel(p)}")
        if not changed:
            print("Alles aktuell.")
        return 1 if (changed or strict_fail) else 0

    for p in changed:
        content, nl = outputs[p]
        write_normalized(p, content, nl)
        print(f"Aktualisiert: {rel(p)}")
    if not changed:
        print("Alles aktuell.")
    return 1 if strict_fail else 0


if __name__ == "__main__":
    sys.exit(main())