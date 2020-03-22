#include <intrins.h>  //包含_nop_()函数定义的头文件
#include "../delay/timeDebug.h"
#include "sysParameter.h"
#include "../1602Ctrl/1602Crtl.h"
#include "../infrared/infrared.h"
unsigned char code string[ ]= {"RED-CODE TEST"}; 
unsigned char interrupt_flag;
unsigned int LowTime,HighTime;
unsigned char a[4];


/***************************************************
函数功能：主函数
***************************************************/

void main(void)            
{
    unsigned char i;	
	LcdInitiate();         //调用LCD初始化函数  
    delayMS(10);
	WriteInstruction(0x01);//清显示：清屏幕指令
	WriteAddress(0x00);  // 设置显示位置为第一行的第1个字
  	i = 0;
	while(string[i] != '\0')    //'\0'是数组结束标志 
		{						// 显示字符	WWW.RICHMCU.COM
			WriteData(string[i]);
			i++;	
		}
    EA=1;        //开启总中断
    EX0=1;       //开外中断0
    ET0=1;       //定时器T0中断允许
    IT0=1;       //外中断的下降沿触发  
    TMOD=0x01;   //使用定时器T0的模式1	
    TR0=0;       //定时器T0关闭
    P1 = 0x00;
    while(1)
    {
        if(interrupt_flag)
        {
            interrupt_flag = 0;
            P1 = ~P1;
   
        }
    }  		
}

void Int0(void) interrupt 0
{
    EX0=0;      //关闭外中断0，不再接收二次红外信号的中断，只解码当前红外信号
	TH0=0;		//定时器T0的高8位清0
	TL0=0;		//定时器T0的低8位清0
	TR0=1;	  	//开启定时器T0			
	while(IR==0);		   //如果是低电平就等待，给引导码低电平计时
	TR0=0;				  //关闭定时器T0	  
	LowTime=TH0*256+TL0;  //保存低电平时间
	TH0=0;		//定时器T0的高8位清0
	TL0=0;		//定时器T0的低8位清0
	TR0=1;		//开启定时器T0
	while(IR==1);  //如果是高电平就等待，给引导码高电平计时
	TR0=0;		  //关闭定时器T0
	HighTime=TH0*256+TL0;	//保存引导码的高电平长度
	if((LowTime>7800)&&(LowTime<8800)&&(HighTime>3600)&&(HighTime<4700))
	 {
		//如果是引导码,就开始解码,否则放弃,引导码的低电平计时
	   //次数＝9000us/1.085=8294, 判断区间:8300－500＝7800，8300＋500＝8800.
		  if(DeCode(a) == 1) // 执行遥控解码功能
		 {		
			Disp(a);//调用1602LCD显示函数
		 }
	 }
	EX0=1;	 //开启外中断X0
    interrupt_flag = 1;
}
