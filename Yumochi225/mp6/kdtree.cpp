/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
    // just exploring the three possiblities
    // if smaller
    if (first[curDim] < second[curDim])
    return true;
    // if larger
    if (first[curDim] > second[curDim])
    return false;
    // if equal use operator < to take care both possibilities
    else
    {
        if (first < second)
          return true;
        else
          return false;
    }
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
    double distPotential = 0.0;
    for (int i = 0; i < Dim; i++)
    {
        distPotential += (target[i] - potential[i]) * (target[i] - potential[i]);

    }

    double distCurrBest = 0.0;
    for (int j = 0; j < Dim; j++)
    {
        distCurrBest += (target[j] - currentBest[j]) * (target[j] - currentBest[j]);
    }


    if (distPotential == distCurrBest)
      return potential < currentBest;


    return (distPotential < distCurrBest);


}

// function partition(list, left, right, pivotIndex)
//      pivotValue := list[pivotIndex]
//      swap list[pivotIndex] and list[right]  // Move pivot to end
//      storeIndex := left
//      for i from left to right-1
//          if list[i] < pivotValue
//              swap list[storeIndex] and list[i]
//              increment storeIndex
//      swap list[right] and list[storeIndex]  // Move pivot to its final place
//      return storeIndex

template <int Dim>
void KDTree<Dim>::swap(Point<Dim>& first, Point<Dim>& second)
{
  Point <Dim> temp = first;
  first = second;
  second = temp;
}

template <int Dim>
int KDTree<Dim>::partition(int start, int end, int pivotIndex, int dimension)
{
    // just going to translate the wikipage
    Point <Dim> pivotValue = points[pivotIndex];
    swap(points[pivotIndex], points[end]);

    int storeIndex = start;
    for (int i = start; i < end; i ++)
    {
      if (smallerDimVal(points[i], pivotValue, dimension))
      {
        swap(points[storeIndex], points[i]);
        storeIndex++;
      }
    }
      swap(points[end], points[storeIndex]);

      return storeIndex;
}

// Returns the n-th smallest element of list within left..right inclusive
  // (i.e. left <= n <= right).
  // The search space within the array is changing for each round - but the list
  // is still the same size. Thus, n does not need to be updated with each round.
  // function select(list, left, right, n)
  //    if left = right        // If the list contains only one element,
  //        return list[left]  // return that element
  //    pivotIndex  := ...     // select a pivotIndex between left and right,
  //                           // e.g., left + floor(rand() % (right - left + 1))
  //    pivotIndex  := partition(list, left, right, pivotIndex)
  //    // The pivot is in its final sorted position
  //    if n = pivotIndex
  //        return list[n]
  //    else if n < pivotIndex
  //        return select(list, left, pivotIndex - 1, n)
  //    else
  //        return select(list, pivotIndex + 1, right, n)

template <int Dim>
void KDTree<Dim>::select( int start, int end, int n, int dimension)
{
      if (start == end)
      return;

      //int pivotIndex = (start + end-1)/2;

      int pivotIndex = partition( start, end, n, dimension);

      if (n == pivotIndex)
        return;
      else if (n < pivotIndex)
        select(start, pivotIndex - 1, n, dimension);
      else
        select(pivotIndex + 1, end, n, dimension);
}



template <int Dim>
void KDTree<Dim>::sort( int start, int end, int dimension)
{
  if (start >= end)
  {
    return;
  }
   int median = (start + end) / 2;
      select(start, end, median, dimension);
      sort(start, median - 1, (dimension+1)%Dim);
      sort(median + 1, end, (dimension+1)%Dim);

}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     // copy the vector over to
    // if (points == NULL)
    //  points = vector();

      // initialize the the vector
     points = newPoints;


     int start = 0;
     int end = newPoints.size() - 1;

    sort( start, end, 0);


}


template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */

     if (points.empty())
     return NULL;

    return findNearestNeighbor(0, points.size()-1, query, 0);
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(int start, int end, const Point<Dim>& query,
   int dimension) const
{
    /**
     * @todo Implement this function!
     */
     // find the smallest hyperrectangle by traveling to the leave of the tree
     int median = floor((start + end)/2);
     if (start >= end){
      //  if (shouldReplace(query, currentBest, points[median]))
          return points[median];
      // else return currentBest;
     }
     Point <Dim> currentBest;
     // decide which pathway to take
     bool left = true;
     if (smallerDimVal(query, points[median], dimension)){
      // cout<<points[median][0]<<endl;
      // cout<<points[median][1]<<endl;
        currentBest = findNearestNeighbor(start, median -1, query, (dimension+1)%Dim);
        left = true;
     }
    if (smallerDimVal(points[median], query, dimension)){
        currentBest = findNearestNeighbor(median + 1, end, query, (dimension+1)%Dim);
        left = false;
     }
     // if current node if closer than currentBest
     if (shouldReplace(query, currentBest, points[median])){
         currentBest = points[median];
     }
     // see if the dimensional distance between current node and query is inside the radius
     Point <Dim> temp;
     if (fabs(points[median][dimension] - query[dimension]) <= calDist(query, currentBest)){
        if (left)
          temp  = findNearestNeighbor(median + 1, end, query, (dimension+1)%Dim);
        else
          temp = findNearestNeighbor(start, median - 1, query, (dimension+1)%Dim);
     }
      if (shouldReplace(query, currentBest, temp))
          currentBest = temp;
    return currentBest;
}

template <int Dim>
int KDTree<Dim>::calDist(const Point<Dim>& first, const Point<Dim>& second) const
{
  double dist = 0.0;
  for (int i = 0; i < Dim; i++)
  {
      dist += (first[i] - second[i]) * (first[i] - second[i]);

  }
  return sqrt(dist);
}
