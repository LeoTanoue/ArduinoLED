#include <LEDColors.h>

#define outputPin 13    // Digital output pin
#define LEDCount 60    // Number of LEDs to drive
#define ballSize 5     // LED cluster size
#define delayValue 10  // Delay value in milliseconds
#define LEDStripCount 4 //LED Strip Count
//Array of LED strips
WS2812 LED[LEDStripCount] = { WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount) };

void setup()
{
  delay(2000);
  for(int i=0;i<LEDStripCount;i++)
  {
    LED[i].setOutput(outputPin);
  }
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
    SetColorAtIndex(i,value);
  }    
  Sync();
}

void Ping()
{
  cRGB value = RandomColor();
  for(int i = 0; i < LEDCount; i++)
  {
    for(int b = 0; b < ballSize; b++)
    {
      SetColorAtIndex(i+b,value);
    }
    if(i > ballSize-1)
    {
      for(int c = ballSize; c > 0; c--)
      {
        SetColorAtIndex(i-c,Blank());
      }
    }
    Sync();
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
      SetColorAtIndex(i-b,value);
    }
    if(i < (LEDCount - ballSize))
    {
      for(int c = ballSize; c > 0; c--)
      {
        SetColorAtIndex(i+c,Blank());
      }
    }
    Sync();
    delay(delayValue);
  }
}

void SetColorAtIndex(int index, cRGB value)
{
  for(int i=0;i<LEDStripCount;i++)
  {
    LED[i].set_crgb_at(index,value);
  }
}

void Sync()
{
  for(int i=0;i<LEDStripCount;i++)
  {
    LED[i].sync();
  }
}
