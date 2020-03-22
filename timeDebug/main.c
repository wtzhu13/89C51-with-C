/**
 * author: wtzhu
 * date: 20200306
 * function: test time delay
 * version:
 */

#include <reg52.h>
#include "timeDebug.h"
#include "sysParameter.h"

#define led1 P0
sbit beef = P3^6;

void main()
{
	while(1)
	{
		led1 = 0xF0;
        beef = 1;
		delay(); 
		led1 = 0xFF;
        beef = 0;
		delay();
	}
}

