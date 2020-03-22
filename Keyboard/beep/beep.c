#include <reg52.h>
#include "../main/sysParameter.h"
#include "../delay/timeDebug.h" 

void beepWork()
{
    uint j;
    for(j=500;j>0;j--)  //蜂鸣器响大约500MS
    {
        BEEP = ~BEEP;
        Delayst(2);	    //延时500US	  发出大约1KHZ频率的响声 
    }
}