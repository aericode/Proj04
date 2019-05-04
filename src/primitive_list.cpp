#include "primitive_list.h"
#include <iostream>
#include <vector>
#include "primitive.h"

using namespace std;

Primitive_list::Primitive_list(){
	list_size = 0;
}

Primitive_list::Primitive_list(Primitive **l, int n){
	list = l;
	list_size = n;
}

bool Primitive_list::intersect(const ray& r, float t_min, float t_max, SurfaceInteraction& inter){
	SurfaceInteraction aux;
	bool hit_something = false;
	float closest_dist = t_max;
	for(int i = 0; i < list_size ; i++){
		if (list[i]->intersect(r,t_min,closest_dist, aux)){
			hit_something = true;
			closest_dist = aux.time;
			inter = aux;
		}
	}
	return hit_something;

}


bool Primitive_list::intersect_p(const ray& r, float t_min, float t_max){
	for(int i = 0; i < list_size; i++){
		if (list[i]->intersect_p(r,t_min,t_max)){
			return true;
		}
	}
	return false;
}