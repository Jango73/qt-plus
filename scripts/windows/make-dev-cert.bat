@echo off
setlocal EnableExtensions

rem Generates a self-signed certificate + private key for local HTTPS development.
rem Do NOT use the generated files in production, use a certificate from a real CA instead.
rem
rem Usage: make-dev-cert.bat [output-dir] [hostname] [days]
rem Defaults: output-dir=.\certs, hostname=localhost, days=365

set "OUT_DIR=%~1"
if "%OUT_DIR%"=="" set "OUT_DIR=%~dp0..\..\certs"
set "HOST=%~2"
if "%HOST%"=="" set "HOST=localhost"
set "DAYS=%~3"
if "%DAYS%"=="" set "DAYS=365"

where openssl >nul 2>nul
if errorlevel 1 (
  echo openssl not found. Install it first and make sure it is in PATH. 1>&2
  exit /b 1
)

set "CRT_FILE=%OUT_DIR%\localhost.crt"
set "KEY_FILE=%OUT_DIR%\localhost.key"

if exist "%CRT_FILE%" (
  echo Refusing to overwrite existing file: %CRT_FILE% 1>&2
  exit /b 1
)
if exist "%KEY_FILE%" (
  echo Refusing to overwrite existing file: %KEY_FILE% 1>&2
  exit /b 1
)

if not exist "%OUT_DIR%" mkdir "%OUT_DIR%"

openssl req -x509 -newkey rsa:2048 -nodes -keyout "%KEY_FILE%" -out "%CRT_FILE%" -days %DAYS% -subj "/CN=%HOST%" -addext "subjectAltName=DNS:%HOST%,IP:127.0.0.1"
if errorlevel 1 exit /b 1

echo Wrote %CRT_FILE% and %KEY_FILE% (dev only, self-signed for %HOST%).
