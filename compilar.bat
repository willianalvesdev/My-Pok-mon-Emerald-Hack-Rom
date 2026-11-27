@echo off
setlocal
title Compilar Pokemon Emerald
echo Compilando a ROM. Aguarde...
echo.
wsl.exe -d Ubuntu-24.04 --cd "%~dp0." -- bash ./dev_scripts/compile_rom.sh
if errorlevel 1 (
    echo.
    echo ERRO: a compilacao falhou. Confira as mensagens acima.
    pause
    exit /b 1
)
echo.
echo ROM compilada com sucesso!
echo Arquivo: %~dp0pokeemerald.gba
pause
