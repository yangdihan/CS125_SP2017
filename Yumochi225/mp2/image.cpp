#include "image.h"

void Image::flipleft()
{	
	size_t width = this->width();
	size_t height = this->height();
	RGBAPixel temp;
	// go through have of width
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width/2; x++)
		{
			// change red component
			temp.red = (*this)(x,y)->red;
			(*this)(x,y)->red = (*this)(width-x-1,y)->red;
			(*this)(width-x-1,y)->red = temp.red;

			temp.blue = (*this)(x,y)->blue;
			(*this)(x,y)->blue = (*this)(width-x-1,y)->blue;
			(*this)(width-x-1,y)->blue = temp.blue;

			temp.green = (*this)(x,y)->green;
			(*this)(x,y)->green = (*this)(width-x-1,y)->green;
			(*this)(width-x-1,y)->green = temp.green;

		}
	}
	return;
}

void Image::adjustbrightness(int r, int g, int b)
{
	size_t width = this->width();
	size_t height = this->height();
	// systematically cycle through coordinates
	for (size_t y = 0; y < height; y++)
	{
		for (size_t x = 0; x < width; x++)
		{
			// overflow prevention
			// smaller than 0
			if ( (*this)(x,y)->red + r < 0)
			{	
				(*this)(x,y)->red = 0;
			}
			// larger than 255
			else 
			if ((*this)(x,y)->red + r >= 255)
			{ 
				(*this)(x,y)->red = 255;
			}
			else 
			{
				(*this)(x,y)-> red += r;
			}
			// blue
			if ((*this)(x,y)->blue + b< 0)
			{
				(*this)(x,y)->blue = 0;
			}
			else 
			if ((*this)(x,y)->blue + b >= 255)
			{
				(*this)(x,y)->blue = 255;
			} 
			else 
			{
				(*this)(x,y)->blue += b;
			}
			// green
			if ((*this)(x,y)->green + g < 0)
			{
				(*this)(x,y)->green = 0;
			}
			else 
			if ((*this)(x,y)->green + g >= 255)
			{
				(*this)(x,y)->green = 255;
			}
			else 
			{
				(*this)(x,y)->green += g;
			}



		}
	}
	return;
}

void Image::invertcolors()
{
	size_t height = this->height();
	size_t width = this->width();

	for (size_t x = 0; x < width; x++)
	{
		for (size_t y = 0; y < height; y++)
		{
			(*this)(x,y)->red = 255 - (*this)(x,y)->red;
			(*this)(x,y)->blue = 255 - (*this)(x,y)->blue;
			(*this)(x,y)->green = 255 - (*this)(x,y)->green;
		} 
	}
	return;
}