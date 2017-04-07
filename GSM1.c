 
#include <nxp/iolpc2148.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char buff[80];
#include "lcd.h"
#include "intrinsics.h"
#include "uart.h"
#include"motor.h"
#include"adc.h"
#include"gsm.h"

#define sen1 IO0PIN_bit.P0_29
#define sen2 IO1PIN_bit.P1_27
#define sen3 IO1PIN_bit.P1_28
#define sen4 IO1PIN_bit.P1_29
#define sen5 IO1PIN_bit.P1_31
#define sen6 IO1PIN_bit.P1_30

int count=0,k1,count1=0;

char dis[6];
int num;
char aa;

void rotation(char s)
{
  switch(s)
  {
  case 'r':
      front();//reverse
    break;
    
    case 'l':
       lrev();
       delay(8000);
        front();
    break;
  }
}
void sensorfunction()
{
     if(sen3==1  && sen4==1 ) 
      {
         front();
       
     }
     else if(( sen2==0)||(sen1==0))
     {
    lrev();
     }
       else if((sen5==0 )||(sen6==1))
      {
     rfwd();
     }
     /* while(((sen5==0 )&&(sen6==1))) 
     {
       rfwd();
     }
     while(((sen1==0 )&&(sen2==0)))
     {
       lrev();
     }*/
}
void UART1_ISR(void)
{


  receive_buf();
   
}
void main()
{
  int ii,k;
  PINSEL2=0X00000000;
  PINSEL0=0X00050005;//Configure TXD0 ,RXD0 & TXD1
  IO1DIR= 0X07FF0000;
  IO0DIR_bit.P0_12=1;
  lcd_command(command);
  signal_command(0x80);
  lcddisp(" Animal Tracking    ");
  signal_command(0x01);
  delay(2000);
  Arm_Uart0_Init();
  Arm_Uart1_Init();
  IO0DIR_bit.P0_2=1;
  IO0DIR_bit.P0_3=1;
  IO0DIR_bit.P0_15=1;
  PINSEL1_bit.P0_29=0x00;
 
   
   lcddisplay(0Xcb,"D:"); 
   relay1=0; relay2=0; relay3=0;
   led1=0;
  while(1)
  {
  
    // lrev();//right turn
  // rfwd();//left turn
//  front();
   sensorfunction();
  }
}








