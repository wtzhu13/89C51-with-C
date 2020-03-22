#include "../main/sysParameter.h"
#include "timeDebug.h"

/**
 * 功能：延时1S
 * 参数：
 * 返回值：
 */
void delay()
{
    uint i,j;
    for(i=1000;i>0;i--)
		 {
		 	 for(j=110;j>0;j--);
		 }
}

/**
 * 功能：延时xms
 * 参数：
 * 返回值：
 */
void delayMS(uint xms)
{
	uint i, j;
	for ( i = xms; i > 0; i--)
	{
		for(j = 110; j > 0; j--);
	}
		
}

/**
 * 功能：延时i个250us
 * 参数：
 * 返回值：
 */ 
void Delayst(unsigned int i)      //延时程序,i是形式参数,i为1时 延时约250US
{
	unsigned int j;
	for(;i>0;i--)             //变量i由实际参数传入一个值,因此i不能赋初值
		for(j=0;j<31;j++)  // 此数值为125时 大约延时1MS 由此计算出为1时 延时大约8US 31X8=248US≈250US      
		{;}
}
