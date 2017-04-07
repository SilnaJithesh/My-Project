
#define AD0_0  0   	// not  available
#define AD0_1  1   	// adc0 channel 1 
#define AD0_2  2	// adc0 channel 2 
#define AD0_3  3	// adc0 channel 3 
#define AD0_4  4	// adc0 channel 4 
#define AD0_5  5	// adc0 channel 5 
#define AD0_6  6	// adc0 channel 6 
#define AD0_7  7	// adc0 channel 7 

#define AD1_0  0   	// not  available
#define AD1_1  1   	// adc1 channel 1 
#define AD1_2  2	// adc1 channel 2 
#define AD1_3  3	// adc1 channel 3 
#define AD1_4  4	// adc1 channel 4 
#define AD1_5  5	// adc1 channel 5 
#define AD1_6  6	// adc1 channel 6 
#define AD1_7  7	// adc1 channel 7 


int value,value1;
int ADCSEL0(int y)
{
  switch(y)
  {
    //  AD0CR_bit.SEL   //00000000   adc0.7 to adc0.0 
    //  adc channel 0 not allowed  0 th & 5 th channel
    
  case 1: 
    PINSEL1_bit.P0_28 = 0x01;      // adc channel P0.28  adc0.1
    AD0CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD0CR_bit.BURST=1;       //To prevent the repeated conversion
    AD0CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD0CR_bit.PDN=1;         //A/D converter is operational
    AD0CR_bit.SEL = 0x02;    //select the ADC0.1 
    while(AD0DR_bit.DONE==0);//wait till the conversion is over
    value=AD0DR1_bit.RESULT;
    break;
    
  case 2: 
    PINSEL1_bit.P0_29 = 0x01;      // adc channel P0.29  adc0.2
    AD0CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD0CR_bit.BURST=1;       //To prevent the repeated conversion
    AD0CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD0CR_bit.PDN=1;         //A/D converter is operational
    AD0CR_bit.SEL = 0x04;    //select the ADC0.2 
    while(AD0DR_bit.DONE==0);//wait till the conversion is over
    value=AD0DR2_bit.RESULT;
    break;
    
  case 3: 
    PINSEL1_bit.P0_30 = 0x01;      // adc channel P0.30  adc0.3
    AD0CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD0CR_bit.BURST=1;       //To prevent the repeated conversion
    AD0CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD0CR_bit.PDN=1;         //A/D converter is operational
    AD0CR_bit.SEL = 0x08;    //select the ADC0.3 
    while(AD0DR_bit.DONE==0);//wait till the conversion is over
    value=AD0DR3_bit.RESULT;
    break;
    
  case 4: 
    PINSEL1_bit.P0_25 = 0x01;      // adc channel P0.25  adc0.4
    AD0CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD0CR_bit.BURST=1;       //To prevent the repeated conversion
    AD0CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD0CR_bit.PDN=1;         //A/D converter is operational
    AD0CR_bit.SEL = 0x10;    //select the ADC0.4
    while(AD0DR_bit.DONE==0);//wait till the conversion is over
    value=AD0DR4_bit.RESULT;
    break;
    
    
    
  case 6: 
    PINSEL0_bit.P0_4 = 0x11;      // adc channel P0.4  adc0.6
    AD0CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD0CR_bit.BURST=1;       //To prevent the repeated conversion
    AD0CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD0CR_bit.PDN=1;         //A/D converter is operational
    AD0CR_bit.SEL = 0x40;    //select the ADC0.6  
    while(AD0DR_bit.DONE==0);//wait till the conversion is over
    value=AD0DR6_bit.RESULT;
    break;
    
  case 7: 
    PINSEL0_bit.P0_5 = 0x11;      // adc channel P0.28  adc0.7
    AD0CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD0CR_bit.BURST=1;       //To prevent the repeated conversion
    AD0CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD0CR_bit.PDN=1;         //A/D converter is operational
    AD0CR_bit.SEL = 0x80;    //select the ADC0.7 
    while(AD0DR_bit.DONE==0);//wait till the conversion is over
    value=AD0DR7_bit.RESULT;
    break;
    
  default :
    break;
    
  }
  return(value);
}



