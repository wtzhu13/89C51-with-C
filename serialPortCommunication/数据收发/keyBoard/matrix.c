#include "../main/sysParameter.h"
#include "../delay/timeDebug.h"
#include "../nixieTube/show.h"
#include "../beep/beep.h"

/**
  * 功能：矩阵键盘扫描函数
  * 参数：
  * 返回值：
  */
uint keyboardScan(uint showNum)
{
    uint temp, key;
    // 扫描第一行
    P1 = 0xfe;
    temp = P1;
    if ((temp & 0xf0) != 0xf0)
    {
        delayMS(10);
        P1 = 0xfe;
        temp = P1;
        if ((temp & 0xf0) != 0xf0)
        {
            switch ((temp & 0xf0))
            {
            case 0xe0:key = 1;break;
            case 0xd0:key = 2;break;
            case 0xb0:key = 3;break;
            case 0x70:key = 4;break;           
            }
            while ((temp & 0xf0) != 0xf0)temp = P1;  // 当按键没有复原是继续监测P1口
            show2Bit(key);
            beepWork();
            return key;
        }
    }
    // 扫描第二行
    P1 = 0xfd;
    temp = P1;
    if ((temp & 0xf0) != 0xf0)
    {
        delayMS(10);
        P1 = 0xfd;
        temp = P1;
        if ((temp & 0xf0) != 0xf0)
        {
            switch ((temp & 0xf0))
            {
            case 0xe0:key = 5;break;
            case 0xd0:key = 6;break;
            case 0xb0:key = 7;break;
            case 0x70:key = 8;break;           
            }
            while ((temp & 0xf0) != 0xf0)temp = P1;
            show2Bit(key);
            return key;
        }
    }

    // 扫描第三行
    P1 = 0xfb;
    temp = P1;
    if ((temp & 0xf0) != 0xf0)
    {
        delayMS(10);
        P1 = 0xfb;
        temp = P1;
        if ((temp & 0xf0) != 0xf0)
        {
            switch ((temp & 0xf0))
            {
            case 0xe0:key = 9;break;
            case 0xd0:key = 10;break;
            case 0xb0:key = 11;break;
            case 0x70:key = 12;break;           
            }
            while ((temp & 0xf0) != 0xf0)temp = P1;
            show2Bit(key);
            return key;
        }
    }
    // 扫描第四行
    P1 = 0xf7;
    temp = P1;
    if ((temp & 0xf0) != 0xf0)
    {
        delayMS(10);
        P1 = 0xf7;
        temp = P1;
        if ((temp & 0xf0) != 0xf0)
        {
            switch ((temp & 0xf0))
            {
            case 0xe0:key = 13;break;
            case 0xd0:key = 14;break;
            case 0xb0:key = 15;break;
            case 0x70:key = 16;break;           
            }
            while ((temp & 0xf0) != 0xf0)temp = P1;
            show2Bit(key);
            return key;
        }
    }
    show2Bit(showNum);
    return showNum;
}