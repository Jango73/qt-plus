@echo off
setlocal EnableExtensions EnableDelayedExpansion

set "EXIT_SUCCESS=0"
set "EXIT_FAILURE=1"

set "ROOT_FOLDER=%~dp0"
set "CLEAN_TARGET=all"

:parse
if "%~1"=="" goto done

if /I "%~1"=="--debug" (
  set "CLEAN_TARGET=debug"
  shift
  goto parse
)
if /I "%~1"=="-d" (
  set "CLEAN_TARGET=debug"
  shift
  goto parse
)
if /I "%~1"=="--release" (
  set "CLEAN_TARGET=release"
  shift
  goto parse
)
if /I "%~1"=="-r" (
  set "CLEAN_TARGET=release"
  shift
  goto parse
)
if /I "%~1"=="--all" (
  set "CLEAN_TARGET=all"
  shift
  goto parse
)
if /I "%~1"=="-a" (
  set "CLEAN_TARGET=all"
  shift
  goto parse
)
if /I "%~1"=="-h" (
  call :usage
  exit /b %EXIT_SUCCESS%
)
if /I "%~1"=="--help" (
  call :usage
  exit /b %EXIT_SUCCESS%
)

echo Unknown option: %~1 1>&2
call :usage 1>&2
exit /b %EXIT_FAILURE%

:done
set "BUILD_DEBUG_FOLDER=%ROOT_FOLDER%build-debug"
set "BUILD_RELEASE_FOLDER=%ROOT_FOLDER%build-release"

if /I "%CLEAN_TARGET%"=="debug" (
  call :remove_folder "%BUILD_DEBUG_FOLDER%"
) else if /I "%CLEAN_TARGET%"=="release" (
  call :remove_folder "%BUILD_RELEASE_FOLDER%"
) else if /I "%CLEAN_TARGET%"=="all" (
  call :remove_folder "%BUILD_DEBUG_FOLDER%"
  call :remove_folder "%BUILD_RELEASE_FOLDER%"
) else (
  echo Invalid clean target: %CLEAN_TARGET% 1>&2
  exit /b %EXIT_FAILURE%
)

exit /b %EXIT_SUCCESS%

:remove_folder
if exist "%~1" (
  rmdir /s /q "%~1"
  echo Removed %~1
) else (
  echo Skip %~1 (not found)
)
exit /b 0

:usage
echo Usage: clean.bat [--debug^|--release^|--all] [-d^|-r^|-a]
echo   --debug,   -d  Remove the debug build folder
echo   --release, -r  Remove the release build folder
echo   --all,     -a  Remove both build folders (default)
exit /b %EXIT_SUCCESS%