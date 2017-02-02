#include <LEDColors.h>

#define outputPin 9     // Digital output pin (default: 9)
#define LEDCount 60     // Number of LEDs to drive (default: 9)
#define delayValue 30   // Delay value in milliseconds

//List of LED's
WS2812 LED(LEDCount); 
cRGB value;

void setup()
{
  delay(2000);
  LED.setOutput(outputPin); // Digital Pin 9
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
    LED.set_crgb_at(i,value);
    LED.sync();
    delay(delayValue);
  }
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

