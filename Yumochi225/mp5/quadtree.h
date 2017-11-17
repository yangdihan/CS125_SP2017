/**
 * @file quadtree.h
 * Quadtree class definition.
 * @date Spring 2008
 */

#ifndef QUADTREE_H
#define QUADTREE_H

#include "png.h"
#include <cmath>
#include <iostream>

/**
 * A tree structure that is used to compress PNG images.
 */
class Quadtree
{
  public:

    // default constructor
    /* The no parameters constructor takes no arguments, and produces an empty
    Quadtree object, i.e. one which has no associated QuadtreeNode objects,
    and in which root is NULL.*/
    Quadtree();

    // specific constructor
    /*
    This constructor's purpose is to build a Quadtree representing the
    upper-left d by d block of the source image.
    This effectively crops the source image into a d by d square.
    You may assume that d is a power of two, and that the width and
    height of source are each at least d.
    Perhaps, to implement this, you could leverage the functionality of
    another function you have written in 5.1...

    Parameters
    source	The source image to base this Quadtree on
    resolution	The width and height of the sides of the image to be
    represented
    */
    Quadtree(PNG const& source, int resolution);

    // copy constructor
    /*
    Copy constructor.
    Simply sets this Quadtree to be a copy of the parameter.

    Parameters
    other	The Quadtree to make a copy of

    */
    // Quadtree (Quadtree const &other)
    Quadtree(Quadtree const & other);

    // destructor
    ~Quadtree();

    // assignment operator
    /*
    Assignment operator; frees memory associated with this Quadtree and
    sets its contents to be equal to the parameter's.

    Parameters
    other	The Quadtree to make a copy of

    Returns
    A constant reference to the Quadtree value that was copied
    */
    Quadtree const& operator=(Quadtree const & other);

    // build a tree functions
    /*
    Deletes the current contents of this Quadtree object, then turns it into a
    Quadtree object representing the upper-left d by d block of source.
    You may assume that d is a power of two, and that the width and height
    of source are each at least d.

    Parameters
    source	The source image to base this Quadtree on
    resolution	The width and height of the sides of the image to be
    represented
    */
    void buildTree(PNG const& source, int resolution);

    // RGBAPixel getter
    /*
    Gets the RGBAPixel corresponding to the pixel at coordinates (x, y)
    in the bitmap image which the Quadtree represents.

    Note that the Quadtree may not contain a node specifically corresponding
    to this pixel (due, for instance, to pruning - see below). In this case,
    getPixel will retrieve the pixel (i.e. the color) of the square region
    within which the smaller query grid cell would lie. (That is, it will
    return the element of the nonexistent leaf's deepest surviving ancestor.)
    If the supplied coordinates fall outside of the bounds of the underlying
    bitmap, or if the current Quadtree is "empty" (i.e., it was created by
    the default constructor) then the returned RGBAPixel should be the one
    which is created by the default RGBAPixel constructor.

    Parameters
    x	The x coordinate of the pixel to be retrieved
    y	The y coordinate of the pixel to be retrieved

    Returns
    The pixel at the given (x, y) location
    */
    RGBAPixel getPixel(int x, int y) const;

    // decompress
    /*
    Returns the underlying PNG object represented by the Quadtree.

    If the current Quadtree is "empty" (i.e., it was created by the
    default constructor) then the returned PNG should be the one which is
    created by the default PNG constructor. This function effectively
    "decompresses" the Quadtree. A Quadtree object, in memory, may take up
    less space than the underlying bitmap image, but we cannot simply look at
    the Quadtree and tell what image it represents. By converting the Quadtree
    back into a bitmap image, we lose the compression, but gain the ability
    to view the image directly.

    Returns
    The decompressed PNG image this Quadtree represents
    */
    PNG decompress() const;

    /*
    Rotates the Quadtree object's underlying image clockwise by 90 degrees.

(Note that this should be done using pointer manipulation, not by attempting
to swap the element fields of QuadtreeNodes. Trust us; it's easier this way.)
    */
    void clockwiseRotate();

    /*
    Compresses the image this Quadtree represents.

    If the color values of the leaves of a subquadtree don't vary by much,
    we might as well represent the entire subtree by, say, the average color
    value of those leaves. We may use this information to effectively
    "compress" the image, by strategically trimming the Quadtree.

    Consider a node n and the subtree, Tn rooted at n, and let avg denote the
    component-wise average color value of all the leaves of Tn. Component-wise
    average means that every internal node in the tree calculates its value
    by averaging its immediate children. This implies that the average must
    be calculated in a "bottom-up" manner.

    Due to rounding errors, using the component-wise average is not
    equivalent to using the true average of all leaves in a subtree.
    If a node n is pruned, the children of n and the subtrees for which
    they are the roots are removed from the Quadtree. Node n is pruned if
    the color value of no leaf in Tn, differs from avg by more than
    tolerance.
    (Note: for all average calculations, just truncate the value to integer.)

    We define the "difference" between two colors, (r1,g1,b1) and (r2,g2,b2),
    to be (r2−r1)2+(g2−g1)2+(b2−b1)2.

    To be more complete, if the tolerance condition is met at a node n,
    then the block of the underlying image which n represents contains
    only pixels which are "nearly" the same color. For each such node n,
    we remove from the Quadtree all four children of n, and their
    respective subtrees (an operation we call a pruning). This means that
    all of the leaves that were deleted, corresponding to pixels whose colors
    were similar, are now replaced by a single leaf with color equal to
    the average color over that square region.

    The prune function, given a tolerance value, prunes the Quadtree
    as extensively as possible. (Note, however, that we do not want the
    prune function to do an "iterative" prune. It is conceivable that by
    pruning some mid-level node n, an ancestor p of n then becomes prunable,
    due to the fact that the prune changed the leaves descended from p.
    Your prune function should evaluate the prunability of each node based
    on the presence of all nodes, and then delete the subtrees based at
    nodes deemed prunable.)

    Note
    You should start pruning from the root of the Quadtree.

    Parameters
    tolerance	The integer tolerance between two nodes
    that determines whether the subtree can be pruned.
    */
    void prune(int tolerance);

