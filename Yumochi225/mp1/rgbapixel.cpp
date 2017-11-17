// rgbapixel.cpp
#include "rgbapixel.h"

  RGBAPixel::RGBAPixel()
  {
 		alpha = 255;
 		red = 255;
 		blue = 255;
 		green = 255;

  }

  RGBAPixel::RGBAPixel(uint8_t NewRed, uint8_t NewGreen, uint8_t NewBlue)
  {
  		alpha = 255;
 		red = NewRed;
 		blue = NewBlue;
 		green = NewGreen;
  }
