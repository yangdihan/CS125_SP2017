/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include <utility>      // std::pair, std::make_pair
#include "maptiles.h"

using namespace std;

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage> const& theTiles)
{
    /**
     * @todo Implement this function!
     */
     // initialize a vector to hold the average value of the tileimages
    vector<Point<3>> TileImageAveragePoints;
    // also need a dictionary to know which tileImage to fetch
    std::map<Point<3>,TileImage> TileImageDecoder;
    // initialize vector
    for (size_t i = 0; i < theTiles.size(); i++)
    {
      // get the pixel from the tiles
      RGBAPixel average = theTiles[i].getAverageColor();
      // declare a Point to contain the r b g components of average
      Point<3> TileImageAverage;
      // initialize the r b g components of the TileImageAverage
      TileImageAverage[0] = average.red;
      TileImageAverage[1] = average.green;
      TileImageAverage[2] = average.blue;
      // now push the finished product on the production line
      TileImageAveragePoints.push_back(TileImageAverage);
      // time to insert into the dictionary as well
      //std::pair<Point<3>, TileImage> temp = make;
      TileImageDecoder[TileImageAverage] = theTiles[i];

    }

    //now we have a vector that contain the average color value of every TileImage
    // available to us
    // now we should create a kdtree to hold these value
    KDTree<3> TileImageAvgPointsTree = KDTree<3> (TileImageAveragePoints);
    // this will allow us to traverse the tree and find the most appropriate
    // images

    //now the next part
    // It creates a new dynamically allocated MosaicCanvas,
    // with the same number of rows and columns as the SourceImage,
    // and returns a pointer to this object.

    int rows = theSource.getRows();
    int cols = theSource.getColumns();
    // createthe MosaicCanvas
    MosaicCanvas* mosaic = new MosaicCanvas(rows, cols);

    // For every region in the SourceImage, mapTiles() should take the
    // TileImage with average color closest to the average color of
    // that region and place that TileImage into the MosaicCanvas in the
    // same tile position as the SourceImage’s region.

    // use a double forloop to initialize the MosaicCanvas
    for (int x = 0; x < rows; x++)
    {
        for (int y = 0; y < cols; y++)
        {
            // get the region color of the source image based on row and col number
            RGBAPixel regionColor = theSource.getRegionColor(x, y);
            // turn the region color into a Point<3>
            Point<3> target;
            target[0] = regionColor.red;
            target[1] = regionColor.green;
            target[2] = regionColor.blue;
            // find the color closest Point to this point in the KDTree
            Point<3> closestPoint =
            TileImageAvgPointsTree.findNearestNeighbor(target);
            // use the closest Point to find the TileImage in the dictionary
            TileImage closestImage = TileImageDecoder.at(closestPoint);

            mosaic->setTile(x, y, closestImage);

        }

    }
    // now return a pointer to MosaicCanvas mosiac
    return mosaic;


}
