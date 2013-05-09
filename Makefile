# MPLAB IDE generated this makefile for use with GNU make.
# Project: ups.mcp
# Date: Sun Apr 28 23:04:34 2013

AS = pic30-as.exe
CC = pic30-gcc.exe
LD = pic30-ld.exe
AR = pic30-ar.exe
HX = pic30-bin2hex.exe
RM = rm

ups.hex : ups.cof
	$(HX) "ups.cof"

ups.cof : clock.o pwm.o main.o StateMachine.o uart.o i2c.o data_struct.o
	$(CC) -mcpu=33FJ16GS504 "clock.o" "pwm.o" "main.o" "StateMachine.o" "uart.o" "i2c.o" "data_struct.o" "C:\Program Files\Microchip\MPLAB C30\lib\libq-coff.a" -o"ups.cof" -Wl,-Tp33FJ16GS504.gld,--defsym=__MPLAB_BUILD=1,-Map="ups.map",--report-mem

clock.o : c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h clock.c
	$(CC) -mcpu=33FJ16GS504 -x c -c "clock.c" -o"clock.o" -g -Wall

pwm.o : c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h data_struct.h define.h sineTable_50Hz.h c:/program\ files/microchip/mplab\ c30/include/math.h c:/program\ files/microchip/mplab\ c30/include/stddef.h c:/program\ files/microchip/mplab\ c30/include/stdlib.h c:/program\ files/microchip/mplab\ c30/support/generic/h/dsp.h c:/program\ files/microchip/mplab\ c30/support/generic/h/libq.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h pwm.c
	$(CC) -mcpu=33FJ16GS504 -x c -c "pwm.c" -o"pwm.o" -g -Wall

main.o : i2c.h StateMachine.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h data_struct.h define.h clock.h uart.h pwm.h c:/program\ files/microchip/mplab\ c30/include/math.h c:/program\ files/microchip/mplab\ c30/include/stddef.h c:/program\ files/microchip/mplab\ c30/include/stdlib.h dsp.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h main.c
	$(CC) -mcpu=33FJ16GS504 -x c -c "main.c" -o"main.o" -g -Wall

StateMachine.o : uart.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h data_struct.h define.h c:/program\ files/microchip/mplab\ c30/include/math.h c:/program\ files/microchip/mplab\ c30/include/stddef.h c:/program\ files/microchip/mplab\ c30/include/stdlib.h c:/program\ files/microchip/mplab\ c30/support/generic/h/dsp.h c:/program\ files/microchip/mplab\ c30/support/generic/h/libq.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h StateMachine.c
	$(CC) -mcpu=33FJ16GS504 -x c -c "StateMachine.c" -o"StateMachine.o" -g -Wall

uart.o : i2c.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h data_struct.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h data_struct.h define.h c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h uart.c
	$(CC) -mcpu=33FJ16GS504 -x c -c "uart.c" -o"uart.o" -g -Wall

i2c.o : i2c.h p33fj16gs504.h i2c.c
	$(CC) -mcpu=33FJ16GS504 -x c -c "i2c.c" -o"i2c.o" -g -Wall

data_struct.o : c:/program\ files/microchip/mplab\ c30/support/dsPIC33F/h/p33fj16gs504.h data_struct.h data_struct.c
	$(CC) -mcpu=33FJ16GS504 -x c -c "data_struct.c" -o"data_struct.o" -g -Wall

clean : 
	$(RM) "clock.o" "pwm.o" "main.o" "StateMachine.o" "uart.o" "i2c.o" "data_struct.o" "ups.cof"

