#ifndef _INFRARED_H_
#define _INFRARED_H_
#ifdef __cplusplus
extern "C";
{
#endif
#include <reg52.h>
#include "../main/sysParameter.h"
/************************************************************
函数功能：对4个字节的用户码和键数据码进行解码
说明：解码正确，返回1，否则返回0
出口参数：dat
*************************************************************/
bit DeCode(uchar *a);
/*------------------二进制码转换为压缩型BCD码,并显示---------------*/
void two_2_bcd(unsigned char date);
extern unsigned int LowTime,HighTime;
//extern unsigned char a[4];

#ifdef __cplusplus
}
#endif
#endif