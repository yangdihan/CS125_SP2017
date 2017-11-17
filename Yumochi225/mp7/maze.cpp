/* Your code here! */
#include "maze.h"

/*
    No-parameter construction
    Creates and empty maze
*/
SquareMaze::SquareMaze()
{
    maze = NULL;
}
/*
    Makes a new SquareMaze of the given height and width.

    If this object already represents a maze it will clear
    all the existing data before doing so. You will start
    with a square grid (like graph paper) with the
    specified height and width. You will select random
    walls to delete without creating a cycle, until there
    are no more walls that could be deleted without
    creating a cycle. Do not delete walls on the perimeter
    of the grid.

    Hints: You only need to store 2 bits per square: the
    "down" and "right" walls. The finished maze is always a
    tree of corridors.)

    Parameters
    width	The width of the SquareMaze (number of cells)
    height	The height of the SquareMaze (number of cells)

*/
void SquareMaze::makeMaze(int width, int height)
{
  // if the object already represents a maze
  if (maze != NULL)
  {
    // then delete the maze
    clear();
  }

    // set width and height
    w = width;
    h = height;

    // initialize the maze`
    maze = new cell* [width];

    for (int i = 0; i < width; i++)
    {
        maze[i] = new cell [height];
        for (int j = 0; j < height; j++ )
        {
          maze[i][j].xcoor = i;
          maze[i][j].ycoor = j;
          maze[i][j].rightwall = true;
          maze[i][j].bottomwall = true;
          maze[i][j].visited = false;
          maze[i][j].dist = -1;
        }
    }
    DisjointSets edges;
    edges.addelements(w*h);
    int cellsaccessed = 0;
    // set up the random process
    srand (time(NULL));

    // randomize the chance to pick height
    while (cellsaccessed != (w*h - 1)){
    int cellheight = rand()%height;
    // randomize the chance to pick width
    int cellwidth = rand()%width;
    // randomize the chance to change botwall
    bool changebotwall = rand()%2;
    // width is not restricted


    if (changebotwall)
    {
        if (cellheight < (h - 1))
        {

          int a = (cellwidth * h) + cellheight;
          int b = a+1;
            if (edges.find(a) != edges.find(b))
            {
              // not in the same set
              maze[cellwidth][cellheight].bottomwall = false;
              edges.setunion(a, b);
              cellsaccessed++;
            }

        }
    }

    else
    {
      if (cellwidth < (w-1))
      {
      int a = (cellwidth * h) + cellheight;
      int b = ((cellwidth+1) * h) + cellheight;
          if (edges.find(a) != edges.find(b))
          {
            // not in the same set
            maze[cellwidth][cellheight].rightwall = false;
            edges.setunion(a, b);
            cellsaccessed++;
          }
        }
      }
    }


}

/*
This uses your representation of the maze to determine
whether it is possible to travel in the given direction
from the square at coordinates (x,y).

For example, after makeMaze(2,2), the possible input
coordinates will be (0,0), (0,1), (1,0), and (1,1).

dir = 0 represents a rightward step (+1 to the x
coordinate)
dir = 1 represents a downward step (+1 to the y
coordinate)
dir = 2 represents a leftward step (-1 to the x
coordinate)
dir = 3 represents an upward step (-1 to the y
coordinate)
You can not step off of the maze or through a wall.

This function will be very helpful in solving the maze.
It will also be used by the grading program to verify
that your maze is a tree that occupies the whole grid,
and to verify your maze solution. So make sure that this
function works!

Parameters
x	The x coordinate of the current cell
y	The y coordinate of the current cell
dir	The desired direction to move from the current cell
Returns
whether you can travel in the specified direction
*/

bool SquareMaze::canTravel(int x, int y, int dir)	const
{
  switch(dir)
  {
  case 0:
	{
		if ((x + 1) <= w && !(maze[x][y].rightwall))
    {
			return true;
    }
		else
			return false;
	}
	case 1:
	{
    if ((y + 1) <= h && !(maze[x][y].bottomwall))
    {
			return true;
    }
		else
			return false;
	}
	case 2:
	{
    if ((x - 1) >= 0 && !(maze[x-1][y].rightwall))
    {
			return true;
    }
		else
			return false;
	}
	case 3:
	{
    if ((y - 1) >= 0 && !(maze[x][y-1].bottomwall))
    {
			return true;
    }
		else
			return false;
	}
	default:
		return false;
  }


}

/*
  Sets whether or not the specified wall exists.

  This function should be fast (constant time).
  You can assume that in grading we will not make your
  maze a non-tree and then call one of the other member
  functions. setWall should noll call setWall to copy a
  specific maze into your implementation.

  Parameters
  x	The x coordinate of the current cell
  y	The y coordinate of the current cell
  dir	Either 0 (right) or 1 (down), which specifies which
  wall to set (same as the encoding explained in canTravel).
  You only need to support setting the bottom and right
  walls of every square in the grid.
  exists	true if setting the wall to exist, false
  otherwise
*/

