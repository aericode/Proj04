#ifndef SPHEREH
#define SPHEREH

#include "ray.h"
#include "vec3.h"
#include "primitive.h"
#include "surfaceInteraction.h"

typedef vec3 Point;

class Sphere: public Primitive {
public:
	Point center;
	float radius;

	Sphere();
	Sphere(Point, float );
	~Sphere();

    bool intersect( const ray& r, float t_min, float t_max, SurfaceInteraction& inter);

    bool intersect_p( const ray& r, float t_min, float t_max);
};

#endif