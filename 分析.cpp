
#define Detect_ZeroCross() ((pmv<0 && mv>=0) && (mv - pmv > 100))

void Interrupt4Mains()
{
	switch(ms)
	{
		case NOT_OK:

			if (mv>5000)
			{
				mscnt++;
				if (mscnt>20)
				{
					ms = HV_D;
					mscnt = 0;
				}
			}
			break;

		case HV_D:
			
			if (pmv<0 && mv>=0)
			{
				if (mv - pmv>100)
				{
					ms = ZC_D;
					mscnt = 0
				}
			}
			break;

		case ZC_D:

			mscnt ++;
			if (mscnt<arraySize)
			{
				array[mscnt] = mv;
				if (ZCD()==1)
				{
				}
			}

