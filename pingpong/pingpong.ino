#include <LEDColors.h>

#define outputPin 9    // Digital output pin (default: 9)
#define LEDCount 60    // Number of LEDs to drive (default: 9)
#define ballSize 3     // LED cluster size
#define delayValue 20  // Delay value in milliseconds

//List of LED's
WS2812 LED(LEDCount);

void setup()
{
  delay(2000);
  LED.setOutput(outputPin); // Digital Pin 9  
  Clear();
}

void loop()
{
  Ping();
  Pong();
}

void Clear()
{
  cRGB value = Blank();
  for(int i = 0; i < LEDCount; i++)
  {
    LED.set_crgb_at(i, value);
  }
  LED.sync(); // Sends the data to the LEDs
}

void Ping()
{
  cRGB value = RandomColor();
  for(int i = 0; i <= LEDCount; i++)
  {
    for(int b = 0; b < ballSize; b++)
    {
      LED.set_crgb_at(i + b, value);
    }
    if(i > ballSize-1)
    {
      for(int c = ballSize; c > 0; c--)
      {
        LED.set_crgb_at(i-c,Blank());
      }
    }
    LED.sync();
    delay(delayValue);
  }
}

void Pong()
{
  cRGB value = RandomColor();
  for(int i = LEDCount; i > 0; i--)
  {
    for(int b = 0; b < ballSize; b++)
    {
      LED.set_crgb_at(i - b, value);
    }
    if(i < (LEDCount - ballSize))
    {
      for(int c = ballSize; c > 0; c--)
      {
        LED.set_crgb_at(i+c,Blank());
      }
    }
    LED.sync();
    delay(delayValue);
  }
}
