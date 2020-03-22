#include "../main/sysParameter.h"
#include "../delay/timeDebug.h"
#include "../beep/beep.h"

uint k8Flag = 0;
 /**
  * ���ܣ����������Ķ˿ڳ�ʼ��
  * ������
  * ����ֵ��
  */
void keyboardPortInit()
{
    P1 = 0xff;      // ��P1��ȫ����Ϊ�ߵ�ƽ
}
 
 /**
  * ���ܣ��������
  * ������
  * ����ֵ�����°����ı�־
  */
int waitKeyboard()
{
    keyboardPortInit();
    switch ((P1 & 0xff))   // ����P1�ڵĵ�ƽ�жϰ���
    {
    case 0xef:
        delayMS(20);       // ��ʱ����
        if(k5 == 0)
        {
            while(!k5);    // �ɿ�����������
            return 5;        
        }
    case 0xdf:
        delayMS(20);
        if(k6 == 0)
        {
            while(!k6);
            return 6;        
        } 
    case 0xbf:
        delayMS(20);
        if(k7 == 0)
        {
            while(!k7);
            return 7;        
        }
    case 0x7f:
        delayMS(20);
        if(k8 == 0)
        {
            while(!k8);
            return 8;        
        }        
    default:
        return 0;
    }
}

/**
  * ���ܣ�����K8���µı�־λ�ж���������ʱ���ǹرն�ʱ
  * ������
  * ����ֵ��
  */
uint k8Func(uint *timeCountP)
{
    if (k8Flag)
    {
        TR0 = 1;                      // ������ʱ
    }
    else
    {
        TR0 = 0;
        *timeCountP = 0;              //  ��ʱ��ֹͣʱ��������ʾ����
        TH0 = (65536 - 45872) / 256;  // ���ö�ʱ����ʼֵ
        TL0 = (65536 - 45872) % 256;
    }   
}

 /**
  * ���ܣ����ݰ���ѡ��ִ�г���
  * �������������ʾ����
  * ����ֵ���������ʾ����
  */
uint keyFunc(uint showNum, uint *timeCountP)
{
    int key = waitKeyboard();
    switch (key)
        {
        case 0:
            break;
        case 5:
            beepWork();
            showNum++;
            break;
        case 6:
            showNum--;
            break;
        case 7:
            showNum = 0;
            break;
        case 8:
            k8Flag = !k8Flag;      // ÿ��һ�α�־λת��һ��
            k8Func(timeCountP);
            break;       
        default:
            break;
        }
    return showNum;
}

 