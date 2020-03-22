#include "../main/sysParameter.h"

/**
 * 函数功能：通过循环实现1秒的延时
 * 参数：无
 * 返回值：无
 */
void delay1s()
{
    uint i, j;
    for(i=1000;i>0;i--)
		 {
		 	 for(j=110;j>0;j--);
		 }
}

 /**
  * 函数功能：实现X毫秒的延时
  * 参数：需要延时的长短
  * 返回值：无
  */
void delayMS(uint xms)
{
	uint i, j;
	for ( i = xms; i > 0; i--)
	{
		for(j = 110; j > 0; j--);
	}
		
}
