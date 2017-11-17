#include <cstdint>
using std::uint8_t;
#ifndef RGBAPixel_H
#define RGBAPixel_H
// ... code goes here
class RGBAPixel 
{
public:
  RGBAPixel ();
  RGBAPixel (uint8_t red, uint8_t green, uint8_t blue);
	uint8_t red;
	uint8_t green;
	uint8_t blue;
	uint8_t alpha;
};
#endif