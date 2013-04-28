//========================================================================
// �ļ���:  LCD_Dis.c
// ��  ��: xinqiang Zhang  (email: xinqiang@Mzdesign.com.cn)
// ��  ��: 2009/02/10
// ��  ��: MzLH04-12864 LCD��ʾģ������V1.0��
//			�������ܽӿں�����
//
// ��  ��: ��
// ��  ��:
//      2009/02/10      First version    Mz Design
//========================================================================

#include "LCD_Config.h"

unsigned char X_Witch=6;
unsigned char Y_Witch=10;
unsigned char X_Witch_cn=16;
unsigned char Y_Witch_cn=16;
unsigned char Dis_Zero=0;
//========================================================================
// ����: void LCD_Init(void)
// ����: LCD��ʼ��������Ҫ��������ɶ˿ڳ�ʼ���Լ�LCDģ��ĸ�λ
// ����: �� 
// ����: ��
// ��ע:
// �汾:
//      2009/02/10      First version    Mz Design
//========================================================================
void TimeDelay(unsigned int Timers)
{
	unsigned int i;
	while(Timers)
	{
		Timers--;
		for(i=0;i<800;i++) ;
	}
}


void Key_Init()
{
	KEY_Pin_Init;
}

unsigned char GetKey()
{
	unsigned char kValue = 0;
	static unsigned char esc=0,enter=0,up=0,down=0;
	static unsigned long kCnt = 0;
	
	if (KEY_ESC)
	{
		//TimeDelay(1);
		kCnt ++;
		esc = 1;
	}
	if (KEY_ENTER)
	{
		//TimeDelay(1);
		kCnt ++;
		enter = 1;
	}
	if (KEY_UP)
	{
		//TimeDelay(1);
		kCnt ++;
		up = 1;
	}
	if (KEY_DOWN)
	{
		//TimeDelay(1);
		kCnt ++;
		down = 1;
	}
	if ((kCnt>=200) && ((esc && !KEY_ESC) || (enter && !KEY_ENTER) || (up && !KEY_UP) || (down && !KEY_DOWN)))
	{
		kValue = esc * 8 + up * 4 + down * 2 + enter;
		esc = 0; enter = 0; up = 0; down = 0;
		kCnt = 0;
	}
	if (!KEY_ESC && !KEY_ENTER && !KEY_UP && !KEY_DOWN && kCnt>0 && kCnt<200) kCnt = 0;
	
	if (kCnt>=100000)
	{
		kCnt = 90000;
		if ((up && KEY_UP) || (down && KEY_DOWN))
		{
			kValue = esc * 8 + up * 4 + down * 2 + enter;
		}
	}	
	return kValue;		
}

