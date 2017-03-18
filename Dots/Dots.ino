#include <LEDColors.h>

#define outputPin 9    // Digital output pin (default: 9)
#define LEDCount 60    // Number of LEDs to drive (default: 9)
#define LEDStripCount 4 //LED Strip Count
WS2812 LED[LEDStripCount] = { WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount) };
int delayValue = 15;

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
  Dots();
}

void Dots()
{
  //Phase 1 dots
  delayValue=15;
  DotsPhaseOne(Blue());
  //Phase 2 move dots
  delayValue = 75;
  DotsPhaseTwo(100,Blue());
}

void DotsPhaseTwo(int times,cRGB color)
{
  for(int j = 0; j < times; j++)
  {
    for(int i = 0; i < LEDCount; i++)
    {
      if((i+j)%2==0)
      {
        SetColorAtIndex(i, Blank());
      }
      else
      {
        SetColorAtIndex(i,color);
      }
    }
    Sync();
    delay(delayValue);
  }
}

void DotsPhaseOne(cRGB color)
{
  DotsUp(color);
  DotsDownForward();
  DotsUp(color);
  DotsDownBackwards();
  DotsUp(color);
}

void DotsUp(cRGB color)
{
  for(int j=0;j<LEDStripCount;j++)
  {
    for(int i = 0; i < LEDCount / 2; i++)
    {
      SetColorAtIndexIndividual(i * 2,color,j);
      Sync();
      delay(delayValue);
    }
  }
}

void DotsDownForward()
{
  for(int j=0;j<LEDStripCount;j++)
  {
    for(int i = 0; i < LEDCount / 2; i++)
    {
      SetColorAtIndexIndividual(i * 2,Blank(),j);
      Sync();
      delay(delayValue);
    }
  }
}

void DotsDownBackwards()
{
  for(int j=LEDStripCount;j>0;j--)
  {
    for(int i = LEDCount; i > 0; i--)
    {
      SetColorAtIndexIndividual(i-1,Blank(),j-1);
      Sync();
      delay(delayValue/2);
    }
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

void SetColorAtIndexIndividual(int index, cRGB value,int LEDIndex)
{
  LED[LEDIndex].set_crgb_at(index,value);
}

void Sync()
{
  for(int i=0;i<LEDStripCount;i++)
  {
    LED[i].sync();
  }
}
