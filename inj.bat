@echo off
rem Script to run mminjector with specified parameters

rem Define paths
set INJECTOR_PATH=C:\Dev\Projects\Cheating\SPY-Injector\build\Debug\mminjector
set DLL_PATH=C:\Dev\Projects\Cheating\i-n-t-e-r-n-a-l\build\Debug\csgowin64.dll
set PROCESS_NAME=cs2.exe

rem Run the command
"%INJECTOR_PATH%" "%DLL_PATH%" "%PROCESS_NAME%"

rem Pause to keep the window open (optional)
pause