void LCD_Init(void)
{
	//SS��SCKԤ������Ϊ�ߵ�ƽ
	LCD_Pin_Init;

	SPI_SCK = 1;
	SPI_CS = 1;
	
	//��λLCDģ��
	SPI_RES = 0;
	TimeDelay(50);			
	//���ֵ͵�ƽ���2ms����
	SPI_RES = 1;
	TimeDelay(80);				    	//��ʱ���10ms����
}
//========================================================================
// ����: void SPI_SSSet(unsigned char Status)
// ����: ��SS��״̬
// ����: Status   =1���øߵ�ƽ��=0���õ͵�ƽ  
// ����: ��
// �汾:
//      2009/02/10      First version    Mz Design
//========================================================================
void SPI_SSSet(unsigned char Status)
{
	if(Status)				//�ж���Ҫ��SSΪ�ͻ��Ǹߵ�ƽ��//SS�øߵ�ƽ
		SPI_CS = 1;
	else   //SS�õ͵�ƽ
		SPI_CS = 0;
}
//========================================================================
// ����: void SPI_Send(unsigned char Data)
// ����: ͨ������SPI������һ��byte��������ģ��
// ����: Data Ҫ���͵����� 
// ����: ��
// �汾:
//      2007/07/17      First version
//		2007/07/24		V1.2 for MCS51 Keil C
//========================================================================
void SPI_Send(unsigned char Data)
{
	unsigned char i=0;
	for(i=0;i<8;i++)
	{
		//SCK�õ�
		SPI_SCK = 0;
		if(Data&0x0080)
			SPI_SDA = 1;			
		else SPI_SDA = 0;//
		//SCK�����ش����������ݲ���
		SPI_SCK = 1;
		Data = Data<<1;							//��������һλ
	}
}
//========================================================================
// ����: void FontSet(unsigned char Font_NUM,unsigned char Color)
// ����: ASCII�ַ���������
// ����: Font_NUM ����ѡ��,�������������ֿ�Ϊ׼
//		 Color  �ı���ɫ,��������ASCII�ֿ�  
// ����: ��
// ��ע: 
// �汾:
//      2007/07/19      First version
//========================================================================
void FontSet(unsigned char Font_NUM,unsigned char Color)
{
	unsigned char ucTemp=0;
	if(Font_NUM==0)
	{
		X_Witch = 6;//7;
		Y_Witch = 10;
	}
	else
	{
		X_Witch = 8;
		Y_Witch = 16;
	}
	ucTemp = (Font_NUM<<4)|Color;
	//����ASCII�ַ�������
	SPI_SSSet(0);					//SS�õ͵�ƽ			
	SPI_Send(0x81);					//����ָ��0x81
	SPI_Send(ucTemp);				//ѡ��8X16��ASCII����,�ַ�ɫΪ��ɫ
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ	
}
//========================================================================
// ����: void FontMode(unsigned char Cover,unsigned char Color)
// ����: �����ַ���ʾ����ģʽ
// ����: Cover  �ַ�����ģʽ���ã�0��1
//		 Color ����ģʽΪ1ʱ�ַ���ʾʱ�ı�������ɫ 
// ����: ��
// ��ע: 
// �汾:
//      2008/11/27      First version
//========================================================================
void FontMode(unsigned char Cover,unsigned char Color)
{
	unsigned char ucTemp=0;
	ucTemp = (Cover<<4)|Color;
	//����ASCII�ַ�������
	SPI_SSSet(0);					//SS�õ͵�ƽ			
	SPI_Send(0x89);					//����ָ��0x81
	SPI_Send(ucTemp);				//ѡ��8X16��ASCII����,�ַ�ɫΪ��ɫ
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ	
}
//========================================================================
// ����: void FontSet_cn(unsigned char Font_NUM,unsigned char Color)
// ����: ���ֿ��ַ���������
// ����: Font_NUM ����ѡ��,�������������ֿ�Ϊ׼
//		 Color  �ı���ɫ,�������ں��ֿ�  
// ����: ��
// ��ע: 
// �汾:
//      2007/07/19      First version
//========================================================================
void FontSet_cn(unsigned char Font_NUM,unsigned char Color)
{
	unsigned char ucTemp=0;
	if(Font_NUM==0)
	{
		X_Witch_cn = 12;
		Y_Witch_cn = 12;
	}
	else
	{
		X_Witch_cn = 16;
		Y_Witch_cn = 16;
	}
	ucTemp = (Font_NUM<<4)|Color;
	//����ASCII�ַ�������
	SPI_SSSet(0);					//SS�õ͵�ƽ			
	SPI_Send(0x82);					//����ָ��0x81
	SPI_Send(ucTemp);				//ѡ��8X16��ASCII����,�ַ�ɫΪ��ɫ
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ	
}
//========================================================================
// ����: void PutChar(unsigned char x,unsigned char y,unsigned char a) 
// ����: д��һ����׼ASCII�ַ�
// ����: x  X������     y  Y������
//		 a  Ҫ��ʾ���ַ����ֿ��е�ƫ����  
// ����: ��
// ��ע: ASCII�ַ���ֱ������ASCII�뼴��
// �汾:
//      2007/07/19      First version
//========================================================================
void PutChar(unsigned char x,unsigned char y,unsigned char a) 
{
	//��ʾASCII�ַ�
	SPI_SSSet(0);					//SS�õ͵�ƽ	
	SPI_Send(7);					//����ָ��0x07
	SPI_Send(x);					//Ҫ��ʾ�ַ������Ͻǵ�X��λ��
	SPI_Send(y);					//Ҫ��ʾ�ַ������Ͻǵ�Y��λ��
	SPI_Send(a);					//Ҫ��ʾ�ַ�ASCII�ַ���ASCII��ֵ
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ
}
//========================================================================
// ����: void PutString(int x,int y,char *p)
// ����: ��x��yΪ��ʼ���괦д��һ����׼ASCII�ַ�
// ����: x  X������     y  Y������
//		 p  Ҫ��ʾ���ַ���  
// ����: ��
// ��ע: ���������Դ���ASCII�ַ�����ʾ
// �汾:
//      2007/07/19      First version
//========================================================================
void PutString(unsigned char x,unsigned char y,char *str)
{
	unsigned char * p = (unsigned char *)str;
	while(*p!=0)
	{
		PutChar(x,y,*p);
		x += X_Witch;
		if((x + X_Witch) > Dis_X_MAX)
		{
			x = Dis_Zero;
			if((Dis_Y_MAX - y) < Y_Witch) break;
			else y += Y_Witch;
		}
		p++;
	}
}
//========================================================================
// ����: void PutChar_cn(unsigned char x,unsigned char y,unsigned short * GB) 
// ����: д��һ���������ֿ⺺��
// ����: x  X������     y  Y������
//		 a  GB��  
// ����: ��
// ��ע: 
// �汾:
//      2007/07/19      First version
//		2007/07/24		V1.2 for MCS51 Keil C
//========================================================================
void PutChar_cn(unsigned char x,unsigned char y,unsigned char * GB) 
{
	//��ʾASCII�ַ�
	SPI_SSSet(0);					//SS�õ͵�ƽ	
	SPI_Send(8);					//����ָ��0x08
	SPI_Send(x);					//Ҫ��ʾ�ַ������Ͻǵ�X��λ��
	SPI_Send(y);					//Ҫ��ʾ�ַ������Ͻǵ�Y��λ��
	
	SPI_Send(*(GB++));	//���Ͷ����ֿ��к���GB��ĸ߰�λֵ
	SPI_Send(*GB);		//���Ͷ����ֿ��к���GB��ĵͰ�λֵ
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ
}
//========================================================================
// ����: void PutString_cn(unsigned char x,unsigned char y,unsigned short *p)
// ����: ��x��yΪ��ʼ���괦д��һ�������ַ�
// ����: x  X������     y  Y������
//		 p  Ҫ��ʾ���ַ���  
// ����: ��
// ��ע: ͬPutChar_cn�еĽ���
// �汾:
//      2007/07/19      First version
//		2007/07/24		V1.2 for MCS51 Keil C
//========================================================================
void PutString_cn(unsigned char x,unsigned char y,char *str)
{
	unsigned char *p = (unsigned char*)str;
	while(*p!=0)
	{
		if(*p<128)
		{
			PutChar(x,y,*p);
			x += X_Witch+1;
			if((x/* + X_Witch*/) > Dis_X_MAX)
			{
				x = Dis_Zero;
				if((Dis_Y_MAX - y) < Y_Witch) break;
				else y += Y_Witch_cn;
			}
			p+=1;
		}
		else
		{
			PutChar_cn(x,y,p);
			x += X_Witch_cn+1;
			if((x/* + X_Witch_cn*/) > Dis_X_MAX)
			{
				x = Dis_Zero;
				if((Dis_Y_MAX - y) < Y_Witch_cn) break;
				else y += Y_Witch_cn;
			}
			p+=2;
		}
	}
}
//========================================================================
// ����: void SetPaintMode(unsigned char Mode,unsigned char Color)
// ����: ��ͼģʽ����
// ����: Mode ��ͼģʽ    Color  ���ص����ɫ,�൱��ǰ��ɫ  
// ����: ��
// ��ע: Mode��Ч
// �汾:
//      2007/07/19      First version
//========================================================================
void SetPaintMode(unsigned char Mode,unsigned char Color)
{
	unsigned char ucTemp=0;
	ucTemp = (Mode<<4)|Color;
	//���û�ͼģʽ
	SPI_SSSet(0);					//SS�õ͵�ƽ			
	SPI_Send(0x83);					//����ָ��0x83
	SPI_Send(ucTemp);				//ѡ��8X16��ASCII����,�ַ�ɫΪ��ɫ
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ
}
//========================================================================
// ����: void PutPixel(unsigned char x,unsigned char y)
// ����: ��x��y���ϻ���һ��ǰ��ɫ�ĵ�
// ����: x  X������     y  Y������
// ����: ��
// ��ע: ʹ��ǰ��ɫ
// �汾:
//      2007/07/19      First version
//========================================================================
void PutPixel(unsigned char x,unsigned char y)
{
	//������	
	SPI_SSSet(0);					//SS�õ͵�ƽ
	SPI_Send(1);					//��ָ��0x01
	SPI_Send(x);					//�͵�һ������,�����õ��X��λ��
	SPI_Send(y);					//���Y��λ��
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ
}
//========================================================================
// ����: void Line(unsigned char s_x,unsigned char  s_y,
//					unsigned char  e_x,unsigned char  e_y)
// ����: ��s_x��s_yΪ��ʼ���꣬e_x��e_yΪ�����������һ��ֱ��
// ����: x  X������     y  Y������
// ����: ��
// ��ע: ʹ��ǰ��ɫ
// �汾:
//      2007/07/19      First version
//========================================================================
void Line(unsigned char s_x,unsigned char  s_y,unsigned char  e_x,unsigned char  e_y)
{  
	//����ֱ��
	SPI_SSSet(0);					//SS�õ͵�ƽ
	SPI_Send(2);					//��ָ��0x02
	SPI_Send(s_x);					//���X������
	SPI_Send(s_y);					//���Y������
	SPI_Send(e_x);					//�յ�X������
	SPI_Send(e_y);					//�յ�Y������
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ
}
//========================================================================
// ����: void Circle(unsigned char x,unsigned char y,
//					unsigned char r,unsigned char mode)
// ����: ��x,yΪԲ��RΪ�뾶��һ��Բ(mode = 0) or Բ��(mode = 1)
// ����: 
// ����: ��
// ��ע: ��Բ����ִ�н��������MCU�п��Ź����������幷�Ĳ���
// �汾:
//      2007/07/19      First version
//========================================================================
void Circle(unsigned char x,unsigned char y,unsigned char r,unsigned char mode)
{
	SPI_SSSet(0);
	if(mode)
		SPI_Send(6);
	else
		SPI_Send(5);
	SPI_Send(x);
	SPI_Send(y);
	SPI_Send(r);
	SPI_SSSet(1);
}
//========================================================================
// ����: void Rectangle(unsigned char left, unsigned char top, unsigned char right,
//				 unsigned char bottom, unsigned char mode)
// ����: ��x,yΪԲ��RΪ�뾶��һ��Բ(mode = 0) or Բ��(mode = 1)
// ����: left - ���ε����ϽǺ����꣬��Χ0��126
//		 top - ���ε����Ͻ������꣬��Χ0��62
//		 right - ���ε����½Ǻ����꣬��Χ1��127
//		 bottom - ���ε����½������꣬��Χ1��63
//		 Mode - ����ģʽ��������������ֵ֮һ��
//				0:	���ο򣨿��ľ��Σ�
//				1:	�����棨ʵ�ľ��Σ�
// ����: ��
// ��ע: ��Բ����ִ�н��������MCU�п��Ź����������幷�Ĳ���
// �汾:
//      2007/07/19      First version
//========================================================================
void Rectangle(unsigned char left, unsigned char top, unsigned char right,
				 unsigned char bottom, unsigned char mode)
{
	SPI_SSSet(0);
	if(mode)
		SPI_Send(4);
	else
		SPI_Send(3);
	SPI_Send(left);
	SPI_Send(top);
	SPI_Send(right);
	SPI_Send(bottom);
	SPI_SSSet(1);
}
//========================================================================
// ����: void ClrScreen(void)
// ����: ����������ִ��ȫ��Ļ���
// ����: 
// ����: ��
// ��ע: 
// �汾:
//      2007/07/19      First version
//========================================================================
void ClrScreen(void)
{
	//��������
	SPI_SSSet(0);					//SS�õ͵�ƽ
	SPI_Send(0x80);					//��ָ��0x80
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ
}
//========================================================================
// ����: void PutBitmap(unsigned char x,unsigned char y,unsigned char width,
//						unsigned char high,unsigned char *p)
// ����: ��x��yΪ��ʼ������ʾһ����ɫλͼ
// ����: x  X������     y  Y������
//		 width λͼ�Ŀ��  
//		 high  λͼ�ĸ߶�
//		 p  Ҫ��ʾ��λͼ����ģ�׵�ַ  
// ����: ��
// ��ע: ��
// �汾:
//      2008/11/27      First version
//========================================================================
void PutBitmap(unsigned char x,unsigned char y,unsigned char width,unsigned char high,unsigned char *p)
{
	unsigned short Dat_Num;
	//unsigned short i;
	unsigned char ucTemp=0;
	SPI_SSSet(0);					//SS�õ͵�ƽ
	SPI_Send(0x0e);	
	SPI_Send(x);
	SPI_Send(y);
	SPI_Send(width);
	SPI_Send(high);
	
	width = width+0x07;
	Dat_Num = (width>>3)*high;
	while(Dat_Num--)
	{
	  	ucTemp++;
		SPI_Send(*p);
		if(ucTemp>250)				//����Ļ����MCUʱ,���������Ҫ�ʵ��ĵ���
		{
			TimeDelay(28);			//�Լ��˴�,�Ա�֤ǰ�洫�͵�LCDģ���е������ѱ�������
			ucTemp = 0;
		}
		p++;
	}
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ
}

