#include <nxp/iolpc2148.h>
#include "lcd.h"
#define relay1 IO1PIN_bit.P1_29
#define relay2 IO1PIN_bit.P1_30
#define relay3 IO1PIN_bit.P1_31

void main()
{
  PINSEL2=0X00000000;
   IO1DIR= 0XE7FF0000;
     lcd_command(command);
       lcddisplay(0Xcb,"D:");
   relay2=1; relay3=1;
   
}