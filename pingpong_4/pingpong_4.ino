#include <LEDColors.h>

#define outputPin 9    // Digital output pin (default: 9)
#define LEDCount 60    // Number of LEDs to drive (default: 9)
#define ballSize 10     // LED cluster size
#define delayValue 10  // Delay value in milliseconds

//List of LED's
WS2812 LED1(LEDCount);
WS2812 LED2(LEDCount);
WS2812 LED3(LEDCount);
WS2812 LED4(LEDCount);

void setup()
{
  delay(2000);
  LED1.setOutput(outputPin); // Digital Pin 9
  LED2.setOutput(outputPin); 
  LED3.setOutput(outputPin); 
  LED4.setOutput(outputPin);
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
    LED1.set_crgb_at(i, value);
    LED2.set_crgb_at(i, value);
    LED3.set_crgb_at(i, value);
    LED4.set_crgb_at(i, value);
  }    
  LED1.sync(); // Sends the data to the LEDs
  LED2.sync();
  LED3.sync();
  LED4.sync();
}

void Ping()
{
  cRGB value = RandomColor();
  for(int i = 0; i <= LEDCount; i++)
  {
    for(int b = 0; b < ballSize; b++)
    {
      LED1.set_crgb_at(i + b, value);
      LED2.set_crgb_at(i + b, value);
      LED3.set_crgb_at(i + b, value);
      LED4.set_crgb_at(i + b, value);
    }
    if(i > ballSize-1)
    {
      for(int c = ballSize; c > 0; c--)
      {
        LED1.set_crgb_at(i-c,Blank());
        LED2.set_crgb_at(i-c,Blank());
        LED3.set_crgb_at(i-c,Blank());
        LED4.set_crgb_at(i-c,Blank());
      }
    }
    LED1.sync();
    LED2.sync();
    LED3.sync();
    LED4.sync();
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
      LED1.set_crgb_at(i - b, value);
      LED2.set_crgb_at(i - b, value);
      LED3.set_crgb_at(i - b, value);
      LED4.set_crgb_at(i - b, value);
    }
    if(i < (LEDCount - ballSize))
    {
      for(int c = ballSize; c > 0; c--)
      {
        LED1.set_crgb_at(i+c,Blank());
        LED2.set_crgb_at(i+c,Blank());
        LED3.set_crgb_at(i+c,Blank());
        LED4.set_crgb_at(i+c,Blank());
      }
    }
    LED1.sync();
    LED2.sync();
    LED3.sync();
    LED4.sync();
    delay(delayValue);
  }
}
