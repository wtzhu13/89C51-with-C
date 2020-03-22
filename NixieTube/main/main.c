/**
 * author: wtzhu
 * date: 20200307
 * function: test NixieTube and interrupt
 * e_mail: wtzhu_13@163.com
 * version:
 */

#include <reg52.h>
#include "sysParameter.h"
#include "../delay/timeDebug.h"

int ledNum[16] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};
uint num = 0;
 
/***********************************************************/
/*******************�жϳ�ʼ������**************************/
/***********************************************************/

 /**
  * ���ܣ��жϳ�ʼ��
  * ��������
  * ����ֵ����
  */
void interruptInit()
{
    TMOD = 0x11;                  // ���ö�ʱ��0λ������ʽ1
    TH0 = (65536 - 45872) / 256;  // ���ö�ʱ����ʼֵ
    TL0 = (65536 - 45872) % 256;  
    EA = 1;                       // �������ж�  
    ET0 = 1;                      // ������ʱ��0�ж�
    TR0 = 1;                      // ������ʱ��0
}

/***********************************************************/
/*********************���������****************************/
/***********************************************************/

 /**
  * ���ܣ����������
  * ��������
  * ����ֵ����
  */
void main()
{
    uint i = 0;
    interruptInit();
    while (1)
    {       
        P2=0xf0;
        P0 = ledNum[i];
        delay1s();
        i++;
        if (i >= 16)
        {
             i = 0;
        }
//        if (num == 20)
//        {
//            i++;
//            num = 0;               // ʱ�䵽�˱�־λ����
//            if (i >= 16)
//            {
//                i = 0;
//            }
//            
//        }
             
    }   
}

/***********************************************************/
/*********************��ʱ��0�жϺ���***********************/
/***********************************************************/

 /**
  * ���ܣ���ʱ��0�жϺ���
  * ������
  * ����ֵ��
  */
void T0_time() interrupt 1
{
    TH0 = (65536 - 45872) / 256;      // ÿ�μ������������ó�ʼֵ
    TL0 = (65536 - 45872) % 256;
    num++;                            // ����һ�α�־λ��1
}