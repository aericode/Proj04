#include "material.h"
#include "vec3.h"
#include <string>

typedef vec3 Color;

Material::~Material(){}

Material::Material(){}

Material::Material(Color color, string name){
	this->color = color;
	this->name  = name;
}

void Material::copy(Material copied){
	this->color = copied.color;
	this->name  = copied.name;
}