#ifndef MATERIALH
#define MATERIALH

#include "vec3.h"
#include <string>

using namespace std;
typedef vec3 Color;

class Material {
    public:
    	string name;
    	Color color;
    	Material();
    	Material(Color, string);
        ~Material();

        void copy(Material);
};

#endif