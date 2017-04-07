
 char BUF[11],receivebuf[5];
int k2=0;
int a1,a2,a3,a4,a5;
#define DESIRED_BAUDRATE 9600
#define CRYSTAL_FREQUENCY_IN_HZ 12000000
#define PCLK CRYSTAL_FREQUENCY_IN_HZ         // since VPBDIV=0x01
#define DIVISOR (PCLK/(16*DESIRED_BAUDRATE))

#define DESIRED_BAUDRATE1 9600
#define CRYSTAL_FREQUENCY_IN_HZ 12000000
#define PCLK CRYSTAL_FREQUENCY_IN_HZ         // since VPBDIV=0x01
#define DIVISOR1 (PCLK/(16*DESIRED_BAUDRATE1))



void Arm_Uart0_Init(void)
{
  PINSEL0_bit.P0_0 = 1;
  PINSEL0_bit.P0_1 = 1;
  U0LCR=0x83;
  VPBDIV=0x01;
  U0DLL=DIVISOR&0xFF;
  U0DLM=DIVISOR>>8;
  U0LCR=0x03 ;      
 // U0FCR=0x05 ; 
}

void Arm_Uart1_Init(void)
{
  PINSEL0_bit.P0_8 = 1;
  PINSEL0_bit.P0_9 = 1;
  U1LCR=0x83;         
  VPBDIV=0x01;          
  U1DLL=DIVISOR1&0xFF;               
  U1DLM=DIVISOR1>>8;              
  U1LCR=0x03 ;      
 // U1FCR=0x05 ; 
}

void single_transmit_U1(unsigned char x)
{
  U1THR=x;
  while (!(U1LSR&0x20));
}

void string_transmit_U1(char *str)
{
  while(*str)
  {
    U1THR=*str++;
    while (!(U1LSR&0x20));
  }
}

void single_transmit_U0(unsigned char x)
{
  U0THR=x;
  while (!(U0LSR&0x20));
}

void string_transmit_U0(char *str)
{
  while(*str)
  {
    U0THR=*str++;
    while (!(U0LSR&0x20));
  }
}

unsigned char single_receive_U1()
{
  while((U1LSR&0X01)!=0X01);
  return(U1RBR);
}
void serial_transmit_arr(unsigned char arr[],unsigned char start,unsigned char stop)
{
  unsigned int k;
  
  for(k=start;k<stop;k++)
  {
    U0THR=arr[k];	
    while((U0LSR&0x20)!=0x20);
  }

}


unsigned char single_receive_U0()
{
  while((U0LSR&0X01)!=0X01);
  return(U0RBR);
}


