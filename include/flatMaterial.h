#include "vec3.h"

typedef vec3 Color;

class FlatMaterial : public Material{
    public:
    	Color color;

        virtual ~Material();

        Color getColor();
};