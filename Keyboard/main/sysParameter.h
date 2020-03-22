#ifndef _SYSPARAMETER_H_
#define _SYSPARAMETER_H_

#include <reg52.h>

#ifdef __cplusplus
extern "C";
{
#endif

sbit k1 = P3^2;
sbit k2 = P3^3;
sbit k3 = P3^4;
sbit k4 = P3^5;
sbit k5 = P1^4;
sbit k6 = P1^5;
sbit k7 = P1^6;
sbit k8 = P1^7;
sbit BEEP = P3^6;

#define uint unsigned int
#define uchar unsigned char


#ifdef __cplusplus
}
#endif
#endif