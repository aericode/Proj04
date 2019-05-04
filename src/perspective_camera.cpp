#include "perspective_camera.h"
#include "camera.h"
#include "ray.h"
#include "vec3.h"

typedef vec3 Point;


Perspective_camera::Perspective_camera(){};

Perspective_camera::Perspective_camera(Point origin, Point vertical, Point horizontal, Point corner)
	:Camera(origin,vertical,horizontal,corner){}

ray Perspective_camera::traceRay(float x, float y){
	Point direction = corner + x*horizontal + y*vertical;
	ray generated(origin, direction);
	return generated;
}