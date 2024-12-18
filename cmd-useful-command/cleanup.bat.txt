@echo off
cd /d "%~dp0"

REM Loop through all files in the directory
for %%f in (*) do (
    REM Check if the file does not end with the specified extensions and is not .gitignore or a .bat file
    if /I not "%%~xf"==".cpp" if /I not "%%~xf"==".h" if /I not "%%~xf"==".pro" if /I not "%%~xf"==".ui" if /I not "%%~xf"==".bat" if /I "%%~nxf" neq ".gitignore" (
        echo Deleting file: %%f
        del "%%f"
    )
)

echo Deletion completed!
cmd
