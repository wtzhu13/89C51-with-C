#include "../main/sysParameter.h"
#include "../delay/timeDebug.h"
#include "../nixieTube/show.h"
#include "../beep/beep.h"

/**
  * ���ܣ��������ɨ�躯��
  * ������
  * ����ֵ��
  */
uint keyboardScan(uint showNum)
{
    uint temp, key;
    // ɨ���һ��
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
            while ((temp & 0xf0) != 0xf0)temp = P1;  // ������û�и�ԭ�Ǽ������P1��
            show2Bit(key);
            beepWork();
            return key;
        }
    }
    // ɨ��ڶ���
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

    // ɨ�������
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
    // ɨ�������
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