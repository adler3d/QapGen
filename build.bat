setlocal enabledelayedexpansion
set ERRORLEVEL=0
cd stable
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
call ./build.bat
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
cd ../src/QapGenV2025
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
call ./build.bat
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
echo done in build.bat