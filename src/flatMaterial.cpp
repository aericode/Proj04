#include "vec3.h"
#include <string>
#include "flatMaterial.h"

typedef vec3 Color;

FlatMaterial::~FlatMaterial(){}

FlatMaterial::FlatMaterial(){}

FlatMaterial::FlatMaterial(Color color, string name){
	this->color = color;
	this->name  = name;
}

Color FlatMaterial::getColor(){
	return color;
}