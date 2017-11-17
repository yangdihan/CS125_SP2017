/**
 * @file quadtree.cpp
 * Quadtree class implementation.
 * @date Spring 2008
 */

#include "quadtree.h"
 using namespace std;

Quadtree::Quadtree()
{
  // no associated QuadtreeNode obj
    //ele = RGBAPixel();
  root = NULL;
}

Quadtree::Quadtree(PNG const& source, int resolution)
{
  // create a new node
  // just initial idea
    //buildTree(root, source, resolution);

    // I should definitely recursively call build a tree on this
    // repeatedly

    //figure out a base case that is suitable for this quadtree
    // basically we should recurse until we are just looking at a group
    //of 4 nodes that make up a square
    // should just be 1 line
    root = NULL;

    // buildTree(root, 0, 0, resolution, source);
    buildTree(source, resolution);


}

Quadtree::Quadtree(Quadtree const & other)
{
  // if the other tree is NULL
  if (other.root == NULL)
  {
    root = NULL;
  }

  // else simply make copy of the node
  else
  {
    //make copy of the node
    copy(root, other.root);
  }
}

// copy helper
void Quadtree::copy(QuadtreeNode* & subroot, QuadtreeNode* other)
{
    // if empty
    if (other == NULL)
    {
      return;
    }

    subroot = new QuadtreeNode(other);
    copy(subroot->nwChild, other->nwChild);
    copy(subroot->neChild, other->neChild);
    copy(subroot->swChild, other->swChild);
    copy(subroot->seChild, other->seChild);

}

Quadtree::~Quadtree()
{
    terminate(root);
}

void Quadtree::terminate(QuadtreeNode* & subroot)
{
  // base case
    if (subroot == NULL)
    {
      return;
    }

    // just use a post order traversal to clear and deleter the tree
    terminate(subroot->nwChild);
    terminate(subroot->neChild);
    terminate(subroot->swChild);
    terminate(subroot->seChild);

    // takecare of the node now
    delete subroot;
    // set to NULL
    subroot = NULL;
    return;

}
Quadtree const & Quadtree::operator= (Quadtree const & other)
{
	// set condition against self assignment}

	if (other.root != root)
	{
		// create a temporary holder of tree
	terminate(root);

	// copy the nodes in the tree recursively
	copy(root, other.root);
	return *this;
	}
	else
	{
		return other;
	}
}

void Quadtree::buildTree(PNG const& source, int resolution)
  {
    // /////////////insert code////Helper////////
    // // that means that the dimension of png being examined is

    // need a wrapper function
     if (root != NULL)
     terminate(root);

     //root = new QuadtreeNode(0, 0, resolution);
     //root = new QuadtreeNode(0,0, resolution);
     buildTree(root, 0, 0, resolution, source);


  	// build the tree recursively with buildHelper
  }

  // create a wrapper function that can help to work through
  // the Quadtree
void Quadtree::buildTree(QuadtreeNode* & subroot, int xc, int yc,
  int dimension, PNG const& source)
{
  // if the dimension of the portion of the PNG being examined is
     // smaller than a 4 piece square
     //////////////////////changed///////////////////////////
    if (dimension == 1)
    {
      // now that we are dealing with the minimum square
      // just make the children
      //  take care of the root
      subroot = new QuadtreeNode(xc, yc, dimension);
      subroot->element = *(source(xc, yc));
       // root->nwChild = new QuadtreeNode(xc, yc, 1);
       // // take advantage of PNG's pixel return ability as well as
       // // pixel's int based memeber variables, which can be easily
       // // copied with the default copy constructor
       // root->nwChild->element = *source(xc, yc);
       // // repeat the same process for all other children
       // root->neChild = new QuadtreeNode(xc+1, yc, 1);
       // root->neChild->element = *source(xc+1, yc);
       // root->swChild = new QuadtreeNode(xc, yc+1, 1);
       // root->swChild->element = *source(xc, yc+1);
       // root->seChild = new QuadtreeNode(xc+1, yc+1, 1);
       // root->seChild->element = *source(xc+1, yc+1);
       return;

    }
   // if the square is no minimum, just recursively go near the minimum

   else
   {
     subroot = new QuadtreeNode(xc, yc, dimension);
     buildTree(subroot->nwChild, xc, yc, dimension/2, source);
     buildTree(subroot->neChild, xc+dimension/2, yc, dimension/2, source);
     buildTree(subroot->swChild, xc, yc+dimension/2, dimension/2, source);
     buildTree(subroot->seChild, xc+dimension/2, yc+dimension/2, dimension/2, source);

     subroot->element.red = (subroot->nwChild->element.red + subroot->neChild->element.red +
			 subroot->swChild->element.red + subroot->seChild->element.red)/4;
     subroot->element.blue = (subroot->nwChild->element.blue + subroot->neChild->element.blue +
			 subroot->swChild->element.blue + subroot->seChild->element.blue)/4;
     subroot->element.green = (subroot->nwChild->element.green + subroot->neChild->element.green +
			 subroot->swChild->element.green + subroot->seChild->element.green)/4;
  }
  // test for condition where resolution is just a single space
}

