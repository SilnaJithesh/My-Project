 
#include <nxp/iolpc2148.h>
#include <string.h>
#include <stdio.h>
char buff[80];
#include "lcd.h"
#include "uart.h"
#include "adc.h"
#include "intrinsics.h"
int count=0,k1;


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
void UART1_ISR(void)
{
  __disable_interrupt();

  receive_buf();
  __enable_interrupt();
 
}
void main()
{

  PINSEL2=0X00000000;
  PINSEL0=0X00050005;//Configure TXD0 ,RXD0 & TXD1
  IO1DIR= 0X07FF0000;

  lcd_command(command);
  Arm_Uart0_Init();
  Arm_Uart1_Init();

 

  /*VICIntSelect &= ~(1<<VIC_UART0);           // Timer 0 intrpt is an IRQ (VIC_TIMER0 = 4)
  VICVectAddr0 = (unsigned int) & UART0_ISR; // Install ISR in VIC addr slot 0
  VICVectCntl0 = 0x20 | VIC_UART0;           // IRQ type, TIMER 0 int enabled
  VICIntEnable |= (1<<VIC_UART0);   */         // Turn on Timer0 Interrupt
  
  
  VICIntSelect &= ~(1<<VIC_UART1);           // Timer 0 intrpt is an IRQ (VIC_TIMER0 = 4)
  VICVectAddr0 = (unsigned int) & UART1_ISR; // Install ISR in VIC addr slot 0
  VICVectCntl0 = 0x20 | VIC_UART1;           // IRQ type, TIMER 0 int enabled
  VICIntEnable |= (1<<VIC_UART1);            // Turn on Timer0 Interrupt
  
 
  U1IER=0X01;
  __enable_interrupt();
 
  
  while(1)
  {
  
  
    
  //lcdconver(buff);
 
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