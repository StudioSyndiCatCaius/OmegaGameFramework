@echo off
setlocal enabledelayedexpansion

:: ============================================================
::  Fab / Marketplace-style plugin build using RunUAT BuildPlugin
::  Place this .bat in your plugin root (next to the .uplugin)
:: ============================================================

:: ---- CONFIG: set your engine path here ----
set "ENGINE_ROOT=D:\Games\EpicGames\UE_5.5"
:: -------------------------------------------

:: Find the .uplugin in this folder
set "PLUGIN_FILE="
for %%f in ("%~dp0*.uplugin") do set "PLUGIN_FILE=%%~ff"

if not defined PLUGIN_FILE (
    echo ERROR: No .uplugin file found in this folder.
    goto :end
)

echo Found plugin: %PLUGIN_FILE%

:: Output package folder (sibling to plugin folder)
set "OUTPUT_DIR=%~dp0BuildOutput"

:: Log file with timestamp
set "TIMESTAMP=%date:~-4%-%date:~4,2%-%date:~7,2%_%time:~0,2%-%time:~3,2%-%time:~6,2%"
set "TIMESTAMP=%TIMESTAMP: =0%"
set "LOG_FILE=%~dp0BuildLog_%TIMESTAMP%.txt"

set "RUNUAT=%ENGINE_ROOT%\Engine\Build\BatchFiles\RunUAT.bat"

if not exist "%RUNUAT%" (
    echo ERROR: RunUAT.bat not found at:
    echo   %RUNUAT%
    echo Check your ENGINE_ROOT setting.
    goto :end
)

echo.
echo Building plugin... this can take several minutes.
echo Log: %LOG_FILE%
echo.

:: Run RunUAT, tee output to console + log. We capture RunUAT's real exit
:: code by writing it to a temp file from inside the same command, since a
:: pipe makes %ERRORLEVEL% reflect powershell instead of RunUAT.
set "RESULT_FILE=%TEMP%\uat_result_%RANDOM%.txt"

(call "%RUNUAT%" BuildPlugin ^
    -Plugin="%PLUGIN_FILE%" ^
    -Package="%OUTPUT_DIR%" ^
    -Rocket ^
    -TargetPlatforms=Win64 ^
    & call echo %%ERRORLEVEL%% ^> "%RESULT_FILE%") 2>&1 ^
    | powershell -NoProfile -Command "$input | Tee-Object -FilePath '%LOG_FILE%'"

set /p BUILD_RESULT=<"%RESULT_FILE%"
del "%RESULT_FILE%" >nul 2>&1
if not defined BUILD_RESULT set "BUILD_RESULT=1"

echo.
if "%BUILD_RESULT%"=="0" (
    echo ============================================
    echo  BUILD SUCCEEDED
    echo ============================================
) else (
    echo ============================================
    echo  BUILD FAILED ^(exit code %BUILD_RESULT%^)
    echo ============================================
    echo.
    echo --- Lines containing 'error' ---
    findstr /I /C:"error" "%LOG_FILE%"
)

echo.
echo Full log saved to: %LOG_FILE%

:end
echo.
echo Press any key to close...
pause >nul
endlocal