#include <reg52.h>
#include "../main/sysParameter.h"
#include "../delay/timeDebug.h" 

void beepWork()
{
    uint j;
    for(j=500;j>0;j--)  //���������Լ500MS
    {
        BEEP = ~BEEP;
        Delayst(2);	    //��ʱ500US	  ������Լ1KHZƵ�ʵ����� 
    }
}