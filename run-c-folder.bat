
@echo off
setlocal EnableExtensions EnableDelayedExpansion

if "%~1"=="" (
    echo FEHLER: Keine C-Datei angegeben.
    exit /b 1
)

if not exist "%~1" (
    echo FEHLER: Datei "%~1" nicht gefunden.
    exit /b 1
)

for %%F in ("%~f1") do (
    set "DIR=%%~dpF"
    set "PROGRAM=%%~dpnF.exe"
)

pushd "!DIR!" || exit /b 1

set "SOURCES="

for %%F in (*.c) do (
    set "SOURCES=!SOURCES! "%%~fF""
)

echo.
echo Kompiliere gesamtes C-Projekt...
echo ----------------------------------------

gcc -std=c11 -Wall -Wextra -Wpedantic -g !SOURCES! -o "!PROGRAM!"

if errorlevel 1 (
    echo.
    echo FEHLER: Kompilierung fehlgeschlagen.
    popd
    pause
    exit /b 1
)

echo.
echo Starte Programm...
echo ----------------------------------------
echo.

"!PROGRAM!"
set "RESULT=!ERRORLEVEL!"

echo.
echo Programm beendet. Exit-Code: !RESULT!

popd
pause
exit /b !RESULT!