RGBAPixel Quadtree::getPixel(int x, int y) const
{
    /////////////insert code////////////
    return getPixel(root, x, y);
}

RGBAPixel Quadtree::getPixel(QuadtreeNode* subroot, int x, int y) const
{
  // base case
  if (subroot == NULL)
  {
    return RGBAPixel();
  }

  // if at the leave then just return
  if (subroot->seChild == NULL || subroot->swChild == NULL || subroot->nwChild == NULL
    || subroot->neChild == NULL)
	{
		return subroot->element;
	}

    // if (x <= subroot->dimension/2 && y <= subroot->dimension/2)
    // {
    //   if (subroot->nwChild != NULL)
    //   getPixel(subroot->nwChild, x, y);
    //   else
    //   return subroot->element;| subroot->nwChild == NULL
    // }
    // if (x > subroot->dimension/2 && y <= subroot->dimension/2)
    // {
    //   if (subroot->neChild != NULL)
    //   getPixel(subroot->neChild, x, y);
    //   else
    //   return subroot->element;
    // }
    // if (x <= subroot->dimension/2 && y > subroot->dimension/2)
    // {
    //   if (subroot->swChild != NULL)|| subroot->nwChild == NULL
    //   getPixel(subroot->swChild, x, y);
    //   else
    //   return subroot->element;
    // }
    //
    //   if (subroot->seChild != NULL)
    //   getPixel(subroot->seChild, x, y);
    //
    //
    //   return subroot->element;
    if (x >= subroot->nwChild->xc && x< (subroot->nwChild->xc + subroot->nwChild->dimension)
    && y >= subroot->nwChild->yc && y < (subroot->nwChild->yc + subroot->nwChild->dimension))

		{
      return getPixel(subroot->nwChild, x, y);
    }

	else if (x >= subroot->neChild->xc && x< (subroot->neChild->xc + subroot->neChild->dimension)
  && y >= subroot->neChild->yc && y < (subroot->neChild->yc + subroot->neChild->dimension))

  {
    return getPixel(subroot->neChild, x, y);
  }
	else if (x >= subroot->swChild->xc && x< (subroot->swChild->xc + subroot->swChild->dimension)
  && y >= subroot->swChild->yc && y < (subroot->swChild->yc + subroot->swChild->dimension))

  {
    return getPixel(subroot->swChild, x, y);
  }
	else
	{
		return getPixel(subroot->seChild, x, y);
	}

}

PNG Quadtree::decompress()const
{
  /////////////insert code////////////
  if (root == NULL)
  return PNG();

    PNG ret(root->dimension, root->dimension);
    for (int i = 0; i < root->dimension; i++)
    {
      for (int j = 0; j < root->dimension; j++)
        *(ret(i,j)) = getPixel(i,j);
    }
    return ret;
}

void Quadtree::clockwiseRotate()
{
  /////////////insert code////////////
  if (root == NULL)
  return;

  if (root != NULL)
    {clockwiseRotate(root);}
  return;
}

// rotate helper
void Quadtree::clockwiseRotate(QuadtreeNode* & subroot)
{
  // if empty tree
  if (subroot == NULL)
  return;
  // base case, if we are at a leave node
  if (subroot->nwChild == NULL)
    return;
  // else then we are in the root or internal node

  // save the nwChild's info
  //int tempx = subroot->nwChild->xc;
  //int tempy = subroot->nwChild->yc;
  QuadtreeNode* temp = subroot->nwChild;
  // switch the position of the children and they xy coordinates

  // now switch the children
  subroot->nwChild = subroot->swChild;
  subroot->swChild = subroot->seChild;
  subroot->seChild = subroot->neChild;
  subroot->neChild = temp;

  // switch their xy coordi| subroot->nwChild == NULLnates first
  subroot->nwChild->xc = subroot->xc;
  subroot->nwChild->yc = subroot->yc;
  subroot->neChild->xc = subroot->xc + subroot->dimension/2;
  subroot->neChild->yc = subroot->yc;
  subroot->seChild->xc = subroot->xc + subroot->dimension/2;
  subroot->seChild->yc = subroot->yc + subroot->dimension/2;
  subroot->swChild->xc = subroot->xc;
  subroot->swChild->yc = subroot->yc + subroot->dimension/2;
  // then keep traversing the tree
  clockwiseRotate(subroot->nwChild);
  clockwiseRotate(subroot->neChild);
  clockwiseRotate(subroot->swChild);
  clockwiseRotate(subroot->seChild);




  return;
}

