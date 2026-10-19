# C-Programs

Dieses Repository enthält meine Übungen, Beispiele und kleinen Projekte aus dem Bereich der Programmiersprache **C**. Es dient dazu, grundlegende Programmierkonzepte zu lernen, praktisch anzuwenden und meine Fortschritte zu dokumentieren.

## 📁 Projektstruktur

| Ordner | Inhalt |
|---|---|
| `00_test_projekt` | Erste Tests und grundlegende Programme |
| `01_variablen_eingaben` | Variablen, Datentypen und Benutzereingaben |
| `02_bedienungen_operatoren` | Operatoren und Berechnungen |
| `03_Schleifen` | Schleifen wie `for`, `while` und `do-while` |
| `04_Funktionen` | Funktionen, Parameter und Rückgabewerte |
| `05_strings_fehlermeldung` | Zeichenketten und Fehlermeldungen |
| `06_Arrays` | Arrays und die Verarbeitung mehrerer Werte |
| `98_taschenrechner` | Taschenrechner-Projekt |

Die Ordner enthalten einzelne C-Programme, die jeweils unterschiedliche Themen behandeln.

## 🛠️ Voraussetzungen

Für die Entwicklung und Ausführung der Programme werden folgende Werkzeuge empfohlen:

- **Visual Studio Code** als Editor
- **GCC** als C-Compiler
- **Windows-Terminal**, PowerShell oder Eingabeaufforderung
- Optional: **Git** zur Versionsverwaltung

### GCC überprüfen

Öffne ein Terminal und führe folgenden Befehl aus:

```bash
gcc --version
```

Wenn eine Versionsnummer angezeigt wird, ist GCC über den aktuellen Suchpfad erreichbar.

## ▶️ Programme kompilieren und ausführen

Öffne ein Terminal im Projektordner.

### Beispiel: `for_schleife.c`

Wechsle in den Projektordner und kompiliere die Datei:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic -g "03_Schleifen/for_schleife.c" -o for_schleife.exe
```

Starte das kompilierte Programm anschließend unter Windows:

```powershell
.\for_schleife.exe
```

Die Compiler-Optionen helfen dabei, Warnungen zu erkennen und Fehler frühzeitig zu finden.

| Option | Bedeutung |
|---|---|
| `-std=c11` | Verwendet den C11-Standard |
| `-Wall` | Aktiviert viele hilfreiche Warnungen |
| `-Wextra` | Aktiviert zusätzliche Warnungen |
| `-Wpedantic` | Weist auf Abweichungen vom Standard hin |
| `-g` | Fügt Debugging-Informationen hinzu |
| `-o` | Legt den Namen der ausführbaren Datei fest |

## ⚡ Ausführen über Visual Studio Code

Für eine schnellere Entwicklung kann eine VS-Code-Task eingerichtet werden, die die aktuell geöffnete C-Datei kompiliert und startet.

Das Projekt kann dafür beispielsweise eine `run-c.bat` im Hauptverzeichnis enthalten. Eine passende Task-Konfiguration gehört in:

```text
.vscode/tasks.json
```

Die genaue Einrichtung hängt von der lokalen Compiler-Installation und den Sicherheitseinstellungen des Computers ab.

**Hinweis:** Wenn Windows oder ein Sicherheitsprogramm die Batch-Datei blockiert, sollte zuerst der Schutzverlauf überprüft werden. Sicherheitsausnahmen sollten nur für geprüfte, vertrauenswürdige Dateien eingerichtet werden.

## 📚 Lernziele

Mit diesem Projekt möchte ich:

- die Grundlagen der Programmiersprache C verstehen,
- Variablen, Datentypen und Operatoren sicher verwenden,
- Bedingungen und Schleifen einsetzen,
- eigene Funktionen schreiben,
- mit Zeichenketten und Arrays arbeiten,
- Benutzereingaben verarbeiten,
- Fehler erkennen und beheben,
- kleine, eigenständige Programme entwickeln.

## 🚀 Geplante Erweiterungen

- Weitere Übungsaufgaben und Beispiele
- Verbesserte Fehlerbehandlung
- Größere Projekte mit mehreren Funktionen
- Debugging und strukturierter Code
- Dokumentation der wichtigsten Erkenntnisse

## 📌 Hinweis

Dieses Repository ist ein persönliches Lernprojekt. Die Programme dienen hauptsächlich zu Übungs- und Lernzwecken und können sich im Laufe der Zeit verändern.

---

**Viel Spaß beim Programmieren mit C!**