void SquareMaze::setWall(int x, int y, int dir, bool exists)
{
  if (dir == 0)
    maze[x][y].rightwall = exists;

    else
      maze[x][y].bottomwall = exists;
}

/*
  Solves this SquareMaze.

  For each square on the bottom row (maximum y coordinate),
  there is a distance from the origin (i.e. the top-left
  cell), which is defined as the length (measured as a
  number of steps) of the only path through the maze from
  the origin to that square.

  Select the square in the bottom row with the largest
  distance from the origin as the destination of the
  maze. solveMaze() returns the winning path from the
  origin to the destination as a vector of integers,
  where each integer represents the direction of a step,
  using the same encoding as in canTravel().

  If multiple paths of maximum length exist, use the one
  with the destination cell that has the smallest x value.

  Hint: this function should run in time linear in the
  number of cells in the maze.

  Returns
  a vector of directions taken to solve the maze
*/

vector<int> SquareMaze::solveMaze()
{
    vector <int> ret;
    queue <int> cellsTraveledx;
    queue <int> cellsTraveledy;

    // I plan to use a dictionary to keep track of child and parent relationship
    // the only real problem is the coordinate arithmatic
    // map <int, int> ChildParentDict;

    // make everything a
    cell *start = &(maze[0][0]);

    // make start visted and push on to queue to perform queue
    start->visited = true;
    start->dist = 0;
    cellsTraveledx.push(start->xcoor);
    cellsTraveledy.push(start->ycoor);

    while(!cellsTraveledx.empty())
    {

      int currx= cellsTraveledx.front();
      int curry= cellsTraveledy.front();
      cellsTraveledx.pop();
      cellsTraveledy.pop();
      // get all adjcent
      vector <int>  adjs = adjCells(currx, curry);
      for (size_t i = 0; i < adjs.size(); i++)
      {
        int x = adjs[i]%h;
        int y = adjs[i]/h;

          if ((maze[x][y]).dist == -1)
          {
            // if undiscovered
            // mark the tile as visited and update its distance
            // I just realized I dont need to use visited
            (maze[x][y]).dist = (maze[currx][curry]).dist + 1;
            (maze[x][y]).visited = true;
            // enqueue the current cell being examined
            //
            cellsTraveledx.push(x);
            cellsTraveledy.push(y);
            // establish association between child to parent
            // convert parent (curr) to an integer
            int parent = curry*h + currx;
            ChildParentDict[adjs[i]] = parent;

          }
      }

    }

    // now time to cycle through the bottom row to find the best dest
    cell dest = maze[0][h-1];
    for (int i = 0; i < w; i++)
    {
        if (maze[i][h-1].dist > dest.dist)
          {
            dest = maze[i][h-1];
          }
        else if (maze[i][h-1].dist == dest.dist)
        {
          if (maze[i][h-1].xcoor < dest.xcoor)
          {
            dest = maze[i][h-1];
          }
        }
    }

    // s0 now we have our start and end;

    int search = dest.xcoor+dest.ycoor*h;

    while (search != 0)
    {
      int temp = ChildParentDict[search];
      if (search - temp == 1)
      {
      ret.insert(ret.begin(), 0);
      }

      else if (search - temp == h)
      {
      ret.insert(ret.begin(), 1);
      }

      else if (search - temp == -1)
      {
      ret.insert(ret.begin(), 2);
      }

      else if (search - temp == -h)
      {
      ret.insert(ret.begin(), 3);
      }

      search = ChildParentDict[search];
    }

    return ret;
}

/*
    Draws the maze without the solution.

    First, create a new PNG. Set the dimensions
    of the PNG to (width*10+1,height*10+1). where height
    and width were the arguments to makeMaze. Blacken the
    entire topmost row and leftmost column of pixels,
    except the entrance (1,0) through (9,0). For each
    square in the maze, call its maze coordinates (x,y).
    If the right wall exists, then blacken the pixels
    with coordinates ((x+1)*10,y*10+k) for k from 0 to 10.
    If the bottom wall exists, then blacken the pixels
    with coordinates (x*10+k, (y+1)*10) for k from 0 to 10.

    The resulting PNG will look like

    Returns
    a PNG of the unsolved SquareMaze
*/

