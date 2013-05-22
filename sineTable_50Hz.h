/*******************************************************************************
* ?2005 Microchip Technology Inc.
*
* SOFTWARE LICENSE AGREEMENT:
* Microchip Technology Incorporated ("Microchip") retains all ownership and 
* intellectual property rights in the code accompanying this message and in all 
* derivatives hereto.  You may use this code, and any derivatives created by 
* any person or entity by or on your behalf, exclusively with Microchip's
* proprietary products.  Your acceptance and/or use of this code constitutes 
* agreement to the terms and conditions of this notice.
*
* CODE ACCOMPANYING THIS MESSAGE IS SUPPLIED BY MICROCHIP "AS IS".  NO 
* WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED 
* TO, IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY AND FITNESS FOR A 
* PARTICULAR PURPOSE APPLY TO THIS CODE, ITS INTERACTION WITH MICROCHIP'S 
* PRODUCTS, COMBINATION WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
*
* YOU ACKNOWLEDGE AND AGREE THAT, IN NO EVENT, SHALL MICROCHIP BE LIABLE,  
* WHETHER IN CONTRACT, WARRANTY, TORT (INCLUDING NEGLIGENCE OR BREACH OF 
* STATUTORY DUTY), STRICT LIABILITY, INDEMNITY, CONTRIBUTION, OR OTHERWISE, FOR 
* ANY INDIRECT, SPECIAL, PUNITIVE, EXEMPLARY, INCIDENTAL OR CONSEQUENTIAL LOSS, 
* DAMAGE, FOR COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE CODE, 
* HOWSOEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE
* DAMAGES ARE FORESEEABLE. TO THE FULLEST EXTENT ALLOWABLE BY LAW, MICROCHIP'S 
* TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY RELATED TO THIS CODE, SHALL NOT 
* EXCEED THE PRICE YOU PAID DIRECTLY TO MICROCHIP SPECIFICALLY TO HAVE THIS 
* CODE DEVELOPED.
*
* You agree that you are solely responsible for testing the code and 
* determining its suitability.  Microchip has no obligation to modify, test, 
* certify, or support the code.
*
*
*******************************************************************************/

#ifndef _SineTable_50Hz_h
#define _SineTable_50Hz_h

#define SINE_TABLE_SIZE 512

static int SineTable_50Hz[SINE_TABLE_SIZE/4+1] = 
{
0,
201,
402,
603,
803,
1004,
1205,
1405,
1605,
1805,
2005,
2204,
2404,
2602,
2801,
2998,
3196,
3393,
3589,
3785,
3980,
4175,
4369,
4563,
4756,
4948,
5139,
5329,
5519,
5708,
5896,
6083,
6269,
6455,
6639,
6822,
7005,
7186,
7366,
7545,
7723,
7900,
8075,
8249,
8423,
8594,
8765,
8934,
9102,
9268,
9434,
9597,
9759,
9920,
10079,
10237,
10393,
10548,
10701,
10853,
11002,
11150,
11297,
11442,
11585,
11726,
11866,
12003,
12139,
12273,
12406,
12536,
12665,
12791,
12916,
13038,
13159,
13278,
13395,
13510,
13622,
13733,
13842,
13948,
14053,
14155,
14255,
14353,
14449,
14543,
14634,
14723,
14810,
14895,
14978,
15058,
15136,
15212,
15286,
15357,
15426,
15492,
15557,
15618,
15678,
15735,
15790,
15842,
15892,
15940,
15985,
16028,
16069,
16107,
16142,
16175,
16206,
16234,
16260,
16284,
16305,
16323,
16339,
16353,
16364,
16372,
16379,
16382,
16384
};


#define ST SineTable_50Hz
#define ST_SIZE SINE_TABLE_SIZE
#ifdef TEST
#define SIN(idx) (((idx) < ST_SIZE/4)?(ST[(idx)]):(((idx) < ST_SIZE/2)?(ST[ST_SIZE/2 - (idx)]):(((idx) < ST_SIZE * 3 / 4)?(-ST[(idx) - ST_SIZE/2]):(-ST[ST_SIZE - (idx)]))))
#else
#define SIN(idx) (((idx) < ST_SIZE/4)?(ST[(idx)]):(((idx) < ST_SIZE/2)?(ST[ST_SIZE/2 - (idx)]):(((idx) < ST_SIZE * 3 / 4)?(ST[(idx) - ST_SIZE/2]):(ST[ST_SIZE - (idx)]))))
#endif
#endif

