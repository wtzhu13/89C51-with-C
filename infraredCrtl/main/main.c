#include <intrins.h>  //����_nop_()���������ͷ�ļ�
#include "../delay/timeDebug.h"
#include "sysParameter.h"
#include "../1602Ctrl/1602Crtl.h"
#include "../infrared/infrared.h"
unsigned char code string[ ]= {"RED-CODE TEST"}; 
unsigned char interrupt_flag;
unsigned int LowTime,HighTime;
unsigned char a[4];


/***************************************************
�������ܣ�������
***************************************************/

void main(void)            
{
    unsigned char i;	
	LcdInitiate();         //����LCD��ʼ������  
    delayMS(10);
	WriteInstruction(0x01);//����ʾ������Ļָ��
	WriteAddress(0x00);  // ������ʾλ��Ϊ��һ�еĵ�1����
  	i = 0;
	while(string[i] != '\0')    //'\0'�����������־ 
		{						// ��ʾ�ַ�	WWW.RICHMCU.COM
			WriteData(string[i]);
			i++;	
		}
    EA=1;        //�������ж�
    EX0=1;       //�����ж�0
    ET0=1;       //��ʱ��T0�ж�����
    IT0=1;       //���жϵ��½��ش���  
    TMOD=0x01;   //ʹ�ö�ʱ��T0��ģʽ1	
    TR0=0;       //��ʱ��T0�ر�
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
    EX0=0;      //�ر����ж�0�����ٽ��ն��κ����źŵ��жϣ�ֻ���뵱ǰ�����ź�
	TH0=0;		//��ʱ��T0�ĸ�8λ��0
	TL0=0;		//��ʱ��T0�ĵ�8λ��0
	TR0=1;	  	//������ʱ��T0			
	while(IR==0);		   //����ǵ͵�ƽ�͵ȴ�����������͵�ƽ��ʱ
	TR0=0;				  //�رն�ʱ��T0	  
	LowTime=TH0*256+TL0;  //����͵�ƽʱ��
	TH0=0;		//��ʱ��T0�ĸ�8λ��0
	TL0=0;		//��ʱ��T0�ĵ�8λ��0
	TR0=1;		//������ʱ��T0
	while(IR==1);  //����Ǹߵ�ƽ�͵ȴ�����������ߵ�ƽ��ʱ
	TR0=0;		  //�رն�ʱ��T0
	HighTime=TH0*256+TL0;	//����������ĸߵ�ƽ����
	if((LowTime>7800)&&(LowTime<8800)&&(HighTime>3600)&&(HighTime<4700))
	 {
		//�����������,�Ϳ�ʼ����,�������,������ĵ͵�ƽ��ʱ
	   //������9000us/1.085=8294, �ж�����:8300��500��7800��8300��500��8800.
		  if(DeCode(a) == 1) // ִ��ң�ؽ��빦��
		 {		
			Disp(a);//����1602LCD��ʾ����
		 }
	 }
	EX0=1;	 //�������ж�X0
    interrupt_flag = 1;
}
