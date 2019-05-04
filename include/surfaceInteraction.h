#ifndef SURFACEH
#define SURFACEH

#include <iostream>
#include "ray.h"
#include "primitive.h"
#include "vec3.h"

typedef vec3 Point;
typedef vec3 Point2f;
typedef ray Vector;

class Primitive;


class SurfaceInteraction {
public:
	SurfaceInteraction(){}
    SurfaceInteraction(const Point&p,const Vector&n, const Vector&wo, float time,
        const Point2f& uv, const Primitive *pri )
        : p{p}, n{n}, wo{wo}, time{time}, uv{uv}, primitive{pri}{};

    Point p; // Contact point.
    Vector n; // The surface normal.
    Vector wo; // Outgoing direction of light, which is -ray.
    float time; // Time of contact.
    Point2f uv; // Parametric coordinate (u,v) of the hit surface.
    const Primitive *primitive = nullptr; // Pointer to the primitive.
};

#endif