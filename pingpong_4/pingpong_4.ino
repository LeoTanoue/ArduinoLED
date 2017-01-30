#include <WS2812.h>
#include <cRGB.h>

#define outputPin 9  // Digital output pin (default: 9)
#define LEDCount 60   // Number of LEDs to drive (default: 9)

//List of LED's
WS2812 LED1(LEDCount);
WS2812 LED2(LEDCount);
WS2812 LED3(LEDCount);
WS2812 LED4(LEDCount);
cRGB value;

void setup()
{
  delay(2000);
  LED1.setOutput(outputPin); // Digital Pin 9
  LED2.setOutput(outputPin); 
  LED3.setOutput(outputPin); 
  LED4.setOutput(outputPin);
}

boolean firstTime = true;

void loop()
{  
  int delayValue = 20;
  int i,r,g,b;
  
  if(firstTime)
  {
    //Blank
    ChangeRGB(0,0,0);
    for(i = 0; i < LEDCount; i++)
    {
        LED1.set_crgb_at(i, value);
        LED2.set_crgb_at(i, value);
        LED3.set_crgb_at(i, value);
        LED4.set_crgb_at(i, value);
    }
    LED1.sync(); // Sends the data to the LEDs
    LED2.sync();
    LED3.sync();
    LED4.sync();
    firstTime = false;
    delay(delayValue); // Wait (ms)
  }
  
  r = getRandomColor();
  g = getRandomColor();
  b = getRandomColor();
  for(i = 0; i <= LEDCount; i++)
  {
    ChangeRGB(r,g,b);
    LED1.set_crgb_at(i, value);
    LED1.set_crgb_at(i+1, value);
    LED2.set_crgb_at(i, value);
    LED2.set_crgb_at(i+1, value);
    LED3.set_crgb_at(i, value);
    LED3.set_crgb_at(i+1, value);
    LED4.set_crgb_at(i, value);
    LED4.set_crgb_at(i+1, value);
    ChangeRGB(0,0,0);
    if( i > 1)
    {
      LED1.set_crgb_at(i-1,value);
      LED1.set_crgb_at(i-2,value);
      LED2.set_crgb_at(i-1,value);
      LED2.set_crgb_at(i-2,value);
      LED3.set_crgb_at(i-1,value);
      LED3.set_crgb_at(i-2,value);
      LED4.set_crgb_at(i-1,value);
      LED4.set_crgb_at(i-2,value);
    }
    LED1.sync();
    LED2.sync();
    LED3.sync();
    LED4.sync();
    delay(delayValue);
  }

  r = getRandomColor();
  g = getRandomColor();
  b = getRandomColor();
  for(i = LEDCount; i > 0; i--)
  {
    ChangeRGB(r,g,b);
    LED1.set_crgb_at(i, value);
    LED1.set_crgb_at(i-1, value);
    LED2.set_crgb_at(i, value);
    LED2.set_crgb_at(i-1, value);
    LED3.set_crgb_at(i, value);
    LED3.set_crgb_at(i-1, value);
    LED4.set_crgb_at(i, value);
    LED4.set_crgb_at(i-1, value);
    ChangeRGB(0,0,0);
    if( i < (LEDCount - 2))
    {
      LED1.set_crgb_at(i+1,value);
      LED1.set_crgb_at(i+2,value);
      LED2.set_crgb_at(i+1,value);
      LED2.set_crgb_at(i+2,value);
      LED3.set_crgb_at(i+1,value);
      LED3.set_crgb_at(i+2,value);
      LED4.set_crgb_at(i+1,value);
      LED4.set_crgb_at(i+2,value);
    }
    LED1.sync();
    LED2.sync();
    LED3.sync();
    LED4.sync();
    delay(delayValue);
  }
  
}

void ChangeRGB(int r,int g,int b)
{
  value.r = r;
  value.g = g;
  value.b = b;
}

int getRandomColor()
{
  return random(0,256);
}
