#include <LEDColors.h>

#define outputPin 9  // Digital output pin (default: 9)
#define LEDCount 60   // Number of LEDs to drive (default: 9)

//List of LED's
WS2812 LED(LEDCount);

void setup()
{
  delay(2000);
  LED.setOutput(outputPin); // Digital Pin 9
}

void loop() 
{
  RotateColor(White());
  RotateColor(Red());
  RotateColor(Green());
  RotateColor(Blue());
  RotateColor(Gray());
  RotateColor(Yellow());
  RotateColor(Cyan());
  RotateColor(Magenta());
  RotateColor(RandomColor());
}

void RotateColor(cRGB value)
{
  int i;
  for(i = 0; i < LEDCount; i++)
  {
      LED.set_crgb_at(i, value);
  }
  LED.sync(); // Sends the data to the LEDs
  delay(1000); // Wait (ms)
}
