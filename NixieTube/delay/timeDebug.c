#include "../main/sysParameter.h"

/**
 * �������ܣ�ͨ��ѭ��ʵ��1�����ʱ
 * ��������
 * ����ֵ����
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
  * �������ܣ�ʵ��X�������ʱ
  * ��������Ҫ��ʱ�ĳ���
  * ����ֵ����
  */
void delayMS(uint xms)
{
	uint i, j;
	for ( i = xms; i > 0; i--)
	{
		for(j = 110; j > 0; j--);
	}
		
}
