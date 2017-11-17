/**
 * @file main.cpp borrowned from lab_intro
 * A simple C++ program that manipulates an image.
 */
#include <algorithm>
#include <iostream>

#include "rgbapixel.h"
#include "png.h"

using namespace std;

/**
 * This function accepts a PNG object, two integer coordinates and a color, and
 * proceeds to draw a horizontal line across the image at the y coordinate and
 * a vertical line down the image at the x coordinage using the given color.
 * The modified PNG is then returned.
 *
 * @param original A PNG object which holds the image data to be modified.
 * @param centerX The center x coordinate of the crosshair which is to be drawn.
 * @param centerY The center y coordinate of the crosshair which is to be drawn.
 * @param color The color of the lines to be drawn.
 *
 * @return The image on which a crosshair has been drawn.
 */
PNG rotate(PNG original)
{
    /// This function is already written for you so you can see how to
    /// interact with our PNG class.
    // make the PNG meant to be returned
    size_t w = original.width();
    size_t h = original.height();
    PNG ret = PNG (w, h);
    for (size_t x = 0; x < w; x++)
        {
        for (size_t y = 0; y < h; y++) 
            {
                ret(w-1-x,h-1-y)->red = original(x, y)-> red;
                ret(w-1-x,h-1-y)->blue = original(x, y)-> blue;
                ret(w-1-x,h-1-y)->green = original(x, y)-> green;
            }
        
        }
    return ret;
}

/**
 * This function brightens a rectangle of a PNG, increasing the components
 * (red, green, blue) of each pixel by the given amount. You must account
 * for potential overflow issues (color components can only store numbers
 * between 0 and 255). If you attempt to store a value greater than 255
 * into a color component, the result will wrap around (and you won't be
 * able to check if it was greater than 255).
 *
 * @param original A PNG object which holds the image data to be modified.
 * @param amount The integer amount by which to increase each pixel's
 * components.
 *
 * @return The brightened image.
 */
PNG brighten(PNG original, int amount)
{
    /// You can assume amount is positive.
    for (size_t yi = 0; yi < original.height(); yi++) {
        for (size_t xi = 0; xi < original.width(); xi++) {
            /// Your code here!
            //check for overflow of red 
            if (((original(xi,yi)->red) + amount) > 255)
                original(xi, yi)-> red = 255;
            else
                original(xi, yi)-> red += amount;

            //check for overflow of blue 
            if (((original(xi,yi)->blue) + amount) > 255)
                original(xi, yi)-> blue = 255;
            else
                original(xi, yi)-> blue += amount;
            //check for overflow of green 
            if (((original(xi,yi)->green) + amount) > 255)
                original(xi, yi)-> green = 255;
            else
                original(xi, yi)-> green += amount;
        }
    }
    return original;
}

/**
 * This function blends, or averages, two PNGs together. That is, each pixel in
 * the returned image consists of the averaged components (red, green, blue) of
 * the two input images.
 *
 * @param firstImage  The first of the two PNGs to be averaged together.
 * @param secondImage The second of the two PNGs to be averaged together.
 *
 * @return The averaged image.
 */
PNG blendImages(PNG firstImage, PNG secondImage)
{
    /// Your code here!
    for (size_t x = 0; x < firstImage.width(); x++)
   {
      for (size_t y = 0; y < firstImage.height(); y++)
      {
         firstImage(x, y)->red = (firstImage(x, y)->red + secondImage(x, y)->red)/2;
         firstImage(x, y)->blue = (firstImage(x, y)->blue + secondImage(x, y)->blue)/2;
         firstImage(x, y)->green = (firstImage(x, y)->green + secondImage(x, y)->green)/2;
      }
   }
    return firstImage;
}

/**
 * The main function in this program (the starting point of the execution of our
 * code).
 *
 * @return An integer indicating whether execution was successful.
 */
int main()
{
    // Open a new PNG image from the file sample.png.
    // modified to open in_01.png
    PNG image1("in.png");
    // rotate image.
    PNG rotated = rotate(image1);

    /*// Blend sample.png and overlay.png together.
    image = blendImages(image, overlay);

    // Create a new RGBAPixel color for drawCrosshairs which is cyan.
    RGBAPixel cyanColor;
    cyanColor.red = 0;
    cyanColor.green = 255;
    cyanColor.blue = 255;

    // Draw two crosshairs on the image.
    image = drawCrosshairs(image, 400, 330, cyanColor);
    image = drawCrosshairs(image, 620, 424, cyanColor);
    */
    // Save the modified image to a file called output.png, overwriting the file
    // if it already exists.
    rotated.writeToFile("out.png");

    return 0;
}
