setlocal enabledelayedexpansion
rem ¬ключаем прерывание при ошибке
set ERRORLEVEL=0
cd stable
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
./build.bat
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
cd ../src/QapGenV2025
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
./build.bat
if errorlevel 1 (
  echo err, stop working
  exit /b %errorlevel%
)
echo done in build.bat