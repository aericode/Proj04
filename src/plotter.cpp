#define WHITE Color(255,255,255)
#define BLACK Color(0,0,0)
#include <iostream>
#include <fstream>

#include "vec3.h"
#include "plotter.h"

#include <vector>
#include <string>

using namespace std;
typedef vec3 Color;

Plotter::Plotter(){}

Plotter::Plotter(int xSize,int ySize, string fileName){

	this->fileName = fileName;

	this->xSize = xSize;
	this->ySize = ySize;

	colorBuffer.resize(xSize*ySize);

	clear();
}

Plotter::~Plotter(){}

int Plotter::matrixToLine(int x, int y){
	return x + ( (ySize-1)-y)*xSize;
}

bool Plotter::isValidLocation(int x, int y){
	bool validX = (x < xSize) && (x >= 0);
	bool validY = (y < ySize) && (y >= 0);

	return validX && validY;
}

void Plotter::changePixel(int x, int y, Color color = BLACK){
	//se estiver fora do limite simplesmente ignora
	if(!isValidLocation(x,y)){return;}

	int indexLine = matrixToLine(x,y);
	colorBuffer.at(indexLine) = color;
}

void Plotter::clear(){
	for(int i = 0;i < colorBuffer.size();i++){
		colorBuffer.at(i) = WHITE;
	}
}


void Plotter::plotFile(){
	std::ofstream myfile;

	myfile.open(fileName.c_str());



	myfile<< "P3" <<std::endl;
	myfile<< std::to_string(xSize) + " " +  std::to_string(ySize) <<std::endl;
	myfile<< "255" <<std::endl;


	for(int i = 0;i < colorBuffer.size();i++){
		myfile << colorBuffer.at(i) << std::endl;
	}
}