@echo off
setlocal

if "%~1"=="" (
    echo Verwendung: run-c.bat Pfad\datei.c
    exit /b 1
)

set "SOURCE=%~1"
set "PROGRAM=%~dpn1.exe"

gcc -std=c11 -Wall -Wextra -Wpedantic -g "%SOURCE%" -o "%PROGRAM%"

if errorlevel 1 (
    echo.
    echo Kompilierung fehlgeschlagen.
    exit /b 1
)

echo.
echo Programm startet:
echo --------------------
"%PROGRAM%"
