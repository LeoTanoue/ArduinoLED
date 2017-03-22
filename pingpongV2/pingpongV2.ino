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
  cRGB value = BaseColor();
  int i = 0;
  while(i <= LEDCount)
  {
    SetColorAtIndex(i,value);
    if(i >= ballSize)
    {
      SetColorAtIndex(i-ballSize,Blank());
    }
    Sync();
    delay(delayValue);
    
    i++;
  }
}

void Pong()
{
  cRGB value = BaseColor();
  int i = LEDCount;
  while((i-ballSize) >= 0)
  {
    SetColorAtIndex(i-ballSize,value);
    SetColorAtIndex(i,Blank());
    Sync();
    delay(delayValue);
    i--;
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
