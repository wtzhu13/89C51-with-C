#ifndef _SYSPARAMETER_H_
#define _SYSPARAMETER_H_

#include <reg52.h>

#ifdef __cplusplus
extern "C";
{
#endif

sbit RS=P2^0;    //寄存器选择位，将RS位定义为P2.0引脚
sbit RW=P2^1;    //读写选择位，将RW位定义为P2.1引脚
sbit E=P2^2;     //使能信号位，将E位定义为P2.2引脚
sbit BF=P0^7;    //忙碌标志位，，将BF位定义为P0.7引脚
sbit IR=P3^2;    //将IR位定义为P3.2引脚

#define uint unsigned int
#define uchar unsigned char


#ifdef __cplusplus
}
#endif
#endif