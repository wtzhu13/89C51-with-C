#include "../main/sysParameter.h"
#include "infrared.h"
#include <reg52.h>
#include "../1602Ctrl/1602Crtl.h"

/************************************************************
函数功能：对4个字节的用户码和键数据码进行解码
说明：解码正确，返回1，否则返回0
出口参数：dat
*************************************************************/
bit DeCode(uchar *a)
{
    uchar i;
    uchar j;
	uchar temp;    //储存解码出的数据
	for(i=0;i<4;i++)      //连续读取4个用户码和键数据码
	  {
		 for(j=0;j<8;j++)  //每个码有8位数字
			 {
		         temp=temp>>1;  //temp中的各数据位右移一位，因为先读出的是高位数据									
				 TH0=0;         //定时器清0
   			     TL0=0;         //定时器清0
   			     TR0=1;         //开启定时器T0
   		         while(IR==0);  //如果是低电平就等待
   	               	      		//低电平计时
   		  	     TR0=0;         //关闭定时器T0
   			     LowTime=TH0*256+TL0;    //保存低电平宽度
   			     TH0=0;         //定时器清0
   			     TL0=0;         //定时器清0
   			     TR0=1;         //开启定时器T0
   			     while(IR==1);  //如果是高电平就等待
   			       			   
   			     TR0=0;         //关闭定时器T0
   			     HighTime=TH0*256+TL0;   //保存高电平宽度
			     if((LowTime<370)||(LowTime>640))
			  		    return 0;        //如果低电平长度不在合理范围，则认为出错，停止解码			
			     if((HighTime>420)&&(HighTime<620))   //如果高电平时间在560微秒左右，即计数560／1.085＝516次
			           temp=temp&0x7f;       //(520-100=420, 520+100=620)，则该位是0
			     if((HighTime>1300)&&(HighTime<1800)) //如果高电平时间在1680微秒左右，即计数1680／1.085＝1548次
			           temp=temp|0x80;       //(1550-250=1300,1550+250=1800),则该位是1
		     }  			            
	   a[i]=temp;	//将解码出的字节值储存在a[i]																					 
    }  				 		 
     if(a[2] == ~a[3])  //验证键数据码和其反码是否相等,一般情况下不必验证用户码
	    return 1;     //解码正确，返回1
     else
        return 0;
}        

/*------------------二进制码转换为压缩型BCD码,并显示---------------*/

void two_2_bcd(unsigned char date)
{
	unsigned char temp;
	temp=date;
	date&=0xf0;
	date>>=4;                    //右移四位得到高四位码
	date&=0x0f;                  //与0x0f想与确保高四位为0
	if(date<=0x09)
	{                 
		WriteData(0x30+date);            //lcd显示键值高四位
	}
	else
	{
		date=date-0x09;
		WriteData(0x40+date);
	}
	date=temp;
	date&=0x0f;
	if(date<=0x09)
	{
	 	WriteData(0x30+date);            //lcd显示低四位值
	}
	else
	{
		date=date-0x09;
		WriteData(0x40+date);
	}
	WriteData(0x48);                 //显示字符'H'
} 