//========================================================================
// ����: void ShowChar(unsigned char x,unsigned char y,unsigned char Num,unsigned char type)
// ����: ��x��y��λ��Ϊ��ʾ��������Ͻǣ���ʾһ��unsigned char����
// ����: x  X������     y  Y������    Num  Ҫ��ʾ��8λ��ȵ�����  type  ��ʾ����(0,1,2)
// ����: ��
// ��ע: 
// �汾:
//      2008/11/27      First version
//========================================================================
void ShowChar(unsigned char x,unsigned char y,unsigned char a,unsigned char type) 
{
	//��ʾASCII�ַ�
	SPI_SSSet(0);					//SS�õ͵�ƽ	
	SPI_Send(11);					//����ָ��0x0B
	SPI_Send(x);					//Ҫ��ʾ�ַ������Ͻǵ�X��λ��
	SPI_Send(y);					//Ҫ��ʾ�ַ������Ͻǵ�Y��λ��
	SPI_Send(a);					//Ҫ��ʾ������
	SPI_Send(type);
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ
}
//========================================================================
// ����: void ShowShort(unsigned char x,unsigned char y,unsigned short Num,unsigned char type)
// ����: ��x��y��λ��Ϊ��ʾ��������Ͻǣ���ʾһ��unsigned short������16λ��ȣ�
// ����: x  X������     y  Y������    Num  Ҫ��ʾ��16λ��ȵ�����  type  ��ʾ����(0,1,2)
// ����: ��
// ��ע: 
// �汾:
//      2008/11/27      First version
//========================================================================
void ShowShort(unsigned char x,unsigned char y,unsigned short a,unsigned char type) 
{
	//��ʾASCII�ַ�
	SPI_SSSet(0);					//SS�õ͵�ƽ	
	SPI_Send(12);					//����ָ��0x0C
	SPI_Send(x);					//Ҫ��ʾ�ַ������Ͻǵ�X��λ��
	SPI_Send(y);					//Ҫ��ʾ�ַ������Ͻǵ�Y��λ��
	SPI_Send((unsigned char)(a>>8));
	SPI_Send((unsigned char)a);
	SPI_Send(type);					//Ҫ��ʾ�ַ�ASCII�ַ���ASCII��ֵ
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ
}
//========================================================================
// ����: void SetBackLight(unsigned char Deg)
// ����: ���ñ������ȵȼ�
// ����: Grade  0~127�ĵȼ�
// ����: ��
// ��ע: 
// �汾:
//      2008/11/27      First version
//========================================================================
void SetBackLight(unsigned char Deg) 
{
	//��ʾASCII�ַ�
	SPI_SSSet(0);					//SS�õ͵�ƽ	
	SPI_Send(0x8a);					//����ָ��0x07
	SPI_Send(Deg);					//Ҫ��ʾ�ַ������Ͻǵ�X��λ��
	SPI_SSSet(1);					//��ɲ�����SS�ߵ�ƽ
}

