@echo off
setlocal EnableExtensions EnableDelayedExpansion

rem Set the qt-plus version everywhere from a single command.
rem Mirrors scripts/linux/set-version.sh for Windows.
rem Usage: set-version.bat [--tag] X.Y.Z

for %%I in ("%~dp0..\..") do set "ROOT_DIR=%%~fI"

set "TAG=0"
set "NEW_VERSION="

:parse
if "%~1"=="" goto done
if /I "%~1"=="--tag" (
  set "TAG=1"
  shift
  goto parse
)
if /I "%~1"=="-h" (
  call :usage
  exit /b 0
)
if /I "%~1"=="--help" (
  call :usage
  exit /b 0
)
if "%~1"=="--" (
  shift
  goto parse
)
if not defined NEW_VERSION (
  set "NEW_VERSION=%~1"
  shift
  goto parse
)
echo Unknown option: %~1 1>&2
call :usage 1>&2
exit /b 1

:done
if not defined NEW_VERSION (
  call :usage 1>&2
  exit /b 1
)

echo %NEW_VERSION% | findstr /R "^[0-9][0-9]*\.[0-9][0-9]*\.[0-9][0-9]*$" >nul
if errorlevel 1 (
  echo Invalid version: %NEW_VERSION% (expected X.Y.Z) 1>&2
  exit /b 1
)

for /F "tokens=1-3 delims=." %%A in ("%NEW_VERSION%") do (
  set "MAJOR=%%A"
  set "MINOR=%%B"
  set "PATCH=%%C"
)

if not exist "%ROOT_DIR%\qt-plus.pro" (
  echo Missing file: %ROOT_DIR%\qt-plus.pro 1>&2
  exit /b 1
)
if not exist "%ROOT_DIR%\CMakeLists.txt" (
  echo Missing file: %ROOT_DIR%\CMakeLists.txt 1>&2
  exit /b 1
)
if not exist "%ROOT_DIR%\source\cpp\qtplus_global.h" (
  echo Missing file: %ROOT_DIR%\source\cpp\qtplus_global.h 1>&2
  exit /b 1
)

> "%ROOT_DIR%\VERSION" echo %NEW_VERSION%

powershell -NoProfile -Command ^
  "$p='%ROOT_DIR%\qt-plus.pro';" ^
  "$c=Get-Content $p;" ^
  "$c=$c -replace '^VERSION = .*','VERSION = %NEW_VERSION%';" ^
  "Set-Content $p $c;" ^
  "if (-not (Select-String -Path $p -Pattern '^VERSION = %NEW_VERSION%$' -Quiet)) { exit 1 }"
if errorlevel 1 (
  echo Failed to update qt-plus.pro 1>&2
  exit /b 1
)

powershell -NoProfile -Command ^
  "$p='%ROOT_DIR%\CMakeLists.txt';" ^
  "$c=Get-Content $p;" ^
  "$c=$c -replace '^project\(qt-plus VERSION [0-9]+\.[0-9]+\.[0-9]+','project(qt-plus VERSION %NEW_VERSION%';" ^
  "Set-Content $p $c;" ^
  "if (-not (Select-String -Path $p -Pattern '^project\(qt-plus VERSION %NEW_VERSION% LANGUAGES CXX\)$' -Quiet)) { exit 1 }"
if errorlevel 1 (
  echo Failed to update CMakeLists.txt 1>&2
  exit /b 1
)

powershell -NoProfile -Command ^
  "$p='%ROOT_DIR%\source\cpp\qtplus_global.h';" ^
  "$c=Get-Content $p;" ^
  "$c=$c -replace '^#define QTPLUS_VERSION_MAJOR .*',\"#define QTPLUS_VERSION_MAJOR %MAJOR%\";" ^
  "$c=$c -replace '^#define QTPLUS_VERSION_MINOR .*',\"#define QTPLUS_VERSION_MINOR %MINOR%\";" ^
  "$c=$c -replace '^#define QTPLUS_VERSION_PATCH .*',\"#define QTPLUS_VERSION_PATCH %PATCH%\";" ^
  "$c=$c -replace '^#define QTPLUS_VERSION_STR .*',\"#define QTPLUS_VERSION_STR `\"\"%NEW_VERSION%`\"\"\";" ^
  "Set-Content $p $c"
if errorlevel 1 (
  echo Failed to update qtplus_global.h 1>&2
  exit /b 1
)

echo Version set to %NEW_VERSION% in:
echo   VERSION
echo   qt-plus.pro
echo   CMakeLists.txt
echo   source/cpp/qtplus_global.h

if "%TAG%"=="1" (
  git -C "%ROOT_DIR%" rev-parse "v%NEW_VERSION%" >nul 2>&1
  if not errorlevel 1 (
    echo Tag v%NEW_VERSION% already exists 1>&2
    exit /b 1
  )
  git -C "%ROOT_DIR%" tag "v%NEW_VERSION%"
  echo Created git tag v%NEW_VERSION%
)

exit /b 0

:usage
echo Usage: set-version.bat [--tag] X.Y.Z
echo   X.Y.Z  new semantic version (e.g. 3.0.0)
echo   --tag  create git tag vX.Y.Z after updating the files
exit /b 0
