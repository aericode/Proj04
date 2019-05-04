#ifndef PERSPECTIVECAMERAH
#define PERSPECTIVECAMERAH

#include "camera.h"
#include "vec3.h"

typedef vec3 Point;

class Perspective_camera: public Camera{
public:
	Perspective_camera();
	Perspective_camera(Point, Point, Point, Point);
	ray traceRay(float, float);
};

#endif