#include "ray.h"
#include "camera.h"
#include "primitive_list.h"
#include "surfaceInteraction.h"

#define MINSIGHT 0
#define MAXSIGHT 100000

using namespace std;
typedef vec3 Color;
typedef vec3 Point;


Camera::Camera(){}


Camera::Camera(Point origin, Point vertical, Point horizontal, Point corner){
	this->origin     = origin;
	this->vertical   = vertical;
	this->horizontal = horizontal;
	this->corner     = corner;
}


bool Camera::hit_sphere(const Point& center, float radius, const ray& r){
	Point oc = r.origin() - center;
	float a = dot(r.direction(),r.direction());
	float b = 2.0 * dot(oc,r.direction());
	float c = dot(oc, oc) - radius*radius;

	float discriminant = b*b - 4*a*c;
	return (discriminant > 0);
}


Color Camera::fadeBG(const ray& r){
	//vetor unitario
	vec3 unit_direction = unit_vector(r.direction());

	//metade do Y do vetor unitário + 1 
	float t = 0.5*(unit_direction.y() + 1.0);

	//aumenta e diminui em funcao deste valor do (branco total ao azul)
	return (1.0-t)*Color(1.0,1.0,1.0) + t*Color(0.5,0.7,1.0);
}


Color Camera::sample(const ray& r, shared_ptr<Primitive_list> world){
	if(world->intersect_p(r,MINSIGHT,MAXSIGHT)){
		return vec3(1,0,0);
	}

	return fadeBG(r);
}