#include<nxp/iolpc2148.h>

#include<stdlib.h>
#include<string.h>
#include<stdio.h>
unsigned char Receive_buf[25];
char tx[15],tx1[15],tx2[15],tx3[15],tx4[15],tx5[15];
#include"uart.h"
#include"lcd.h"
#include"gps.h"
#include"gsm.h"
#include"adc.h"

#define relay1 IO0PIN_bit.P0_2
#define relay2 IO0PIN_bit.P0_3
#define relay3 IO0PIN_bit.P0_15
#define led1 IO0PIN_bit.P0_12

unsigned int i,j;
unsigned char a;
int ADC1,ADC2,ADC3;
int adcvalue1,adcvalue2,adcvalue3;
int a1,a3,a4,a5;

char la[9],lo[9];
char long1[9];
float lat11,lon11,lat21,lon21;


void lcd_print(void)
{
   unsigned int l,k;
   
      
    strncpy(la,Receive_buf,9);
    la[8]='\0';
    lat11=atof(la);
    lat21=lat11/100;
    sprintf(tx1,"@%f",lat21);
   
   
    for(k=0,l=11;l<18;l++,k++)
    {
      long1[k]=Receive_buf[l];
    }
    strncpy(lo,long1,9);
    lo[8]='\0';
    lon11=atof(lo);
    lon21=lon11/100;
    sprintf(tx2,"|%f",lon21);
  
}    

void stop()
{
    relay1=0;
 /* relay1=1;
  relay2=1;
  relay3=1;*/
}

void lfwd()
{
  relay1=1;
  relay2=0;
  relay3=1;
}
void front()
{
  relay1=1;
  /*relay2=0;
  relay3=0;*/
}
void rrev()
{
  relay1=0;
  relay2=0;
  relay3=1;
}

void rev()
{
  relay1=0;
  relay2=1;
  relay3=1;
}
void rfwd()
{
  long ii;
  relay2=1;
  
  relay1=0;relay3=0;
  //for(ii==0;ii<500;ii++){}
  // relay1=1;relay3=1;
  // for(ii==0;ii<500;ii++){}
  
}

void main()
{
  PINSEL0= 0x00050005;
  uart0_init();// to configure baur rate as 9600 for uart0
  uart1_init();// to configure baur rate as 9600 for uart1
  PINSEL2=0X00000000;
  IO1DIR =0X07FF0000;
  lcdinit();
  
  
  while(1)
  {
   
    //stop();
    ADC1=ADCSEL0(AD0_1);//gas
    ADC2=ADCSEL0(AD0_2);
    ADC3=ADCSEL0(AD0_4);//o2
    adcvalue1=(ADC1*0.097656);
    adcvalue2=(ADC2*0.097656);
    adcvalue3=(ADC3*0.097656);
    sprintf(tx3,"Gas:%03d",adcvalue1);
    sprintf(tx4,"T:%03d",adcvalue2);
    sprintf(tx5,"O2:%03d",adcvalue3);
    lcddisplay(tx3,0x80);
    lcddisplay(tx4,0x87);
    lcddisplay(tx5,0xc0);
    serial_transmit_arr(tx3,0,6);
    serial_transmit_arr(tx4,0,5);
    serial_transmit_arr(tx5,0,6);
  }
}


