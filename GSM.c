 
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

int count=0,k1;

char dis[6];
int num;
char aa;
void UART0_ISR(void)
{
     //buff[0]='\0';
    
  
  __disable_interrupt();
//for(k=0;k<10;k++)
  //{
  while((U0LSR&0X01)!=0X01);
    buff[k1]=U0RBR;
  if(buff[k1]==0x0d)
  {
     buff[k1]='\0';
     k1=0;
     buff[0]='\0';
  }
     else
     {
       k1=k1+1;
     }
  //lcdconver(buff);
 // signal_command(0xc0);
  // lcddisp(buff);
 // }
__enable_interrupt();
 /* __disable_interrupt();
  while((U0LSR&0X01)!=0X01);
  buf[count]=U0RBR;
   signal_command(0xc0);
  signal_data(buf[0]);
  count=count+1;
      __enable_interrupt();*/
  /*if(s[count]==0x0d)
  {
    s[count]='\0';
     lcd_command(command);
     lcddisp(s);
     printf("Received:%s count:%d",s,count);
  }
  
  single_transmit_U0(s[count]);*/
}
void rotation(char s)
{
  switch(s)
  {
  case 'r':
      reverse();//reverse
    break;
    
    case 'l':
       lrev();
       delay(8000);
        reverse();
    break;
  }
}
void UART1_ISR(void)
{


  receive_buf();
  
 
}
void main()
{
  int ii;
  PINSEL2=0X00000000;
  PINSEL0=0X00050005;//Configure TXD0 ,RXD0 & TXD1
  IO1DIR= 0XE7FF0000;
  lcd_command(command);
  Arm_Uart0_Init();
  Arm_Uart1_Init();
   IO0DIR_bit.P0_2=1;
   IO0DIR_bit.P0_3=1;
   IO0DIR_bit.P0_15=1;

 
  VICIntSelect &= ~(1<<VIC_UART1);           // Timer 0 intrpt is an IRQ (VIC_TIMER0 = 4)
  VICVectAddr0 = (unsigned int) & UART1_ISR; // Install ISR in VIC addr slot 0
  VICVectCntl0 = 0x20 | VIC_UART1;           // IRQ type, TIMER 0 int enabled
  VICIntEnable |= (1<<VIC_UART1);            // Turn on Timer0 Interrupt
  
 
  U1IER=0X01;
  __enable_interrupt();  
  
 
  lcddisplay(0X80,"D:"); 
   relay1=0; relay2=0; relay3=0;
  while(1)
  {
   
  // lrev();//right turn
 //  rfwd();//left turn
  //  front();
    while(single_receive_U0()!='R');
     for(ii=0;ii<3;ii++)
     {
       dis[ii]=single_receive_U0();
     }
     dis[3]='\0';
     num=atoi(dis);
     printf("dis:%d",num);
     lcddisplay(0X82,dis); 
     if(num>=9)
     {
     aa='r';
      printf("\nrevers ");
     }
     else if(num<9)
     {
       aa='l';
        printf("\nleft");
       /*lrev();
       delay(100);
        reverse();*/
     }
     printf("\naa:%c",aa);
     rotation(aa);
       if(sw1==0)
       {
          reverse();//reverse
       }
     if(sw2==0)
       {
          lrev();
       }
  }
}


#pragma vector=0x18
__irq __arm void irq_handler (void)
{
  void (*interrupt_function)();
  unsigned int vector;

  vector = VICVectAddr;     
  interrupt_function = (void(*)())vector;
  (*interrupt_function)();  
  VICVectAddr = 0;          
}





__fiq __arm void fiq_handler (void)
{
    while(1);
}