#include "../main/sysParameter.h"
#include "../delay/timeDebug.h"
#include "../beep/beep.h"

uint k8Flag = 0;
 /**
  * 功能：独立按键的端口初始化
  * 参数：
  * 返回值：
  */
void keyboardPortInit()
{
    P1 = 0xff;      // 将P1口全部置为高电平
}
 
 /**
  * 功能：按键检测
  * 参数：
  * 返回值：按下按键的标志
  */
int waitKeyboard()
{
    keyboardPortInit();
    switch ((P1 & 0xff))   // 根据P1口的电平判断按键
    {
    case 0xef:
        delayMS(20);       // 延时防抖
        if(k5 == 0)
        {
            while(!k5);    // 松开按键后启动
            return 5;        
        }
    case 0xdf:
        delayMS(20);
        if(k6 == 0)
        {
            while(!k6);
            return 6;        
        } 
    case 0xbf:
        delayMS(20);
        if(k7 == 0)
        {
            while(!k7);
            return 7;        
        }
    case 0x7f:
        delayMS(20);
        if(k8 == 0)
        {
            while(!k8);
            return 8;        
        }        
    default:
        return 0;
    }
}

/**
  * 功能：根据K8按下的标志位判断是启动定时还是关闭定时
  * 参数：
  * 返回值：
  */
uint k8Func(uint *timeCountP)
{
    if (k8Flag)
    {
        TR0 = 1;                      // 启动定时
    }
    else
    {
        TR0 = 0;
        *timeCountP = 0;              //  定时器停止时，计数表示清零
        TH0 = (65536 - 45872) / 256;  // 设置定时器初始值
        TL0 = (65536 - 45872) % 256;
    }   
}

 /**
  * 功能：根据按键选择执行程序
  * 参数：数码管显示数字
  * 返回值：数码管显示数字
  */
uint keyFunc(uint showNum, uint *timeCountP)
{
    int key = waitKeyboard();
    switch (key)
        {
        case 0:
            break;
        case 5:
            beepWork();
            showNum++;
            break;
        case 6:
            showNum--;
            break;
        case 7:
            showNum = 0;
            break;
        case 8:
            k8Flag = !k8Flag;      // 每按一次标志位转换一次
            k8Func(timeCountP);
            break;       
        default:
            break;
        }
    return showNum;
}

 