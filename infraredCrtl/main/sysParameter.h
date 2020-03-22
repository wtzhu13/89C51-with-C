#ifndef _SYSPARAMETER_H_
#define _SYSPARAMETER_H_

#include <reg52.h>

#ifdef __cplusplus
extern "C";
{
#endif

sbit RS=P2^0;    //�Ĵ���ѡ��λ����RSλ����ΪP2.0����
sbit RW=P2^1;    //��дѡ��λ����RWλ����ΪP2.1����
sbit E=P2^2;     //ʹ���ź�λ����Eλ����ΪP2.2����
sbit BF=P0^7;    //æµ��־λ������BFλ����ΪP0.7����
sbit IR=P3^2;    //��IRλ����ΪP3.2����

#define uint unsigned int
#define uchar unsigned char


#ifdef __cplusplus
}
#endif
#endif