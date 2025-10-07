@echo off
cls
echo Compilando Simulador de Impresora...

set SRC=src\cola.c src\gui.c
set INCLUDE=headers
gcc main.c %SRC% -I%INCLUDE% -o impresora.exe

if %errorlevel%==0 (
    echo Compilacion exitosa!
    echo Ejecutando programa...
    impresora.exe
) else (
    echo Error en la compilacion.
)
pause
