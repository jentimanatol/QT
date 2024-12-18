@echo off
cd /d "%~dp0"

REM Loop through all files in the directory
for %%f in (*) do (
    REM Check if the file does not end with the specified extensions and is not .gitignore
    if /I not "%%~xf"==".cpp" if /I not "%%~xf"==".h" if /I not "%%~xf"==".pro" if /I not "%%~xf"==".ui" if /I "%%~nxf" neq ".gitignore" (
        del "%%f"
    )
)

echo Deletion completed!
pause
