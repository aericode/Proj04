#ifndef PRIMITIVELISTH
#define PRIMITIVELISTH

#include <iostream>
#include <vector>
#include "primitive.h"

using namespace std;

class Primitive_list: public Primitive{
public:
	Primitive** list;
	int list_size;

	Primitive_list();

	Primitive_list(Primitive**, int);
	
	bool intersect(const ray&, float, float, SurfaceInteraction&);

	bool intersect_p(const ray&, float, float);
};

#endif