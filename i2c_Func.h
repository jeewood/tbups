/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
;                                                                     
;                     Software License Agreement                      
;                                                                     
;     ©2007 Microchip Technology Inc
;     Mirochip Technology Inc. ("Microchip") licenses this software to 
;     you solely for the use with Microchip Products. The software is
;     owned by Microchip and is protected under applicable copyright
;     laws. All rights reserved.
;
;     SOFTWARE IS PROVIDED "AS IS." MICROCHIP EXPRESSLY DISCLAIMS ANY
;     WARRANTY OF ANY KIND, WHETHER EXPRESS OR IMPLIED, INCLUDING BUT NOT
;     LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
;     PARTICULAR PURPOSE, OR NON-INFRINGEMENT. IN NO EVENT SHALL MICROCHIP
;     BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL
;     DAMAGES, LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, COST OF
;     PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
;     BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
;     ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR COSTS.
;     
;                                                                
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
;	Filename:			    i2c.h            
;	Date:				    February 21, 2007          
;	File Version:		  	1.0                             
;	Assembled using:		MPLAB IDE 7.51.00.0               
; 	Author:		  	    	Martin Bowman              
;	Company:			    Microchip Technology, Inc.
;~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

//This file contains the function prototypes for the i2c function
#define PAGESIZE	32

//Low Level Functions
unsigned int IdleI2C(void);
unsigned int StartI2C(void);
unsigned int WriteI2C(unsigned char);
unsigned int StopI2C(void);
unsigned int RestartI2C(void);
unsigned int getsI2C(unsigned char*, unsigned char);
unsigned int NotAckI2C(void);
unsigned int InitI2C(void);
unsigned int ACKStatus(void);
unsigned int getI2C(void);
unsigned int AckI2C(void);
unsigned int EEAckPolling(unsigned char);
unsigned int putstringI2C(unsigned char*);

//High Level Functions for Low Density Devices
unsigned int LDByteReadI2C(unsigned char, unsigned char, unsigned char*, unsigned char);
unsigned int LDByteWriteI2C(unsigned char, unsigned char, unsigned char);
unsigned int LDPageWriteI2C(unsigned char, unsigned char, unsigned char*);
unsigned int LDSequentialReadI2C(unsigned char, unsigned char, unsigned char*, unsigned char);

//High Level Functions for High Density Devices
unsigned int HDByteReadI2C(unsigned char, unsigned char, unsigned char, unsigned char*, unsigned char);
unsigned int HDByteWriteI2C(unsigned char, unsigned char, unsigned char, unsigned char);
unsigned int HDPageWriteI2C(unsigned char, unsigned char, unsigned char, unsigned char*);
unsigned int HDSequentialReadI2C(unsigned char, unsigned char, unsigned char, unsigned char*, unsigned char);
