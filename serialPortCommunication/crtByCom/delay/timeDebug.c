#include "../main/sysParameter.h"
#include "timeDebug.h"

/**
 * ���ܣ���ʱ1S
 * ������
 * ����ֵ��
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
 * ���ܣ���ʱxms
 * ������
 * ����ֵ��
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
 * ���ܣ���ʱi��250us
 * ������
 * ����ֵ��
 */ 
void Delayst(unsigned int i)      //��ʱ����,i����ʽ����,iΪ1ʱ ��ʱԼ250US
{
	unsigned int j;
	for(;i>0;i--)             //����i��ʵ�ʲ�������һ��ֵ,���i���ܸ���ֵ
		for(j=0;j<31;j++)  // ����ֵΪ125ʱ ��Լ��ʱ1MS �ɴ˼����Ϊ1ʱ ��ʱ��Լ8US 31X8=248US��250US      
		{;}
}
