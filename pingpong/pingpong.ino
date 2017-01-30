#include <WS2812.h>
#include <cRGB.h>

#define outputPin 9  // Digital output pin (default: 9)
#define LEDCount 60   // Number of LEDs to drive (default: 9)

//List of LED's
WS2812 LED(LEDCount); 
cRGB value;

void setup()
{
  delay(2000);
  LED.setOutput(outputPin); // Digital Pin 9
}

boolean firstTime = true;

void loop()
{  
  int delayValue = 25;
  int i,r,g,b;
  
  if(firstTime)
  {
    //Blank
    ChangeRGB(0,0,0);
    for(i = 0; i < LEDCount; i++)
    {
        LED.set_crgb_at(i, value);
    }
    LED.sync(); // Sends the data to the LEDs
    firstTime = false;
    delay(delayValue); // Wait (ms)
  }
  
  r = getRandomColor();
  g = getRandomColor();
  b = getRandomColor();
  for(i = 0; i <= LEDCount; i++)
  {
    ChangeRGB(r,g,b);
    LED.set_crgb_at(i, value);
    LED.set_crgb_at(i+1, value);
    ChangeRGB(0,0,0);
    if( i > 1)
    {
      LED.set_crgb_at(i-1,value);
      LED.set_crgb_at(i-2,value);
    }
    LED.sync();
    delay(delayValue);
  }

  r = getRandomColor();
  g = getRandomColor();
  b = getRandomColor();
  for(i = LEDCount; i > 0; i--)
  {
    ChangeRGB(r,g,b);
    LED.set_crgb_at(i, value);
    LED.set_crgb_at(i-1, value);
    ChangeRGB(0,0,0);
    if( i < (LEDCount - 2))
    {
      LED.set_crgb_at(i+1,value);
      LED.set_crgb_at(i+2,value);
    }
    LED.sync();
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
