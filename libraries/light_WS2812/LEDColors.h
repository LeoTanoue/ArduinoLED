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

cRGB Orange()
{
  return GetColor(255,165,0);
}

cRGB Purple()
{
  return GetColor(128,0,128);
}

int getRandomColors()
{
  return rand() % 256 + 1;
}

cRGB RandomColor()
{
  return GetColor(getRandomColors(),getRandomColors(),getRandomColors());
}

cRGB BaseColor()
{
  switch(rand() % 8 + 1)
  {
    case 1:
      return Red();
      break;
    case 2:
      return Green();
      break;
    case 3:
      return Blue();
      break;
    case 4:
      return Yellow();
      break;
    case 5:
      return Cyan();
      break;
    case 6:
      return Magenta();
      break;
    case 7:
      return Orange();
    case 8:
      return Purple();
    default:
      return Blue();
  }
}
