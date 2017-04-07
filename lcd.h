
#define RS IO1PIN_bit.P1_24
#define RW IO1PIN_bit.P1_25
#define EN IO1PIN_bit.P1_26

char command[5]={0X38,0X01,0X06,0X0C,0X80};

void time_delay()
{
  double  i;
  for(i=0;i<0x7ff;i++)
  for(i=0;i<0xffff;i++);
}


void delay( double  x)
{
   double i; 
  for(i=0;i<x;i++);
}


void lcd_command( char command[])
{ 	 
   int i;
   	  RS=0;
          RW=0;
          EN=0;
          for(i=0;i<5;i++)
          {
            IO1PIN=(command[i]<<16)+0x00000000;
            EN=1;
            delay(200);
            EN=0;
          }
  	  
  
}


void lcddisplay( char y , char display[])
{
   int i;  
   	  RS=0;
          RW=0;
          EN=0;
	  IO1PIN=(y<<16)+0x00000000;
          EN=1;
          delay(300);
          EN=0;
	  
	  RS=1;
	    
	  for(i=0;display[i]!='\0';i++)
          {
            IO1PIN=(display[i]<<16)+0x01000000;
            EN=1;
            delay(300);
            EN=0;
            
          }
}


void signal_command(char x)
{
          RS=0;
          RW=0;
          EN=0;
	  IO1PIN=(x<<16)+0x00000000;
          EN=1;
          delay(300);
          EN=0;
}


void signal_data(char y)
{
          RS=1;
          IO1PIN=((y<<16)+0x01000000);
          EN=1;
          delay(300);
          EN=0;
}

void lcddisp(unsigned char display[])
{
  unsigned int i;
        RS=1;
	    
	  for(i=0;display[i]!='\0';i++)
          {
            IO1PIN=(display[i]<<16)+0x01000000;
            EN=1;
            delay(300);
            EN=0;
            
          }
}
void lcdconver(char disp[])
{
    
  unsigned int i;
  // signal_command(0x01);
        
         signal_command(0x80);
       //  buff[0]='\0';
           RS=1;
	    
	  for(i=0;disp[i]!='\0';i++)
          {
          
          //  signal_command(0x80);
           
            if(i==20)
            {
              signal_command(0xC0);
            }
            if(i==40)
            {
              signal_command(0x94);
            }
            if(i==60)
            { signal_command(0xD4);
             
            }
           if(i==80)
            {
             // delay(300); delay(300); delay(300); delay(300); 
              disp[0]='\0'; 
              i=0; 
            //  signal_command(0x01);
              // buff[0]='\0';
              signal_command(0x80);
            }
            IO1PIN=(disp[i]<<16)+0x01000000;
            EN=1;
            delay(300);
            EN=0;
            
          }
}
