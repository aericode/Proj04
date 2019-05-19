#ifndef ORTHOGONALCAMERAH
#define ORTHOGONALCAMERAH

#include "camera.h"
#include "vec3.h"

typedef vec3 Point;

class Orthogonal_camera: public Camera{
public:
	//Direction the camera is pointing at
	float direction;

	Orthogonal_camera();
	Orthogonal_camera(Point, Point, Point, Point, float);
	ray traceRay(float, float);
};

#endif