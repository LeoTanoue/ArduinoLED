#include <WS2812.h>

cRGB GetColor(int r, int g, int b)
{
  cRGB value;
  value.r = r;
  value.g = g;
  value.b = b;
  return value;
}

cRGB Red()
{
  return GetColor(255,0,0);
}

cRGB Green()
{
  return GetColor(0,255,0);
}

cRGB Blue()
{
  return GetColor(0,0,255);
}

cRGB Blank()
{
  return GetColor(0,0,0);
}

cRGB White()
{
  return GetColor(255,255,255);
}

cRGB Gray()
{
  return GetColor(128,128,128);
}

cRGB Yellow()
{
  return GetColor(255,255,0);
}

cRGB Cyan()
{
  return GetColor(0,255,255);
}

cRGB Magenta()
{
  return GetColor(255,0,255);
}

int getRandomColors()
{
  return rand() % 256 + 1;
}

cRGB RandomColor()
{
  return GetColor(getRandomColors(),getRandomColors(),getRandomColors());
}
