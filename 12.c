
#include <nxp/iolpc2148.h>
#include <string.h>
#include <stdio.h>
char buff[80];
#include "lcd.h"
#include "intrinsics.h"
int count=0,k1,card1=0,card2=0;
#include "uart.h"

#include"adc.h"
#define led1 IO0PIN_bit.P0_12
#define led2 IO0PIN_bit.P0_13
int ADC1,ADC2,ADC3;
int adcvalue1,adcvalue2,adcvalue3;
char tx[15],tx1[15],tx2[15],tx3[15],tx4[15],tx5[15];
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


  receive_buf();


}
void main()
{

  PINSEL0=0X00050005;//Configure TXD0 ,RXD0 & TXD1,RXD1 v
  PINSEL2=0X00000000;
  IO1DIR= 0X07FF0000;
  lcd_command(command);
  Arm_Uart0_Init();//uart0 at baud rate of 9600
  Arm_Uart1_Init();//uart1 at baud rate of 9600


  VICIntSelect &= ~(1<<VIC_UART1);           // Timer 0 intrpt is an IRQ (VIC_TIMER0 = 4)
  VICVectAddr0 = (unsigned int) & UART1_ISR; // Install ISR in VIC addr slot 0
  VICVectCntl0 = 0x20 | VIC_UART1;           // IRQ type, TIMER 0 int enabled
  VICIntEnable |= (1<<VIC_UART1);            // Turn on Timer0 Interrupt


   U1IER=0X01;
  __enable_interrupt();
    IO0DIR_bit.P0_12=1;
    IO0DIR_bit.P0_13=1;

  while(1)
  {
  /*
    ADC1=ADCSEL0(AD0_1);//gas
    ADC2=ADCSEL0(AD0_2);
    ADC3=ADCSEL0(AD0_4);//o2*/

    ADC1=ADCSEL0(AD0_4);//gas
    ADC2=ADCSEL1(AD1_7);
    ADC3=ADCSEL0(AD0_2);//o2

    adcvalue1=(ADC1*0.097656);
    adcvalue2=(ADC2*0.097656);
    adcvalue3=(ADC3*0.097656);
    adcvalue2=adcvalue2+13;
    sprintf(tx3,"Gas:%03d",adcvalue1);//Gas:045
    sprintf(tx4,"T:%03d",adcvalue2);
    sprintf(tx5,"O2:%03d",adcvalue3);

    /*single_transmit_U0('*');
    single_transmit_U0('/');
    serial_transmit_arr(tx3,0,7);
    single_transmit_U0(' ');
    serial_transmit_arr(tx4,0,5);
    single_transmit_U0(0xdf);
    single_transmit_U0('C');
    single_transmit_U0(' ');
    serial_transmit_arr(tx5,0,6);*/
    if(card1==1)
    {
     led1=1;led2=0;
    single_transmit_U0('*');
    single_transmit_U0('/');
    serial_transmit_arr(tx3,0,7);
    single_transmit_U0(' ');
    serial_transmit_arr(tx4,0,5);
    single_transmit_U0(0xdf);
    single_transmit_U0('C');
    single_transmit_U0(' ');
    serial_transmit_arr(tx5,0,6);

       delay(7000);
         delay(7000);
           delay(7000);
       card1=0;
    }
    else if(card2==1)
    {
        led2=1;led1=0;
    single_transmit_U0('*');
    single_transmit_U0('+');
    serial_transmit_arr(tx3,0,7);
    single_transmit_U0(' ');
    serial_transmit_arr(tx4,0,5);
    single_transmit_U0(0xdf);
    single_transmit_U0('C');
    single_transmit_U0(' ');
    serial_transmit_arr(tx5,0,6);

       card2=0;
    }
    else
    {
        led1=0;led2=0;
     //  single_transmit_U0('-');
    }
  //  single_transmit_U0(0x0d); single_transmit_U0(0x0a);
    lcddisplay(0x80,tx3);
    lcddisplay(0x87,tx4);
    lcddisplay(0xc0,tx5);

  //  receive_buf();
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