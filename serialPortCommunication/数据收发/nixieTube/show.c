#include <reg52.h>
#include "../main/sysParameter.h"
#include "../delay/timeDebug.h"
//#include "show.h"

// ����ܶ��룬��Ӧ1-16
int ledNum[16] = {0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e};
// �����λ�룬�����Ұ�λ
int ledPos[8] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f};

/**
  * ���ܣ������λ��ʮλ��
  * ������ʮλ���ֵ�ָ��͸�λ���ֵ�ָ��
  * ����ֵ��
  */
void _compute2Bit(uint figure, uint *pUnit, uint *pDecade)
{
 	  uint unit, decade;
      unit = figure % 10;      // �����λ��
      decade = figure / 10;    // ����ʮλ��
	  *pUnit = unit;           // ָ���Ӹ�ֵ
	  *pDecade = decade;
}

/**
  * ���ܣ���ʾ���ֵ������
  * ��������Ҫ��ʾ������
  * ����ֵ��
  */
void show2Bit(uint figure)
{
    uint unit = 0; 
	  uint decade = 0;
  	_compute2Bit(figure, &unit, &decade);
    P2 = ledPos[0];             // P2��������ܵ�λ��
    P0 = ledNum[decade];        // P0��������ܶ���
    delayMS(5);
    P2 = ledPos[1];
    P0 = ledNum[unit];
    delayMS(5);
}

