#ifndef _INFRARED_H_
#define _INFRARED_H_
#ifdef __cplusplus
extern "C";
{
#endif
#include <reg52.h>
#include "../main/sysParameter.h"
/************************************************************
�������ܣ���4���ֽڵ��û���ͼ���������н���
˵����������ȷ������1�����򷵻�0
���ڲ�����dat
*************************************************************/
bit DeCode(uchar *a);
/*------------------��������ת��Ϊѹ����BCD��,����ʾ---------------*/
void two_2_bcd(unsigned char date);
extern unsigned int LowTime,HighTime;
//extern unsigned char a[4];

#ifdef __cplusplus
}
#endif
#endif