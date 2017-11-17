#include <stdlib.h>
#include <math.h>
#include "gradientColorPicker.h"
#include <stdlib.h> 

/**
 * Constructs a new gradientColorPicker.
 *
 * @param fadeColor1 The first color to start the gradient at.
 * @param fadeColor2 The second color to end the gradient with.
 * @param rad How quickly to transition to fadeColor2.
 * @param centerX X coordinate for the center of the gradient.
 * @param centerY Y coordinate for the center of the gradient.
 */
gradientColorPicker::gradientColorPicker(RGBAPixel fadeColor1,
                                         RGBAPixel fadeColor2, int radius,
                                         int centerX, int centerY)
{
    /**
     * @todo Construct your gradientColorPicker here! You may find it
     *	helpful to create additional member variables to store things.
     */
     color1 = fadeColor1;
     color2 = fadeColor2;
     rad = radius;
     xCoord = centerX;
     yCoord = centerY;
}

/**
 * Picks the color for pixel (x, y).
 *
 * The first color fades into the second color as you move from the initial
 * fill point, the center, to the rad. Beyond the rad, all pixels
 * should be just color2.
 *
 * You should calculate the distance between two points using the standard
 * Manhattan distance formula,
 *
 * \f$d = |center\_x - given\_x| + |center\_y - given\_y|\f$
 *
 * Then, scale each of the three channels (R, G, and B) from fadeColor1 to
 * fadeColor2 linearly from d = 0 to d = rad.
 *
 * For example, the red color at distance d where d is less than the rad
 * must be
 *
 * \f$ redFill = fadeColor1.red - \left\lfloor
   \frac{d*fadeColor1.red}{rad}\right\rfloor +
   \left\lfloor\frac{d*fadeColor2.red}{rad}\right\rfloor\f$
 *
 * Note that all values are integers. If you do not follow this formula,
 * your colors may be very close but round differently than ours.
 *
 * @param x The x coordinate to pick a color for.
 * @param y The y coordinate to pick a color for.
 * @return The color selected for (x, y).
 */
RGBAPixel gradientColorPicker::operator()(int x, int y)
{
   
    /**
     * @todo Return the correct color here!
     */
    int d = abs(xCoord-x) + abs(yCoord-y);
    if (d >= rad)
    return color2;

    RGBAPixel ret;
    ret.red = color1.red - floor(d*color1.red/rad) + floor(d*color2.red/rad);
    ret.green = color1.green - floor(d*color1.green/rad) + floor(d*color2.green/rad);
    ret.blue = color1.blue - floor(d*color1.blue/rad) + floor(d*color2.blue/rad);
    return ret;
}
