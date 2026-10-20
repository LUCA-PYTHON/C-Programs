@echo off
setlocal

if "%~1"=="-h" goto help
if "%~1"=="--help" goto help
if "%~1"=="/?" goto help

set "SOURCE=%~1"

if not defined SOURCE (
    echo FEHLER!
    echo Oeffne eine C-Datei in VS Code und druecke F11.
    exit /b 1
)

if not exist "%SOURCE%" (
    echo FEHLER!
    echo Datei "%SOURCE%" nicht gefunden.
    exit /b 1
)

for %%F in ("%SOURCE%") do set "PROGRAM=%%~dpnF.exe"

gcc -std=c11 -Wall -Wextra -Wpedantic -g "%SOURCE%" -o "%PROGRAM%"

if errorlevel 1 (
    echo.
    echo FEHLER!
    echo Kompilierung fehlgeschlagen.
    pause
    exit /b 1
)

echo.
echo Starte Programm...
echo ----------------------------------------
echo.

"%PROGRAM%"
set "RESULT=%ERRORLEVEL%"

echo.
echo ----------------------------------------
echo Programm beendet. Exit-Code: %RESULT%
echo ----------------------------------------
echo.
pause
exit /b %RESULT%

:help
echo.
echo run-c - C-Programm kompilieren und starten
echo =========================================
echo.
echo Verwendung:
echo   run-c DATEI.c
echo   run-c --help
echo.
echo In VS Code:
echo   C-Datei oeffnen und F11 druecken.
echo.
exit /b 0
