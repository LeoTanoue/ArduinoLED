#include <LEDColors.h>

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
  int i;
  
  if(firstTime)
  {
    //Blank
    value = Blank();
    for(i = 0; i < LEDCount; i++)
    {
        LED.set_crgb_at(i, value);
    }
    LED.sync(); // Sends the data to the LEDs
    firstTime = false;
    delay(delayValue); // Wait (ms)
  }
  
  value = RandomColor();
  for(i = 0; i <= LEDCount; i++)
  {
    LED.set_crgb_at(i, value);
    LED.set_crgb_at(i+1, value);
    if( i > 1)
    {
      LED.set_crgb_at(i-1,Blank());
      LED.set_crgb_at(i-2,Blank());
    }
    LED.sync();
    delay(delayValue);
  }

  
  value = RandomColor();
  for(i = LEDCount; i > 0; i--)
  {
    LED.set_crgb_at(i, value);
    LED.set_crgb_at(i-1, value);
    if( i < (LEDCount - 2))
    {
      LED.set_crgb_at(i+1,Blank());
      LED.set_crgb_at(i+2,Blank());
    }
    LED.sync();
    delay(delayValue);
  }
  
}
