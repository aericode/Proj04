#include "vec3.h"

typedef vec3 Color;

FlatMaterial::~FlatMaterial(){}

FlatMaterial::FlatMaterial(){}

FlatMaterial::FlatMaterial(Color color){
	this->color = color;
}

FlatMaterial::getColor(){
	return color;
}