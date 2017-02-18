#include <LEDColors.h>

#define outputPin 9    // Digital output pin (default: 9)
#define LEDCount 60    // Number of LEDs to drive (default: 9)
#define ballSize 5     // LED cluster size
#define delayValue 10  // Delay value in milliseconds
#define LEDStripCount 4 //LED Strip Count

WS2812 LED[LEDStripCount] = { WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount) };

int h = 0;   //stores 0 to 614
byte steps = 15; //number of hues we skip in a 360 range per update
byte sat = 255;
byte val = 127;

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
  HueChange();
}

void HueChange()
{
  Cycle();
  for(int i = 0; i < LEDCount; i++)
  {
    SetColorAtIndex(i,value);
  }
  Sync();
  delay(delayValue);
}

void Clear()
{
  cRGB value = Blank();
  for(int i = 0; i < LEDCount; i++)
  {
    setColorAtIndex(i,value);
  }    
  Sync();
}

void Cycle()
{
  value.SetHSV(h, sat, val);
  
  h += steps;  
  if(h > 360)
  {
      h %= 360;
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