PNG * SquareMaze::drawMaze(	)	const
{
  PNG *ret = new PNG(w*10+1,h*10+1);

  // Blacken the
  // entire topmost row
  // except the entrance (1,0) through (9,0).

  (*ret)(0,0)->red = 0;
  (*ret)(0,0)->blue = 0;
  (*ret)(0,0)->green = 0;

  for (int i = 10; i < w*10+1; i++ )
  {
      (*ret)(i,0)->red = 0;
      (*ret)(i,0)->blue = 0;
      (*ret)(i,0)->green = 0;
  }
  // and leftmost column of pixels,
  for (int i = 0; i < h*10+1; i++ )
  {
      (*ret)(0,i)->red = 0;
      (*ret)(0,i)->blue = 0;
      (*ret)(0,i)->green = 0;
  }

  for (int i = 0; i < w; i++)
  {
    for (int j = 0; j < h; j++)
    {
      //  For each square in the maze,
      //  call its maze coordinates (x,y).
      //  If the right wall exists, then blacken the pixels
      //  with coordinates ((x+1)*10,y*10+k) for k from 0 to 10.
      if(maze[i][j].rightwall)
      {
        for (int k = 0; k< 11; k++)
        {
          (*ret)((i+1)*10, j*10+k)->red = 0;
          (*ret)((i+1)*10, j*10+k)->green = 0;
          (*ret)((i+1)*10, j*10+k)->blue = 0;
        }
      }
      // If the bottom wall exists, then blacken the pixels
      // with coordinates (x*10+k, (y+1)*10) for k from 0 to 10.
      if (maze[i][j].bottomwall)
      {
        for (int k = 0; k< 11; k++)
        {
          (*ret)(i*10+k, (j+1)*10)->red = 0;
          (*ret)(i*10+k, (j+1)*10)->green = 0;
          (*ret)(i*10+k, (j+1)*10)->blue = 0;
        }
      }
    }
  }

  return ret;

}


/*
    This function calls drawMaze, then solveMaze; it modifies the
    PNG from drawMaze to show the solution vector and the exit.

    Start at pixel (5,5). Each direction in the solution vector
    corresponds to a trail of 11 red pixels in the given direction.
    If the first step is downward, color pixels (5,5) through (5,15)
    red. (Red is 0,0,0 in RGB). Then if the second step is right,
    color pixels (5,15) through (15,15) red. Then if the third step
    is up, color pixels (15,15) through (15,5) red. Continue in this
    manner until you get to the end of the solution vector, so that
    your output looks analogous the above picture.

    Make the exit by undoing the bottom wall of the destination
    square: call the destination maze coordinates (x,y), and whiten
    the pixels with coordinates (x*10+k, (y+1)*10) for k from 1 to 9.

    Returns
    a PNG of the solved SquareMaze
*/


PNG * SquareMaze::drawMazeWithSolution(	)
{
  PNG* ret = drawMaze();
  vector<int> dirs = solveMaze();
  cout<<dirs.size()<<endl;
  int x = 5;
  int y = 5;
  for (size_t i = 0; i < dirs.size(); i++)
  {
      if (dirs[i] == 0)
      {
        // this mean s we took a right
        // so we color the x,y to x+10, y with red
        for (int j = 0; j < 11; j++)
        {
          (*ret)(x+j, y)->red = 255;
          (*ret)(x+j, y)->blue = 0;
          (*ret)(x+j, y)->green = 0;

        }
          x = x + 10;
      }

      if (dirs[i] == 1)
      {
        // going down
        for (int j = 0; j < 11; j++)
        {
          (*ret)(x, y+j)->red = 255;
          (*ret)(x, y+j)->blue = 0;
          (*ret)(x, y+j)->green = 0;

        }
        y = y + 10;

      }

      if (dirs[i] == 2)
      {
        for (int j = 0; j < 11; j++)
        {
          (*ret)(x-j, y)->red = 255;
          (*ret)(x-j, y)->blue = 0;
          (*ret)(x-j, y)->green = 0;
        }
        x = x - 10;

      }

      if (dirs[i] == 3)
      {
        for (int j = 0; j < 11; j++)
        {
          (*ret)(x, y-j)->red = 255;
          (*ret)(x, y-j)->blue = 0;
          (*ret)(x, y-j)->green = 0;
        }
        y = y - 10;

      }
  }
      for (int k = 0; k < 9; k++)
      {
        (*ret)(x-4+k, y+5)->red = 255;
        (*ret)(x+k-4, y+5)->blue = 255;
        (*ret)(x-4+k, y+5)->green = 255;
      }

  return ret;
}



SquareMaze::~SquareMaze()
{
  clear();
}

void SquareMaze::clear()
{
  for (int i = 0; i < w; i++)
  {
      delete [] maze[i];
  }

  delete [] maze;
  // set w and h to 0
  w = h = 0;
}

vector <int> SquareMaze::adjCells(int x, int y)
{
  // just a helper function to help test the adj cells
  // oh my, i just realized how glad I am that there is no diagonal movements
  // in this maze, lol
  vector <int> ret;

        if (canTravel(x, y, 0))
        {
          pair <int, int> insert = make_pair(x+1, y);
            ret.push_back(y*h + x + 1);
        }

        if (canTravel(x, y, 1))
        {
          pair <int, int> insert = make_pair(x, y+1);
            ret.push_back((y+1)*h + x);
        }

        if (canTravel(x, y, 2))
        {
          pair <int, int> insert = make_pair(x-1, y);
            ret.push_back(y*h + x - 1);
        }

        if (canTravel(x, y, 3))
        {
          pair <int, int> insert = make_pair(x, y-1);
            ret.push_back((y-1)*h + x);
        }

        return ret;
}
