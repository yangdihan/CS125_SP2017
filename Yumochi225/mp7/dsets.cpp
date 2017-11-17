#include "dsets.h"
/* Your code here! */
void DisjointSets::addelements(int num)
{
  for (int i = 0; i < num; i++)
  {
    elems.push_back(-1);
  }
  //elems[num] = -1;
  return;
}

int DisjointSets::find (int elem)
{
  // so I have to find the set that the element is in
  // as well as change the parent to the set representative
  // if we are at the root/ ie the representative,
  // then just return
  if (elems[elem] < 0)
    return elem;

  return elems[elem] = find(elems[elem]);
}

bool DisjointSets::isBigger(int aRoot, int bRoot)
{
  // cout<<"aRoot Size: "<<elems[aRoot]<<endl;
  // cout<<"bRoot Size: "<<elems[bRoot]<<endl;
    return elems[aRoot] < elems[bRoot];
}

void DisjointSets::setunion(int a, int b)
{
  // union by size
  // first find the root of both elements
  int aRoot = find(a);
  int bRoot = find(b);
  // check if the two roots are the same
  if (aRoot == bRoot)
  {
    return;
  }
  // now we are sure that the two elements are from
  // different sets
  // create the newsize by summing the roots of the sets
  int newSize = elems[aRoot] + elems[bRoot];
  //cout<<"New Size: "<<newSize<<endl;

  if (isBigger(bRoot, aRoot))
  {
      elems[aRoot] = bRoot;
      elems[bRoot] = newSize;
  }

  else
  {
      elems[bRoot] = aRoot;
      elems[aRoot] = newSize;
  }

}
