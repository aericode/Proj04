#ifndef FLATMATERIALH
#define	FLATMATERIALH

#include "material.h"
#include "vec3.h"
#include <string>

typedef vec3 Color;

class FlatMaterial : public Material{
    public:
    	FlatMaterial();
    	~FlatMaterial();
    	FlatMaterial(Color,string);
        Color getColor();
};

#endif