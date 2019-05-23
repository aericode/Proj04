#ifndef MATERIALH
#define MATERIALH

#include "vec3.h"

typedef vec3 Color;

class Material {
    public:
    	Color color;
        virtual ~Material();
};

#endif