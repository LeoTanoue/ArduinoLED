#include <LEDColors.h>

#define outputPin 9    // Digital output pin (default: 9)
#define LEDCount 60    // Number of LEDs to drive (default: 9)
#define LEDStripCount 4 //LED Strip Count
WS2812 LED[LEDStripCount] = { WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount) };
int delayValue = 10;

void setup()
{
  delay(2000);
  for(int i=0;i<LEDStripCount;i++)
  {
    LED[i].setOutput(outputPin);
  }
}

void loop()
{
  Clear();
  SlowTraverse(4,3,Blue());
}

void SlowTraverse(int forward, int backwards, cRGB color)
{
  int i = forward;
  int j = 0;
  while(i < LEDCount)
  {
    LightUp(j,i,color);
    FadeDown(i,j+backwards);
    i = i + forward;
    j = j + backwards;
  }
  LightUp(j,LEDCount,Blue());
}

void LightUp(int startIndex, int endIndex, cRGB value)
{
  for(int i = startIndex; i <= endIndex; i++)
  {
    SetColorAtIndex(i,value);
    Sync();
    delay(delayValue);
  }
}

void FadeDown(int startIndex, int endIndex)
{
  for(int i = startIndex; i >= endIndex; i--)
  {
    SetColorAtIndex(i,Blank());
    Sync();
    delay(delayValue);
  }
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
