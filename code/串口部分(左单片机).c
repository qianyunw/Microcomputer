#include <REG52.H>
#include <stdio.h>
unsigned char b;  
unsigned char letter[32];   
unsigned int k;   		   
unsigned int j;   		   
unsigned int Number; 
unsigned int e;	   

sbit M0=P2^0;     
sbit M1=P2^1;   
sbit M2=P2^2;     
sbit M3=P2^3;  
sbit M4=P2^4;     
sbit M5=P2^5;    
sbit IsNew=P2^6; 

void delay_ms(unsigned int z)  //延时子程序
{ 
 	unsigned int x,y;
	for(x=z;x>0;x--)
	for(y=110;y>0;y--);
}

void main (void) {
    SCON = 0x50;      	//REN=1允许串行接受状态，串口工作模式1    	       	   
	TMOD|= 0x20;      	//定时器工作方式2                    
	PCON|= 0x80;                                                          
	TH1 = 0xF3;			//波特率4800、数据位8、停止位1。效验位无 (12M)
   	TL1 = 0xF3;         
	TR1  = 1;                                                             
	ES   = 1;        	//开串口中断                  
	EA   = 1;        	//打开总中断 
	k = 0;
	for(e = 0; e < 32; e++) {
		 letter[e] = 53;
	}
	IsNew = 0;
	while(1){
	  	if (RI){       	//RI接受中断标志  
			RI=0; 	    //清除RI接受中断标志
			letter[k] = SBUF;		//SUBF接受/发送缓冲器
			k++;
       	}
		if((letter[k-1] == 0x23 && k <= 32) || k == 32) {
			Number = k;
			if(Number == 32) letter[Number-1] = 0x23;	
		   	for(j = 0; j < Number; j++) {
		   		b =  letter[j];
				if(b <= 0x5A && b >= 0x41){		//A-Z
					b = b - 0x41;
				}
				else if(b <= 0x7A && b >= 0x61){//a-z
					b = b - 0x61 + 26;
				}
				else if(b == 0x21){				//接收！
					b = 52;
				}
				else if(b == 0x23){				//结束
					b = 54;
				}
				else{							//接收到其他字符显示空白
					b = 53;
				}
				M5 = b / 32;
				M4 = b % 32 / 16;
				M3 = b % 16 / 8;
				M2 = b % 8 / 4;
				M1 = b % 4 / 2;
				M0 = b % 2 / 1;
				IsNew = 1;
				delay_ms(100);	
				IsNew = 0; 
			}
			k = 0;
		}
	}
}