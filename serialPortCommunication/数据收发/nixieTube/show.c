#include <reg52.h>
#include "../main/sysParameter.h"
#include "../delay/timeDebug.h"
//#include "show.h"

// 数码管段码，对应1-16
int ledNum[16] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};
// 数码管位码，从左到右八位
int ledPos[8] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};

/**
  * 功能：计算各位和十位数
  * 参数：十位数字的指针和各位数字的指针
  * 返回值：
  */
void _compute2Bit(uint figure, uint *pUnit, uint *pDecade)
{
 	  uint unit, decade;
      unit = figure % 10;      // 计算个位数
      decade = figure / 10;    // 计算十位数
	  *pUnit = unit;           // 指针间接赋值
	  *pDecade = decade;
}

/**
  * 功能：显示数字到数码管
  * 参数：需要显示的数字
  * 返回值：
  */
void show2Bit(uint figure)
{
    uint unit = 0; 
	  uint decade = 0;
  	_compute2Bit(figure, &unit, &decade);
    P2 = ledPos[0];             // P2控制数码管的位数
    P0 = ledNum[decade];        // P0控制数码管段码
    delayMS(5);
    P2 = ledPos[1];
    P0 = ledNum[unit];
    delayMS(5);
}

