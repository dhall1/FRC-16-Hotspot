@ECHO OFF > out.txt
SETLOCAL enabledelayedexpansion enableextensions

IF "%~1"=="" (
	ECHO Command should be used: build.bat [Drive in which eclipse installation exists]
	ECHO eg build.bat C:\
	GOTO :EOF
)

DIR *.cpp *.c /b/s > out.txt
SET COUNT=0
SET FILES[0]=null
for /F "tokens=*" %%A in (out.txt) do (
	SET /A COUNT=!COUNT! + 1
	SET OUTPUT=%%A
    if "x!OUTPUT:~-4!"=="x.cpp" (
        SET OUTPUT=!OUTPUT:~0,-4!
    )
    if "x!OUTPUT:~-2!"=="x.c" (
    	SET OUTPUT=!OUTPUT:~0,-2!
    )
    SET FILES[!COUNT!]="!OUTPUT!.o"
    arm-frc-linux-gnueabi-g++ -std=c++1y "-I%1%HOMEPATH%\\wpilib\\cpp\\current\\include" "-I%CD%\\src" -O0 -g3 -Wall -c -fmessage-length=0 -o !OUTPUT!.o %%A
)

SET link_files=arm-frc-linux-gnueabi-g++ "-L%1%HOMEPATH%\\wpilib\\cpp\\current\\lib" -Wl,-rpath,/opt/GenICam_v2_3/bin/Linux_armv7-a,-rpath,/usr/local/frc/rpath-lib -o FRCUserProgram
for /l %%N in (1,1,!COUNT!) do ( 
    ECHO !FILES[%%N]! 
    SET "link_files=!link_files! !FILES[%%N]!"
)
SET "link_files=!link_files! -lwpi"
ECHO !link_files!
!link_files!
for /l %%N in (1,1,!COUNT!) do (
	DEL !FILES[%%N]!
)

DEL out.txt
:EOF
ENDLOCAL