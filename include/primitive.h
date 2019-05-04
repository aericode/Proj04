#ifndef PRIMITIVEH
#define PRIMITIVEH

#include "ray.h"
#include "surfaceInteraction.h"



class Primitive {
    public:
        ~Primitive(){}
        virtual bool intersect( const ray& r, float t_min, float t_max, SurfaceInteraction& inter) = 0;
        // Simpler & faster version of intersection that only return true/false.
        // It does not compute the hit point information.
        virtual bool intersect_p( const ray& r, float t_min, float t_max ) = 0;
};

#endif