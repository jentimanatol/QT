@echo off
REM Script to verify if required libraries are present and accessible

REM Define expected library paths
set MYSQL_DLL_PATH=C:\Program Files\MySQL\MySQL Server 8.0\lib\libmysql.dll
set QSQLMYSQL_DLL_PATH=C:\BHCC\qt\sql_qt\TestSQLConnection\TestSQLConnection\build\Desktop_Qt_6_8_1_MinGW_64_bit-Debug\bin\sqldrivers\qsqlmysql.dll

echo ============================
echo Checking Libraries Presence
echo ============================

REM Check for libmysql.dll
if exist "%MYSQL_DLL_PATH%" (
    echo libmysql.dll found at "%MYSQL_DLL_PATH%"
) else (
    echo ERROR: libmysql.dll not found at "%MYSQL_DLL_PATH%"
    goto end
)

REM Check for qsqlmysql.dll
if exist "%QSQLMYSQL_DLL_PATH%" (
    echo qsqlmysql.dll found at "%QSQLMYSQL_DLL_PATH%"
) else (
    echo ERROR: qsqlmysql.dll not found at "%QSQLMYSQL_DLL_PATH%"
    goto end
)

echo.
echo ============================
echo Verifying Architecture
echo ============================

REM Use sigcheck.exe to verify architecture (download from Sysinternals if needed)
set TOOL_PATH=sigcheck.exe

if exist "%TOOL_PATH%" (
    echo Using sigcheck to determine architecture...
    "%TOOL_PATH%" "%MYSQL_DLL_PATH%" | findstr /i "32-bit 64-bit"
) else (
    echo WARNING: sigcheck.exe not found. Please download it from Sysinternals for architecture verification.
    echo Skipping architecture detection...
)

:end
echo.
pause
