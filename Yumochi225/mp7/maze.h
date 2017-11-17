/* Your code here! */
/*
yumo's little peace of mind here, dont know if this is enough to
keep me sane, but I think it will */

#ifndef MAZE
#define MAZE

#include <stdio.h>      /* printf, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <vector>
#include "png.h"
#include "dsets.h"
#include <queue>
#include <map>
#include <utility>      // std::pair, std::make_pair

using std::vector;
using namespace std;


class SquareMaze
{
  /*
  Each SquareMaze object represents a randomly-generated
  square maze and its solution.

  (Note that by "square maze" we mean a maze in which each
  cell is a square; the maze itself need not be a square.)
  */
  public:
    SquareMaze ();
    void makeMaze(int width, int height);
    ~SquareMaze();
    bool canTravel (int x, int y, int dir) const;
    void setWall (int x, int y, int dir, bool exist);
    vector <int> solveMaze();
    PNG* drawMaze() const;
    PNG* drawMazeWithSolution();
  private:
    class cell
    {
    public:
      bool rightwall;
      bool bottomwall;
      bool visited;
      int xcoor;
      int ycoor;
      int dist;
    };
      int w;
      int h;
      cell** maze;
      map <int, int> ChildParentDict;

      vector <int> adjCells(int x, int y);
      void clear();

};

#endif //
