#ifndef SCENE_H
#define SCENE_H
// codes for scene.h file

#include <iostream>
#include "image.h"

using namespace std;
class Scene {

	public :
		// constructor
		Scene (int Nmax);
		// clear function
		void clear();
		// deconstructor 
		~Scene();
		//copy helper
		void copy (const Scene &source);
		// copy constructor
		Scene (const Scene &source);
		// operator overload
		const Scene& operator=(const Scene &source);
		
		//functionality
		void changemaxlayers (int newmax);
		void addpicture (const char *Filename, int index, int Nx, int Ny);
		void changelayer (int index, int newindex);
		void translate (int index, int xcoord, int ycoord);
		void deletepicture (int index);

		Image * getpicture (int index) const;
		//Image * 	getpicture (int index) const
		Image drawscene () const;
		//Image 	drawscene () const

	private :
		int max;
		//int count;
		Image **images;
		int* x;
		int* y;

};
#endif 
