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

void loop() 
{
  int delayValue = 100;  
  int i;
  
  ChangeRGB(0,0,255);
  for(i = 0; i < LEDCount; i++)
  {
      LED.set_crgb_at(i, value);
  }

  LED.sync(); // Sends the data to the LEDs
  delay(delayValue); // Wait (ms)
  
  ChangeRGB(0,255,0);
  for(i = 0; i < LEDCount; i++)
  {
      LED.set_crgb_at(i, value);
  }

  LED.sync(); // Sends the data to the LEDs
  delay(delayValue); // Wait (ms)
  
  ChangeRGB(255,0,0);
  for(i = 0; i < LEDCount; i++)
  {
      LED.set_crgb_at(i, value);
  }

  LED.sync(); // Sends the data to the LEDs
  delay(delayValue); // Wait (ms)
}

void ChangeRGB(int r,int g,int b)
{
  value.r = r;
  value.g = g;
  value.b = b;
}