// adc1   pins reserved (or) adc channels 
// adc1 
int ADCSEL1(int y)  
{
  switch(y)
  {
  case 0:
    PINSEL0_bit.P0_6 = 0x11;      // adc channel P0.6  adc1.0
    AD1CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD1CR_bit.BURST=1;       //To prevent the repeated conversion
    AD1CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD1CR_bit.PDN=1;         //A/D converter is operational
    AD1CR_bit.SEL = 0x01;    //select the ADC1.0 
    while(AD1DR_bit.DONE==0);//wait till the conversion is over
    value1=AD1DR0_bit.RESULT;
    break;
    
    case 1:
    PINSEL0_bit.P0_8 = 0x11;      // adc channel P0.8  adc1.1
    AD1CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD1CR_bit.BURST=1;       //To prevent the repeated conversion
    AD1CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD1CR_bit.PDN=1;         //A/D converter is operational
    AD1CR_bit.SEL = 0x02;    //select the ADC1.1 
    while(AD1DR_bit.DONE==0);//wait till the conversion is over
    value1=AD1DR1_bit.RESULT;
    break;
    
    case 2:
    PINSEL0_bit.P0_10 = 0x11;      // adc channel P0.10  adc1.2
    AD1CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD1CR_bit.BURST=1;       //To prevent the repeated conversion
    AD1CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD1CR_bit.PDN=1;         //A/D converter is operational
    AD1CR_bit.SEL = 0x04;    //select the ADC1.2 
    while(AD1DR_bit.DONE==0);//wait till the conversion is over
    value1=AD1DR2_bit.RESULT;
    break;
    
    case 3:
    PINSEL0_bit.P0_12 = 0x11;      // adc channel P0.12  adc1.3
    AD1CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD1CR_bit.BURST=1;       //To prevent the repeated conversion
    AD1CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD1CR_bit.PDN=1;         //A/D converter is operational
    AD1CR_bit.SEL = 0x08;    //select the ADC1.3 
    while(AD1DR_bit.DONE==0);//wait till the conversion is over
    value1=AD1DR3_bit.RESULT;
    break;
    
    case 4:
    PINSEL0_bit.P0_13 = 0x11;      // adc channel P0.13  adc1.4
    AD1CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD1CR_bit.BURST=1;       //To prevent the repeated conversion
    AD1CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD1CR_bit.PDN=1;         //A/D converter is operational
    AD1CR_bit.SEL = 0x10;    //select the ADC1.4 
    while(AD1DR_bit.DONE==0);//wait till the conversion is over
    value1=AD1DR4_bit.RESULT;
    break;
    
    case 5:
    PINSEL0_bit.P0_15 = 0x11;      // adc channel P0.6  adc1.5
    AD1CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD1CR_bit.BURST=1;       //To prevent the repeated conversion
    AD1CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD1CR_bit.PDN=1;         //A/D converter is operational
    AD1CR_bit.SEL = 0x20;    //select the ADC1.5 
    while(AD1DR_bit.DONE==0);//wait till the conversion is over
    value1=AD1DR5_bit.RESULT;
    break;
    
    case 6:
    PINSEL1_bit.P0_21 = 0x10;      // adc channel P0.6  adc1.6
    AD1CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD1CR_bit.BURST=1;       //To prevent the repeated conversion
    AD1CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD1CR_bit.PDN=1;         //A/D converter is operational
    AD1CR_bit.SEL = 0x40;    //select the ADC1.6 
    while(AD1DR_bit.DONE==0);//wait till the conversion is over
    value1=AD1DR6_bit.RESULT;
    break;
    
    case 7:
    PINSEL1_bit.P0_22 = 0x01;      // adc channel P0.6  adc1.7
    AD1CR_bit.CLKDIV =0x02;  // VPB clock (PCLK) is divided by 2
    AD1CR_bit.BURST=1;       //To prevent the repeated conversion
    AD1CR_bit.CLKS=0;        //clk indicate 11 clocks / 10 bits
    AD1CR_bit.PDN=1;         //A/D converter is operational
    AD1CR_bit.SEL = 0x80;    //select the ADC1.7 
    while(AD1DR_bit.DONE==0);//wait till the conversion is over
    value1=AD1DR7_bit.RESULT;
    break;
    default :
    break;
  }
  return(value1);
}

