#include "scene.h"

using namespace std;

Scene::Scene(int Nmax)
{
	//count = 0;
	max = Nmax;
	// allocate dynamic memory for image array
	images = new Image* [max];	
	//initialize each image to null
	for (int x = 0; x < max; x++)
	{
		images[x] = NULL;
	}
	//storage for x and y
	x = new int [max];
	y = new int [max];
}

// copy helper function, 
void Scene::copy(const Scene &source) 
{
	cout<<"reach cctor line 24"<<endl;
	max = source.max;
	//count = source.count;
	images = new Image* [max];	
	cout<<"reach cctor line 28"<<endl;
	x = new int [max];
	cout<<"reach cctor line 30"<<endl;
	y = new int [max];
	cout<<"reach cctor line 32"<<endl;
	for (int i = 0; i < max; i++)
	{
		if (source.images[i] == NULL)
		{
			images[i] = NULL;
		}	
		else
		{
			// forgot to add new to images
			images[i] = new Image;
			*(images[i]) = *(source.images[i]);
			// go back to make sure we are allocating a deep copy
			x[i] = source.x[i];
			y[i] = source.y[i]; 

		}
	}
	cout<<"reach cctor line 48"<<endl;
	return;

}

Scene::Scene (const Scene &source)
{
	copy (source);
}

// destructor
void Scene::clear()
{
	for (int i = 0; i < max; i++)
	{
		if (images[i] != NULL)
			delete images[i];
	}
	delete [] images; // do I need this?
	delete [] x;
	delete [] y;
	images = NULL; //do I need this?
	x= NULL;
	y= NULL;
}

Scene::~Scene()
{
	// call clear
	clear();
}

const Scene & Scene::operator= (const Scene & source)
{
	if (this != &source)
	{
		clear();
		copy(source);
	}
	return *this;
}


void Scene::changemaxlayers(int newmax)
{
	//check if the newmax is valid
	if (max > newmax)
	{
		cout<<"invalid newmax"<<endl;
		return;
	}
	// creating a temporary holding for the images
	Image** temp = new Image* [newmax];
	max = newmax;
	int* newx = new int [max];
	int* newy = new int [max];

	for (int i = 0; i < max; i++)
	{
		if (images[i] == NULL)
		{
			temp[i] = NULL;
		}
		else
		{
			temp[i] = images[i];
			newx[i] = x[i];
			newy[i] = y[i];
		}
		
	}
	// destroy the old images array and the x and y integer array
	delete [] images;
	delete x;
	delete y;

	// set the address of the temp to images, x, and y
	images = temp;
	x = newx;
	y = newy;
	return;

   //Images temp [newmax];
}
//set->addpicture("in_01.png", 0, 0, 0);
void Scene::addpicture(const char* FileName, int index, int Nx, int Ny)
{
	if (index > (max-1))
	{
		cout << "index out of bounds" << endl;
		return;
	}
	Image* add = new Image;
	(*add).readFromFile(FileName);

	// i see two possible options, one being that the index can be readily switched in, other is that I have to 
	if ((max - 1) >= index)
	{
		//(*add).readFromFile(FileName);
		//if (read)
		//{
		if (images[index] != NULL)
		{
			delete images[index];
		}

		images[index] = add;
		//(this->)x[index] = x;
		//(this->)y[index] = y;
		x[index] = Nx;
		y[index] = Ny;
		//}
		return;
	}
	// if the index exceed new max then I'll just change the max with changemaxlayer
	cout<<"index out of bounds" << endl;
	return;

}

void Scene::changelayer(int index, int newindex)
{
	cout<<"reach changelayer"<<endl;
	if (index == newindex)
	{
		//cout<<"invalid index"<<endl;
		cout<<"reach changelayer line 174"<<endl;
		return;
	}
	if ((index > (max -1)) | (newindex > (max-1)))
	{
		cout<<"invalid index"<<endl;
		cout<<"reach changelayer line 180"<<endl;
		return;
	}

	if ((images[index] == NULL) && (images[newindex] == NULL))
	{
		cout<<"invalid index"<<endl;
		cout<<"reach changelayer line 187"<<endl;
		return;
	}
	// now we can be sure index and newindex are [0, max-1]
	if (images[newindex] != NULL)
	{
		delete images[newindex];
	}
		// check if the source is invalid
		/*if (images[index] == NULL)
		{
			return;
		}*/
		// switch pointers
		images[newindex] = images[index];
		images[index] = NULL;
		cout<<"reach changelayer line 203"<<endl;
		// set source to null to mark it
		x[newindex] = x[index];
		y[newindex] = y[index];
		return;
}



void Scene::translate(int index, int xcoord, int ycoord)
{
	// if index is invalid
	if ((max-1) < index)
	{
		cout<<"invalid index"<<endl;
		return;
	}
	// if the pointer is null
	if (images[index] == NULL)
	{
		cout<<"invalid index"<<endl;
		return;
	}

	x[index] = xcoord;
	y[index] = ycoord;
}

void Scene::deletepicture(int index)
{
	//invalid index
	if (index > (max-1)) 
	{
		cout<<"invalid index"<<endl;
		cout<<"reach deletepicture line 233"<<endl;
		return;
	}
	//index points to NULL. prevents double free memory
	if (images[index] == NULL)
	{
		cout<<"invalid index"<<endl;
		cout<<"reach deletepicture line 240"<<endl;
		return;
	}

	delete images[index];
	images[index] = NULL;
}	

Image* Scene::getpicture(int index) const
{
	if ((max-1)<index)
	{
		cout<<"invalid index"<<endl;
		return NULL;
	}

	if (images[index] == NULL)
	{
		cout<<"invalid index"<<endl;
		return NULL;
	}
	return images[index];
}

Image Scene::drawscene() const
{
	//find max width needed and max height by first setup two holder variabls
	size_t maxH = 0;
	size_t maxW = 0;

	for (int i = 0; i < max; i++)
	{
		if (images[i] != NULL)
		{
			//cycle through array to find largest width the image needs to be
			if (( x[i] + (images[i])->width() )> maxW)
				maxW = x[i] + (images[i])->width();
			//cycle through array to find the largest height the image needs to be
			if 
				(( y[i] + (images[i]->height() ) > maxH))
				maxH = y[i] + (images[i])->height();
		}
	}

	// now that maxH and maxW should hold the width and height needed by the largest images
	// create a return image
	Image ret;
	ret.resize(maxW, maxH);

	for (int j = 0; j < max; j++)
	{
		// check if image pointer is NULL
		if (images[j] != NULL)
		{
			//get the images's size
			size_t w = images[j]->width();
			size_t h = images[j]->height();
			// use double for loop to allocate the pixel in images
			for (size_t a = 0; a < w; a++)
			{	
				for (size_t b = 0; b <  h; b++)
				{
					ret(x[j]+a, y[j]+b)->red = (*images[j])(a,b)->red;
					ret(x[j]+a, y[j]+b)->blue = (*images[j])(a,b)->blue;
					ret(x[j]+a, y[j]+b)->green = (*images[j])(a,b)->green;
	//				ret(x[j]+a, y[j]+b)->green = (images[j])->(a,b)->green);
					//*original(centerX, y) = color;
				}
			}
		}
	}
	return ret;
	
}