
unsigned char *mob_num[3]={"8056207847","9840956105"};//8374616909

unsigned char *lat={"Accident Occured at lat.value - "};
unsigned char *lon={"longitude value - "};

void msg_init(void)
{
    string_transmit_U0("AT");
    single_transmit_U0(0x0D);
     single_transmit_U0(0x0A);
    delay(5000);
    string_transmit_U0("AT+CMGF=1");
    single_transmit_U0(0x0D);
     single_transmit_U0(0x0A);
    delay(5000);
    string_transmit_U0("AT+CMGS=");
    delay(5000);
}


void send_msg(unsigned char *mob_num)
{
    single_transmit_U0('"');
    string_transmit_U0(mob_num);
    single_transmit_U0('"');
    single_transmit_U0(0x0D);
    single_transmit_U0(0x0A);
    string_transmit_U0( "Cow Crossing");
    string_transmit_U0( "Cow ID:5622");
    serial_transmit_arr(BUF,0,23);
   // single_transmit(0x0D);
    
}    
void send_msg1(unsigned char *mob_num)
{
    single_transmit_U0('"');
    string_transmit_U0(mob_num);
    single_transmit_U0('"');
    single_transmit_U0(0x0D);
    single_transmit_U0(0x0A);
    string_transmit_U0( "Goat Crossing");
    string_transmit_U0( "Goat ID:4994");
    serial_transmit_arr(BUF,0,23);
   // single_transmit(0x0D);
    
}    
/*void send_msg1(unsigned char *mob_num)
{
    single_transmit('"');
    serial_transmit(mob_num);
    single_transmit('"');
    single_transmit(0x0D);
   
    U0THR=0x3C;	
    while((U0LSR&0x20)!=0x20);
    serial_transmit_arr(tx1,0,10);
    single_transmit(Receive_buf[10]);
    U0THR=0x3E;	
    while((U0LSR&0x20)!=0x20);
    
  
    serial_transmit_arr(tx2,0,10);
    single_transmit(Receive_buf[22]);
    single_transmit('?');
   
    
}*/
void msg_end(void)
{
    U0THR=0X1A;       
    while((U0LSR&0x20)!=0x20); 
}    

void send_mssg(void)
{
  msg_init();
  send_msg(mob_num[0]);
  msg_end();
  
  
}  
void send_mssg_1(void)
{
  msg_init();
  send_msg(mob_num[1]);
  msg_end();
  
  
}  
void send_mssg1(void)
{
 
  msg_init();
  send_msg1(mob_num[0]);
  msg_end();
  
  
  
}  
void send_mssg1_1(void)
{
 
  msg_init();
  send_msg1(mob_num[1]);
  msg_end();
  
  
  
}  