void receive_buf()
{
 int k=0,j;
 // signal_command(0x01);
  // signal_command(0xc0);
   __disable_interrupt();
  for(k=0;k<10;k++)
  {
    while((U1LSR&0X01)!=0X01);
    BUF[k]=U1RBR;
   
  }
   BUF[10]='\0';
  // serial_transmit_arr(BUF,0,10);
  //signal_command(0xc0);
 // lcddisp(BUF);
   if(strncmp(BUF,"24035622",8)==0)
   {
     card1=1;
         //string_transmit_U0("@T1152");
  //   single_transmit_U0('#');
    
      // string_transmit_U0("Tiger Crossing");
       //single_transmit_U0(0x0d); single_transmit_U0(0x0a);
      // string_transmit_U0("Animal ID:1152");
       
       //single_transmit_U0('!');
       lcddisplay(0x80,"Animal ID:5622" );
       lcddisplay(0xC0,"Tiger Crossing  " );
      /*  delay(88888);
        lcddisplay(0x80,"               " );
       lcddisplay(0xC0,"                " );
      */
    
   }
   else if(strncmp(BUF,"25134994",8)==0)
   {
    
      card2=1;
       //single_transmit_U0('@');
       //string_transmit_U0("T7786");
   //  single_transmit_U0('#');
   
       //string_transmit_U0("Tiger Crossing");
       //single_transmit_U0(0x0d); single_transmit_U0(0x0a);
      // string_transmit_U0("Animal ID:7786");
       
       //single_transmit_U0('!');
       lcddisplay(0x80,"Animal ID:4994" );
       lcddisplay(0xC0,"Deer Crossing  " );
        strcpy(BUF,"             ");
        BUF[0]='\0';
      /*  delay(88888);
        lcddisplay(0x80,"               " );
       lcddisplay(0xC0,"                " );
      */
    
   }
   else if(strncmp(BUF,"13337841",8)==0)
   {
    
     
        //single_transmit_U0('@');
       // string_transmit_U0("D7841");
   //    single_transmit_U0('^');
     //delay(3000);
       //string_transmit_U0("Deer Crossing");
       //single_transmit_U0(0x0d); single_transmit_U0(0x0a);
       //string_transmit_U0("Animal ID:7841");
       
       //single_transmit_U0('!');
       lcddisplay(0x80,"Animal ID:7841" );
       lcddisplay(0xC0,"Deer Crossing  " );
        strcpy(BUF,"             ");
        BUF[0]='\0';
      /*  delay(88888);
        lcddisplay(0x80,"               " );
       lcddisplay(0xC0,"                " );
      */
    
   }
    __enable_interrupt();
  
  /* if(strncmp(BUF,"13337841",8)==0)
   {
    
     
       single_transmit_U0('*');
       string_transmit_U0("Tiger Crossing");
       string_transmit_U0("Animal ID:7841");
       
       single_transmit_U0('!');
       lcddisplay(0x80,"Animal ID:7841" );
       lcddisplay(0xC0,"Tiger Crossing  " );
        delay(88888);
        lcddisplay(0x80,"               " );
       lcddisplay(0xC0,"                " );
      
    
   }
   else if(strncmp(BUF,"13337786",5)==0)
   {
  
     single_transmit_U0('*');
       string_transmit_U0("Deer Crossing");
       string_transmit_U0("Animal ID:7786");
       
       single_transmit_U0('!');
       lcddisplay(0x80,"Animal ID:7841" );
       lcddisplay(0xC0,"Deer Crossing  " );
        delay(88888);
        lcddisplay(0x80,"               " );
       lcddisplay(0xC0,"                " );
       
  
    
   }*/
  
    /* for(k2=0,j=0;k2<4;k2++,j++)
    {
       receivebuf[j]= BUF[k2];
    }
    receivebuf[j]='\0';*/
   //  lcddisplay(0x80,BUF);
     /* for(k2=4,j=0;k2<8;k2++,j++)
  {
    receivebuf[j]= BUF[k2];
  
  }
   receivebuf[j]='\0';
     signal_command(0x01);
  lcddisplay(0xc0,receivebuf);*/
 
  //  BUF[k]='\0';
 
 
     // single_transmit_U0('*');
      //string_transmit_U0(BUF);
      // single_transmit_U0('!');
     /*  if(strcmp(BUF,"15411336")==0)//16709967
   {
     single_transmit_U0('*');
      string_transmit_U0("1336");
       single_transmit_U0('!');
       BUF[0]='\0';
        strcpy(BUF,"                    ");
   }
  if(strcmp(receivebuf,"4078")==0)//16709967
   {
      single_transmit_U0('*');
      string_transmit_U0(receivebuf);
       single_transmit_U0('!');
    // lcddisplay(0x80," WELCOME SELVAN " );
    // lcddisplay(0xC0," xxxxxxxxxxx967 " );
     //delay(88888);
    
    
     strcpy(BUF,"         ");
     strcpy(receivebuf,"         ");
   }
   else if(strcmp(receivebuf,"2775")==0)
   {
      single_transmit_U0('*');
      string_transmit_U0(receivebuf);
      single_transmit_U0('!');
    // lcddisplay(0x80,"  WELCOME BABU   " );
    // lcddisplay(0xC0," xxxxxxxxxxx968 " );
    // delay(88888);
    
  
     strcpy(BUF,"         ");
      strcpy(receivebuf,"         ");
   }
   else if(strcmp(receivebuf,"1336")==0)
   {
      single_transmit_U0('*');
      string_transmit_U0(receivebuf);
       single_transmit_U0('!');
     //lcddisplay(0x80,"  WELCOME kayal   " );
   //  lcddisplay(0xC0," xxxxxxxxxxx968 " );
     //delay(88888);
     strcpy(BUF,"         ");
     strcpy(receivebuf,"         ");
   }
   else if(strcmp(receivebuf,"8902")==0)
   {
      single_transmit_U0('*');
      string_transmit_U0(receivebuf);
       single_transmit_U0('!');
    // lcddisplay(0x80,"  WELCOME SARAN   " );
   //  lcddisplay(0xC0," xxxxxxxxxxx968 " );
    // delay(88888);
     strcpy(BUF,"         ");
     strcpy(receivebuf,"         ");
   }
   else if(strcmp(receivebuf,"6995")==0)
   { single_transmit_U0('*');
      string_transmit_U0(receivebuf);
       single_transmit_U0('!');
  //   lcddisplay(0x80,"  WELCOME SINDU   " );
  //   lcddisplay(0xC0," xxxxxxxxxxx968 " );
    // delay(88888);
     strcpy(BUF,"         ");
     strcpy(receivebuf,"         ");
   }*/
 
  // U0IER=0X01;
 // BUF[8]='\0';
 
}