//unsigned char X_Witch=6;
//unsigned char Y_Witch=10;
//unsigned char X_Witch_cn=16;
//unsigned char Y_Witch_cn=16;

void Print(unsigned char cn,unsigned char FontSize,unsigned char Color,unsigned char Line,unsigned char Column,char* Str)
{
	if(cn)
	{
		FontSet_cn(FontSize,Color);
	}
	else
	{
		FontSet(FontSize,Color);
	}

	if (Line<64 || Column<128)
	{
		if(cn)
		{
			PutString_cn(Column,Line,Str);
		}
		else
		{
			PutString(Column,Line,Str);
		}
	}	
}

unsigned char cStrLen(char * str)
{
	char* p = str;
	while(*p++);
	return ((p-str))/2;
}

unsigned char StrLen(char * str)
{
	char* p = str;
	while(*p++);
	return p-str-1;
}

void cPrint12(unsigned char cfs,unsigned char efs,unsigned char Line,unsigned Column, char * str,unsigned char i)
{
	FontMode(1,0);
	FontSet(efs,1);
	FontSet_cn(cfs,1);

	if (i)
	{
		FontSet(efs,0);
		FontSet_cn(cfs,0);
		FontMode(0,1);
		Rectangle(Column-1,Line-1,Column+13*cStrLen(str)-1,Line+13-1,1);
	}
	PutString_cn(Column,Line,str);
}

void Print6(unsigned char fs,unsigned char Line,unsigned Column, char * str,unsigned char i)
{
	FontSet(fs,1);

	if (i)
	{
		FontSet(fs,0);
		FontMode(0,1);
		Rectangle(Column-1,Line-1,Column+6*StrLen(str)-1,Line+9,1);
	}
	PutString(Column,Line,str);
}

