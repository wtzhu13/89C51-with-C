#include <reg52.h>
#define uint unsigned int
#define uchar unsigned char

unsigned char flag, i, a;
uchar code table[] = "I get ";

/***********************************************************/
/*********************introduction**************************/
/***********************************************************/

void interruptInit()
{
    TMOD = 0x20;    
    TH1 = 0xfd;     
    TL1 = 0xfd;
    // ET1 = 1;        
    TR1 = 1;        
    REN = 1;        
    SM0 = 0;       
    SM1 = 1;
    EA = 1;         
    ES = 1;         
}

/***********************************************************/
/*********************introduction**************************/
/***********************************************************/

void main()
{
    interruptInit();
    while (1)
    {
        if (flag == 1)
        {
            ES = 0;
            for ( i = 0; i < 6; i++)
            {
                SBUF = table[i];
                while(!TI);
                TI = 0;
            }
            SBUF = a;
            while(!TI);
            TI = 0;   
            ES = 1;  
            flag = 0;       
        }        
    }
}

/***********************************************************/
/*********************introduction**************************/
/***********************************************************/

void ser() interrupt 4
{
    RI = 0;
    a = SBUF;
    flag = 1;
}
