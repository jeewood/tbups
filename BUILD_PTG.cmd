@echo off
nmake /f NMakefile
"C:\Program Files\Microchip\MPLAB IDE\Programmer Utilities\PICkit3\PK3CMD.exe" -P33fj16gs504 -M -Fups.hex -L -E