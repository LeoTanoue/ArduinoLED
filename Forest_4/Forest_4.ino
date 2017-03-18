#define USE_HSV
#include <LEDColors.h>

#define outputPin 9    // Digital output pin (default: 9)
#define LEDCount 60    // Number of LEDs to drive (default: 9)
#define ballSize 5     // LED cluster size
#define LEDStripCount 4 //LED Strip Count
int delayValue = 10;  // Delay value in milliseconds
int cycles[3] = { 15, 5, 100};
WS2812 LED[LEDStripCount] = { WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount) };
int h = 0;   //stores 0 to 614
byte steps = 15; //number of hues we skip in a 360 range per update
byte sat = 255;
byte val = 127;
cRGB hvalue;

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
  //Ping Pong Start
  delayValue = 10;
  int i;
  for(i = 0; i < cycles[0]; i++)
  {
    Ping();
    Pong();
  }
  //Traverse Start
  delayValue = 15;
  for(i = 0; i < cycles[1]; i++)
  {
    TraverseColors();
  }
  //Hue Change Start
  delayValue = 85;
  for(int i = 0; i < cycles[2]; i++)
  {
    HueChange();
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

void Ping()
{
  cRGB value = RandomColor();
  for(int i = 0; i <= LEDCount; i++)
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

void Traverse(cRGB value)
{
  for(int i = 0; i < LEDCount; i++)
  {
    SetColorAtIndex(i,value);
    Sync();
    delay(delayValue);
  }
}

void TraverseColors()
{
  Traverse(Red());
  Traverse(Green());
  Traverse(Blue());
  Traverse(Yellow());
  Traverse(Cyan());
  Traverse(Magenta());
  Traverse(RandomColor());
}

void HueChange()
{
  Cycle();
  for(int i = 0; i < LEDCount; i++)
  {
    SetColorAtIndex(i,hvalue);
  }
  Sync();
  delay(delayValue);
}

void Cycle()
{
  hvalue.SetHSV(h, sat, val);
  
  h += steps;  
  if(h > 360)
  {
      h %= 360;
  }
}
