#include <reg52.h>
#include "sysParameter.h"
#include "../delay/timeDebug.h"
#include "../nixie_tube/show.h"
#include "../keboard/independent.h"
#include "../keboard/matrix.h"

uint T0Flag = 0;

void interruptInit()
{
    TMOD = 0x01;                  // 设置定时器0位工作方式1
    TH0 = (65536 - 45872) / 256;  // 设置定时器初始值
    TL0 = (65536 - 45872) % 256;  
    EA = 1;                       // 开启总中断  
    ET0 = 1;                      // 开启定时器0中断
    TR0 = 0;                      // 等待启动定时器0
}

void main()
{
    uint showNum = 1;  // 初始化显示数字
    // show2Bit(showNum);   // 在数码管显示数字
    interruptInit();   // 初始化中断
    while(1)
    {    
        // show2Bit(showNum);   // 在数码管显示数字
        // showNum = keyFunc(showNum, &T0Flag);   // 等待独立按键程序       
        // if (T0Flag >= 40)
        // {
        //     T0Flag = 0;
        //     showNum++;
        // }
        showNum = keyboardScan(showNum);
    }   
}

 /**
  * 功能：
  * 参数：
  * 返回值：
  */
void T0_time() interrupt 1
{
    T0Flag ++;
    TH0 = (65536 - 45872) / 256;  // 设置定时器初始值
    TL0 = (65536 - 45872) % 256;
     
}