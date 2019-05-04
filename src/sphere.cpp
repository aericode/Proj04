
#include "sphere.h"
#include "ray.h"
#include "vec3.h"
#include "primitive.h"
#include "surfaceInteraction.h"

typedef vec3 Point;

Sphere::Sphere(){};

Sphere::Sphere(Point center, float radius){
	this->center = center;
	this->radius = radius;
}

Sphere::~Sphere(){};

bool Sphere::intersect( const ray& r, float t_min, float t_max, SurfaceInteraction& inter) {
	Point oc = r.origin() - center;
	float a = dot(r.direction(),r.direction());
	float b = dot(oc,r.direction());
	float c = dot(oc, oc) - radius*radius;

	float discriminant = b*b - a*c;

	if (discriminant > 0){
		float temp = (-b - sqrt(discriminant))/a;
		if(temp < t_max && temp > t_min){
			inter.time = temp;
			inter.p    = r.point_at_parameter(inter.time);
			inter.n    = ray(center/ radius, inter.p/ radius);
			inter.wo   = r.getReverse();
			inter.primitive = this;
			return true;
		}

		temp = (-b + sqrt(discriminant))/a;
		if(temp < t_max && temp > t_min){
			inter.time = temp;
			inter.p    = r.point_at_parameter(inter.time);
			inter.n    = ray(center/radius, inter.p/radius) ;
			inter.wo   = r.getReverse();
			inter.primitive = this;
			return true;
		}
	}
	return false;
}



bool Sphere::intersect_p( const ray& r, float t_min, float t_max) {
	Point oc = r.origin() - center;
	float a = dot(r.direction(),r.direction());
	float b = dot(oc,r.direction());
	float c = dot(oc, oc) - radius*radius;

	float discriminant = b*b - a*c;

	if (discriminant > 0){
		float temp = (-b - sqrt(discriminant))/a;
		if(temp < t_max && temp > t_min){return true;}
	}
	return false;
}
