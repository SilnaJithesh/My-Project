#define relay1 IO0PIN_bit.P0_2
#define relay2 IO0PIN_bit.P0_3
#define relay3 IO0PIN_bit.P0_15
#define sw1 IO0PIN_bit.P0_10
#define sw2 IO0PIN_bit.P0_11
#define led1 IO0PIN_bit.P0_12
void rfwd()
{
  relay1=0;
  relay2=1;
  relay3=0;
}
void rrev()
{
  relay1=0;
  relay2=0;
  relay3=1;
}
void lfwd()
{
  relay1=1;
  relay2=0;
  relay3=1;
}
void lrev()
{
  relay3=1;
  relay1=0;
  relay2=0;
}
void rev()//do not cal
{
    relay2=0; relay3=0;relay1=1;
}
void front()
{
 relay2=1; relay3=1;relay1=0;
}

void reverse()
{
  relay1=1;//rev
relay2=0;
  relay3=0;
}

void stop()
{
  relay2=0;
  relay3=0;
    //relay1=0;
 /* relay1=1;
  relay2=1;
  relay3=1;*/
}
