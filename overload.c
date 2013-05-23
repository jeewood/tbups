
/*
1.继电器状态
2.输出电流
3.120%过载电流
4.150%冲击电流
5.额定电流
6.蜂鸣器
7.*/

#define SWITCH2BYPASS() { SetRelay(MAINPOWER); SetBeep(ON,0,0); }
#define SWITCH2INVERTOR() { SetRelay(INVERTOR); SetBeep(OFF,0,0); }

#define OL150TIME 150000
#define OL150()	{ ol.f = OVERLOAD150; ol.cnt = OL150TIME; SWITCH2BYPASS(); }

#define OL120TIME 300000
#define OL120()	{ ol.f = OVERLOAD120; ol.cnt = OL120TIME; SetBeep(LOOP,5000,5000); }

#define OLNORMAL() { ol.f = OVERLOAD_NORMAL; ol.cnt = 0; SetBeep(OFF,0,0); if (wMode) SetRelay(INVERTOR); else SetRelay(MAINPOWER)}

#define isByPass() (BYPASS==0)

#define OverLoad() \
{\
	switch(ol.f)\
	{\
		case OVERLOAD_NORMAL:\
			if (LoadI>ol.s_curr)	//输出电流大于150%\
			{\
				OL150();\
			}\
			else\
			if (LoadI>ol.ol_curr)\
			{\
				OL120();\
			}\
			if ()\
			break;\
		case OVERLOAD120:\
			if (ol.cnt>1)\
			{\
				if (LoadI>ol.s_curr)\
				{\
					OL150();	\
				}\
				if (LoadI<ol.ol_curr)\
				{\
					OLNORMAL();\
				}\
			}\
			if (ol.cnt == 1)\
			{\
				if (LoadI>ol.ol_curr)\
				{\
					if (!isByPass())\
					{\
						SWITCH2BYPASS();\
					}\
				}\
			}\
			break;\
		case OVERLOAD150:\
			if (ol.cnt)\
			{\
				if (LoadI < RatedCurr)\
				{\
					//Set To Normal\
					OLNORMAL();\
				}\
				if (LoadI>ol.ol_curr && LoadI<ol.s_curr)\
				{\
					OL120();\
				}\
			}\
		break;\
	}\
}


{
switch(ol.f)
            {
	            case OVERLOAD_NORMAL:
	            {
		            if (LoadI>ol.s_curr)
		            {
			            ol.cycle++;
			            if (ol.cycle>5)
			            {
				            ol.f = OVERLOAD150;
				            ol.cnt = 150000;
				            SetBeep(ON,0,0);
				            SetRelay(OFF);
				            ol.cycle = 0;
			            }
		            }
		            else if (LoadI>ol.ol_curr)
		            {
			         	ol.cycle++;
			         	if (ol.cycle>5)
			         	{
				         	ol.f = OVERLOAD120;
				         	ol.cnt = 300000;
				         	SetBeep(LOOP,3000,3000);
				         	SetRelay(ON);
				         	ol.cycle = 0;
			         	}
		            }
		            else
		            {
			            ol.cycle = 0;
		            }
		            break;
	            }
	            case OVERLOAD150:
	            {
		            if (ol.cnt>0)
		            {
			            if (LoadI<RatedCurr)
			            {
				            ol.cycle++;
				            if(ol.cycle>5)
				            {
					            SetRelay(ON);
					            SetBeep(OFF,0,0);
					            ol.cnt = 0;
					        }
			            }
			            else if (LoadI>ol.ol_curr && LoadI<ol.s_curr)
			            {
				         	ol.cycle++;
				         	if (ol.cycle>5)
				         	{
					         	ol.f = OVERLOAD120;
					         	ol.cnt = 300000;
					         	SetBeep(LOOP,3000,3000);
					         	SetRelay(ON);
					         	ol.cycle = 0;
				         	}
			            }
			            else
			            {
				            ol.cycle = 0;
			            }
		            }
		            break;
	            }
	            case OVERLOAD120:
	            {
		            if (ol.cnt>1)
		            {
			            if (LoadI>ol.s_curr)
			            {
				            ol.cycle++;
				            if (ol.cycle>5)
				            {
					            ol.f = OVERLOAD150;
					            ol.cnt = 150000;
					            SetRelay(OFF);
					            SetBeep(ON,0,0);
					        } 
			            }
			            else
			            if (LoadI<ol.ol_curr)
			            {
				            ol.cycle++;
				            if (ol.cycle>5)
				            {
				                ol.f = OVERLOAD_NORMAL;
				                ol.cnt = 0;
				                SetBeep(OFF,0,0);
				                SetRelay(ON);
				                ol.cycle = 0;
				            }
			            }
		            }
		            else if (ol.cnt==1)
		            {
			            if (LoadI>ol.ol_curr)
			            {
				            if (BYPASS)
				            {
			            		SetBeep(ON,0,0);
			            		SetRelay(OFF);
				            }
			            }
			            else if (!BYPASS)
			            {
		            		SetBeep(OFF,0,0);
		            		SetRelay(ON);
			            }
		            }
		            break;
	            }
            }	
}