    /*
    This function is similar to prune; however, it does not actually
    prune the Quadtree.

    Rather, it returns a count of the total number of leaves the
    Quadtree would have if it were pruned as in the prune function.

    Parameters
    tolerance	The integer tolerance between two nodes that determines
    whether the subtree can be pruned.

    Returns
    How many leaves this Quadtree would have if it were pruned
    with the given tolerance.
    */
    int pruneSize(int tolerance) const;

    /*
    Calculates and returns the minimum tolerance necessary to guarantee that
    upon pruning the tree, no more than numLeaves leaves remain in the Quadtree.

    Essentially, this function is an inverse of pruneSize; for any Quadtree
    object theTree, and for any positive integer tolerance it should be true
    that

     theTree.pruneSize(theTree.idealPrune(numLeaves)) <= numLeaves
    Once you understand what this function is supposed to do, you will
    probably notice that there is an "obvious" implementation. This is probably
    not the implementation you want to use! There is a fast way to implement
    this function, and a slow way; you will need to find the fast way.
    (If you doubt that it makes a significant difference, the tests in the
    given main.cpp should convince you.)

    Parameters
    numLeaves	The number of leaves you want to remain in the tree
    after prune is called.

    Returns
    The minimum tolerance needed to guarantee that there are no more than
    numLeaves remaining in the tree.
    Note
    The "obvious" implementation involves a sort of linear search over all
    possible tolerances. What if you tried a binary search instead?
    */
    int idealPrune(int numLeaves) const;


  private:
    class QuadtreeNode
    {
      public:
        QuadtreeNode* nwChild; /**< pointer to northwest child */
        QuadtreeNode* neChild; /**< pointer to northeast child */
        QuadtreeNode* swChild; /**< pointer to southwest child */
        QuadtreeNode* seChild; /**< pointer to southeast child */

        RGBAPixel element; /**< the pixel stored as this node's "data" */
        // saving the coordinate start point of each area
        // saving the dimension of the element
        int dimension;
        int xc;
        int yc;

        // create a new constructor to make our live easier during build a tree;
        QuadtreeNode(int newx, int newy, int newdimension)
        {
          // save the dimensional information for the new node
            xc = newx;
            yc = newy;
            dimension = newdimension;
          // take care of the child pointer
          // which I don't know what to put yet, so I will just make them NULL for now
          nwChild = NULL;
          neChild = NULL;
          swChild = NULL;
          seChild = NULL;
          // I also dont know what to put into the element, but I do know that
          // I should not put a legit pixel into the node unless it is a leaf
          // consider changing this
          //element = RGBAPixel(); //unnecessary
        }

        QuadtreeNode(QuadtreeNode* other)
        {
          xc = other->xc;
          yc = other->yc;
          dimension = other->dimension;
          // should jbool Quadtree::withInTolerance(QuadtreeNode *original, QuadtreeNode *rootPtr, int tolerance) constust copy since it it just int
          element = other->element;
          nwChild = NULL;
          neChild = NULL;
          swChild = NULL;
          seChild = NULL;
        }
    };

    QuadtreeNode* root; /**< pointer to root of quadtree */
    //helper function for buildTree
    void buildTree(QuadtreeNode * & subroot, int xc, int yc, int dimension, PNG const& source);
    //helper class for copy constructor
    void copy(QuadtreeNode* & subroot, QuadtreeNode* other);
    // delete helper
    void terminate (QuadtreeNode* & subroot);
    // getter helper
    RGBAPixel getPixel(QuadtreeNode* subroot, int x, int y) const;
    /**
     * A simple class representing a single node of a Quadtree.
     * You may want to add to this class; in particular, it could
     * probably use a constructor or two...
     */

    // helper function for rotateclockwise
    void clockwiseRotate(QuadtreeNode* &subroot);
    // helper function for prune
    void prune(QuadtreeNode* &subroot, int tolerance);
    bool rootvssubroot(RGBAPixel root, QuadtreeNode *rootPtr, int tolerance) const;
    int pruneSize(QuadtreeNode* subtroot, int tolerance) const;
    int countNodes(QuadtreeNode* subroot) const;
    // helper function for rotateclockwise
    //void clockwiseRotate(QuadtreeNode* &subroot);
    int idealPrune(int lowerbound, int upperbound, int numLeaves) const;


/**** Functions for testing/grading                      ****/
/**** Do not remove this line or copy its contents here! ****/
#include "quadtree_given.h"
};

#endif
