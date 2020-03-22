#include <reg52.h>
#include "sysParameter.h"
#include "../delay/timeDebug.h"
#include "../nixie_tube/show.h"
#include "../keboard/independent.h"
#include "../keboard/matrix.h"

uint T0Flag = 0;

void interruptInit()
{
    TMOD = 0x01;                  // ���ö�ʱ��0λ������ʽ1
    TH0 = (65536 - 45872) / 256;  // ���ö�ʱ����ʼֵ
    TL0 = (65536 - 45872) % 256;  
    EA = 1;                       // �������ж�  
    ET0 = 1;                      // ������ʱ��0�ж�
    TR0 = 0;                      // �ȴ�������ʱ��0
}

void main()
{
    uint showNum = 1;  // ��ʼ����ʾ����
    // show2Bit(showNum);   // ���������ʾ����
    interruptInit();   // ��ʼ���ж�
    while(1)
    {    
        // show2Bit(showNum);   // ���������ʾ����
        // showNum = keyFunc(showNum, &T0Flag);   // �ȴ�������������       
        // if (T0Flag >= 40)
        // {
        //     T0Flag = 0;
        //     showNum++;
        // }
        showNum = keyboardScan(showNum);
    }   
}

 /**
  * ���ܣ�
  * ������
  * ����ֵ��
  */
void T0_time() interrupt 1
{
    T0Flag ++;
    TH0 = (65536 - 45872) / 256;  // ���ö�ʱ����ʼֵ
    TL0 = (65536 - 45872) % 256;
     
}