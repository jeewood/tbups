#include <p33fj16gs504.h> 
#include "LCD_Driver\LCD_Dis.h"

#include "menu.h"
#include "define.h"

char* MenuProc(unsigned char mID);

#define NULL 0

cValue Value;

//初始化液晶屏
void Init_LCD(void)
{
	LCD_Init();
	SetBackLight(100);				//设置背光的亮度等级为100
}

void Welcome() //Welcome
{
	ClrScreen();

	FontMode(0,0);
	FontSet(0,1);
	cPrint12(1,0,1,24,"电力专用UPS",0);
	cPrint12(0,0,24,0,"上海统部电器有限公司",0);
	FontMode(1,0);
	FontSet(1,1);
	PutString(18,46,"TBU10KVA220V");

}

typedef struct _cMenuItem
{
	unsigned char bid;
	unsigned char eid;
	char * ItemStr;
	unsigned char isSet;
}cMenuItem;

const 
cMenuItem MS[] = 
{
	{0,3,"系统设置"   ,1},	//0
	{0,3,"工作模式：" ,1},	//1
	{0,3,"启动方式：" ,1},	//2
	{0,3,"背光状态：" ,1},	//3

	{4,8,"通讯设置"   ,1},	//4
	{4,8,"波 特 率：" ,1},	//5
	{4,8,"数 据 位：" ,1},	//6
	{4,8,"停 止 位：" ,1},	//7
	{4,8,"奇偶校验：" ,1},	//8
		
	{9,15,"系统信息"  ,0},	//9
	{9,15,"输入电压：",0},	//10
	{9,15,"逆变电压：",0},	//11
	{9,15,"负载电流：",0},	//12

	{9,15,"输入频率：",0},	//13
	{9,15,"逆变频率：",0},	//14
	{9,15,"负 载 率：",0},	//15

	{16,19,"电池信息"  ,0},//16
	{16,19,"电池电压：",0},//17
	{16,19,"充电电流：",0},//18
	{16,19,"充电状态：",0}	//19
};

#define MSTR_TITLE(mid) (MS[MS[mid].bid].ItemStr)
#define MSTR_FID(cid) (((cid - MS[cid].bid - 1) / 3) * 3 + MS[cid].bid)
#define MSTR_LID(cid) (((cid - MS[cid].bid - 1) / 3) * 3 + MS[cid].bid + 2)

#define MSTR(cid) (MS[cid].ItemStr)

unsigned char MenuItemCount()
{
	return sizeof(MS)/sizeof(cMenuItem) - 1;
}

unsigned char GetTitleID(unsigned char mID)
{
	return MS[mID].bid;
}

unsigned char isSet(unsigned char mID)
{
	return (MS[MSTR_FID(mID)].isSet)?4:(4 - (mID - MSTR_FID(mID)));
}

void Menu(unsigned char mID) //设置1
{
	ClrScreen();
	if (!mID)
	{
    	    Welcome();
    	    return ;
     }   	
	cPrint12(1,1,0,30,MSTR_TITLE(mID),0);
	if (MSTR_FID(mID)+1 <= MS[mID].eid) 
	{
		cPrint12(0,0,18,0,MSTR(MSTR_FID(mID)+1),0);
		cPrint12(0,0,18,64,MenuProc(MSTR_FID(mID)+1),(MSTR_FID(mID)+1==mID && isSet(mID)==4)?1:0);
	}	
	if (MSTR_FID(mID)+2 <= MS[mID].eid) 
	{
		cPrint12(0,0,34,0,MSTR(MSTR_FID(mID)+2),0);
		cPrint12(0,0,34,64,MenuProc(MSTR_FID(mID)+2),(MSTR_FID(mID)+2==mID && isSet(mID)==4)?1:0);
	}
	if (MSTR_FID(mID)+3 <= MS[mID].eid) 
	{
		cPrint12(0,0,50,0,MSTR(MSTR_FID(mID)+3),0);
		cPrint12(0,0,50,64,MenuProc(MSTR_FID(mID)+3),(MSTR_FID(mID)+3==mID && isSet(mID)==4)?1:0);
	}		
	MenuProc(mID);
}

/*
unsigned char InvMode = 0;
unsigned char StartMode = 0;
unsigned char BKLtime = 0;
unsigned int BandRate = 1;
unsigned char DataBit = 8;
unsigned char StopBit = 1;
unsigned char OddEven = 0;
unsigned int ACinV = 2200;
unsigned int InvV = 2200;
unsigned char ACinF = 49;
unsigned char InvF = 49;
unsigned int LoadI = 10;
unsigned int LoadRate = 50;
*/
char *InvModeProc()
{
	return (inv.synced)?"在线":"离线";
}

char *StartModeProc()
{
	return (Value.Mode.l)?"手动":"自动";
}

char *BKLtimeProc()
{
	return (Value.Status.h)?"长":"短";
}

char *BandRateProc()
{
	switch(Value.ComSet[0].h)
	{
		case 0: return "19200";
		case 2: return "4800";
		case 3: return "2400";
		case 4: return "1200";
		default: return "9600";
	}
}

char *DataBitProc()
{
	return (Value.ComSet[0].l)?"7":"8";
}

char *StopBitProc()
{
	return (Value.ComSet[1].h)?"2":"1";
}

char *OddEvenProc()
{
	if (Value.ComSet[1].l==0) 
		return "无";
	else if (Value.ComSet[1].l==1)
		return "奇";
	else
		return "偶";
}

char *i2s(unsigned int v)
{
	static char vs[7] = "000000";
	char sign = 0;
	unsigned char i = 1;
	if (v>32767) 
	{
		sign = 1;
		v = (~v) + 1;
	}
	vs[i++] = (v/10000) + '0';
	v = v % 10000;
	vs[i++] = (v/1000) + '0';
	v = v % 1000;
	vs[i++] = (v/100) + '0';
	v = v % 100;
	vs[i++] = (v/10) + '0';
	v = v % 10;
	vs[i++] = v + '0';
	vs[i++] = '\0';
	for(i=0;i<5;i++)
	{
		if (vs[i+1]!='0') 
		{
			vs[i]=sign?'-':'0';
			return &vs[(sign?i:i+1)];
		}
	}
	return &vs[5];
}

char* MenuProc(unsigned char mID)
{
	switch(mID)
	{
		case 1: 	//工作模式:在线，离线
			return InvModeProc();
		case 2: 	//启动方式:自动，手动
			return StartModeProc();
		case 3: 	//背光状态:长，短
			return BKLtimeProc();
		case 5: 	//波特率:19200,9600,4800,2400,1200
			return BandRateProc();
		case 6: 	//数据位:8,7
			return DataBitProc();
		case 7:  //停止位:1,2
			return StopBitProc();
		case 8: 	//奇偶校验:奇，偶，无
			return OddEvenProc();
		case 10: 	//输入电压
			return i2s(Value.ACInV);
		case 11: 	//逆变电压
			return i2s(Value.InvV);
		case 12:	//负载电流
			return i2s(Value.LoadI);
		case 13:	//输入频率
			return i2s(Value.Freq.h); //ACInF
		case 14:	//输出频率
			return i2s(Value.Freq.l); //InvF
		case 15:	//负载率
			return i2s(Value.LoadRate);
		case 17:	//电池电压
			return i2s(Value.BatV);
		case 18:	//充电电流
			return i2s(Value.BusI);
		case 19:	//充电状态
			return i2s(Value.Adjust);
		default: 	//其他
			return "0";
	}
}

