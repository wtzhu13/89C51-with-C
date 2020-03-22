#ifndef _1602CTRL_H_
#define _1602CTRL_H_
#ifdef __cplusplus
extern "C";
{
#endif

#include "../main/sysParameter.h"

unsigned char BusyTest(void);
void WriteInstruction (unsigned char dictate);
void WriteAddress(unsigned char x);
void WriteData(unsigned char y);
void LcdInitiate(void);
/************************************************************
 函数功能：1602LCD显示
 *************************************************************/
void Disp(uchar *a);
//extern uchar a[4];

#ifdef __cplusplus
}
#endif
#endif