void Quadtree::prune(int tolerance)
{
  /////////////insert code////////////
    // if empty tree
    if ( root == NULL)
    return;

    // call a prune helper function
    prune(root, tolerance);
    return;

}

// // prune helper function
void Quadtree::prune(QuadtreeNode* &subroot, int tolerance)
{
  // base case for the subroot
  // empty tree
  if (subroot == NULL)
  {
    return;
  }
  if (subroot->nwChild == NULL)
  {
    return;
  }

  // int rnw = subroot->element.red - subroot->nwChild->element.red;
  // int bnw = subroot->element.blue - subroot->nwChild->element.blue;
  // int gnw = subroot->element.green - subroot->nwChild->element.green;

  // see if the difference for all children are within tolerance
  if (rootvssubroot(subroot->element, subroot, tolerance))
  {
       terminate(subroot->nwChild);
       terminate(subroot->neChild);
       terminate(subroot->swChild);
       terminate(subroot->seChild);

       // to be safe
       subroot->nwChild = NULL;
       subroot->neChild = NULL;
       subroot->swChild = NULL;
       subroot->seChild = NULL;
      return;
  }

  //recursively call prune on the children (pre order)
  prune(subroot->nwChild, tolerance);
  prune(subroot->neChild, tolerance);
  prune(subroot->swChild, tolerance);
  prune(subroot->seChild, tolerance);

//   // remember this is meant to be a top down process
// //  if ()
   return;
}

bool Quadtree::rootvssubroot(RGBAPixel root, QuadtreeNode* subroot,int tolerance) const
{

	// declare a bool to return
	bool ret = true;
	// base case, if we are at a root
	if (subroot->nwChild == NULL)
	{
		 int r = root.red - subroot->element.red;
 		 int b = root.blue - subroot->element.blue;
 		 int g = root.green - subroot->element.green;

 		 // calculate differences by squaring the differences
          	 r = r * r;
            	 b = b * b;
              	 g = g * g;

		ret = ret && ((r + b + g) <= tolerance);
		return ret;
	}

	return (ret&& rootvssubroot(root, subroot->nwChild, tolerance) && rootvssubroot(root, subroot->neChild, tolerance) &&
		rootvssubroot(root, subroot->swChild, tolerance) && rootvssubroot(root, subroot->seChild, tolerance));

}



int Quadtree::pruneSize(int tolerance) const
{
  /////////////insert code////////////
  	// empty tree
	 if (root == NULL)
	 return 0;

	return pruneSize(root, tolerance);
}

// prune helper function
int Quadtree::pruneSize(QuadtreeNode* subroot, int tolerance) const
{
   // base case for the subroot
   // empty tree
   	if (subroot == NULL)
   	{
          return 0;
   	}

    if (subroot->nwChild == NULL)
    {
          return 1;
    }

    if (rootvssubroot(subroot->element, subroot, tolerance))
    {
        	return 1;

    }

    //recursively call prune on the children (pre order)
  return  pruneSize(subroot->nwChild, tolerance) +
  pruneSize(subroot->neChild, tolerance) +
  pruneSize(subroot->swChild, tolerance) +
  pruneSize(subroot->seChild, tolerance);

  // remember this is meant to be a top down process
}

// int Quadtree::countNodes(QuadtreeNode* subroot) const
// {
//   //cout<<"enter count nodes"<<endl;
// 	if (subroot == NULL)
// 		return 0;
//
// 	if (subroot->nwChild == NULL)
// 		return 1;
//
//     // just use a post order traversal to clear and deleter the tree
//  	return countNodes(subroot->nwChild) +  countNodes(subroot->neChild) +
// 		 countNodes(subroot->swChild) + countNodes(subroot->seChild) + 1;
//
// }


int Quadtree::idealPrune(int numLeaves) const
{
  if (root == NULL)
  {
    return -1;
  }
  int guess = 2147483647;
  return idealPrune(0, guess, numLeaves);
  /////////////insert code////////////

}

int Quadtree::idealPrune(int lowerbound, int upperbound, int numLeaves) const
{
  int median;
    if (lowerbound >= upperbound)
      {
        return lowerbound;
      }

    //start in the middle because would will have less leafs to go through

      median = (lowerbound + upperbound)/2;

      if (numLeaves > pruneSize(median))
      {
        return idealPrune(lowerbound, median-1, numLeaves);
      }

      if (numLeaves < pruneSize(median))
      {
        return idealPrune(median+1, upperbound, numLeaves);
      }

      else // this is when we know the leave and pruneSize is equal
      {
        // shave down the number of leaves
        while (numLeaves == pruneSize(median))
          median--;
        return median + 1;
      }
}
