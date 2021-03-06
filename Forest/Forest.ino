#define USE_HSV
#include <LEDColors.h>

#define outputPin 13    // Digital output pin
#define LEDCount 60    // Number of LEDs to drive
#define ballSize 5     // LED cluster size
#define LEDStripCount 4 //LED Strip Count
int delayValue = 10;  // Delay value in milliseconds
int cycles[4] = { 10, 5, 5, 100}; //Different shapes need to run different amounts of cycles
WS2812 LED[LEDStripCount] = { WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount), WS2812(LEDCount) }; //Array to hold LED Strips
int hue = 0;   //stores 0 to 614
cRGB hueColor;   //cRGB to hold color of Hue Change

void setup()
{
  delay(2000);
  //Sets up all LED Strips to the output (Data) pin
  for(int i=0;i<LEDStripCount;i++)
  {
    LED[i].setOutput(outputPin);
  }
}

void loop()
{  
  Clear();
  //Ping Pong
  delayValue = 8;
  int i;
  for(i = 0; i < cycles[0]; i++)
  {
    Ping();
    Pong();
  }
  //Traverse
  delayValue = 12;
  for(i = 0; i < cycles[1]; i++)
  {
    TraverseColors();
  }
  //Dots
  Clear();
  Dots();
  //Slow Traverse
  Clear();
  delayValue = 8;
  for(int i = 0; i < cycles[2]; i++)
  {
    SlowTraverse(4,3,BaseColor());
  }
  //Hue Change
  delayValue = 85;
  for(int i = 0; i < cycles[3]; i++)
  {
    HueChange();
  }
}

/***** Base Functions *****/

void SetColorAtIndex(int index, cRGB color)
{
  for(int i=0;i<LEDStripCount;i++)
  {
    LED[i].set_crgb_at(index,color);
  }
}

void SetColorAtIndexIndividual(int index, cRGB color,int LEDIndex)
{
  LED[LEDIndex].set_crgb_at(index,color);
}

void Sync()
{
  for(int i=0;i<LEDStripCount;i++)
  {
    LED[i].sync();
  }
}

void Clear()
{
  for(int i = 0; i < LEDCount; i++)
  {
    SetColorAtIndex(i,Blank());
  }    
  Sync();
}

/***** Slow Traverse *****/

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
  LightUp(j,LEDCount,color);
}

void LightUp(int startIndex, int endIndex, cRGB color)
{
  for(int i = startIndex; i <= endIndex; i++)
  {
    SetColorAtIndex(i,color);
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

/***** Dots *****/

void Dots()
{
  //Phase 1 dots
  delayValue=15;
  DotsPhaseOne(BaseColor());
  //Phase 2 move dots
  delayValue = 75;
  DotsPhaseTwo(100,BaseColor());
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

/***** Ping Pong *****/

void Ping()
{
  cRGB color = BaseColor();
  for(int i = 0; i < LEDCount; i++)
  {
    for(int b = 0; b < ballSize; b++)
    {
      SetColorAtIndex(i+b,color);
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
  cRGB color = BaseColor();
  for(int i = LEDCount; i > 0; i--)
  {
    for(int b = 0; b < ballSize; b++)
    {
      SetColorAtIndex(i-b,color);
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


/***** Traverse *****/

void Traverse(cRGB color)
{
  for(int i = 0; i < LEDCount; i++)
  {
    SetColorAtIndex(i,color);
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

/***** Hue Change *****/

void HueChange()
{
  Cycle();
  for(int i = 0; i < LEDCount; i++)
  {
    SetColorAtIndex(i,hueColor);
  }
  Sync();
  delay(delayValue);
}

void Cycle()
{
  byte steps = 15; //number of hues we skip in a 360 range per update
  
  //Hue, Saturation and Value (Brightness)
  hueColor.SetHSV(hue, 255, 127);
  
  hue += steps;
  if(hue > 360)
  {
      hue %= 360;
  }
}
