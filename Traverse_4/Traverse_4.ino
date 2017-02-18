#include <LEDColors.h>

#define outputPin 9    // Digital output pin (default: 9)
#define LEDCount 60    // Number of LEDs to drive (default: 9)
#define ballSize 5     // LED cluster size
#define delayValue 10  // Delay value in milliseconds
#define LEDStripCount 4 //LED Strip Count

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
  Traverse(White());
  Traverse(Red());
  Traverse(Green());
  Traverse(Blue());
  Traverse(Gray());
  Traverse(Yellow());
  Traverse(Cyan());
  Traverse(Magenta());
  Traverse(RandomColor());
}

void Traverse(cRGB value)
{
  for(int i = 0; i < LEDCount; i++)
  {
    SetColorAtIndex(i,value);
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
