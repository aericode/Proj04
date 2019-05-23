#include <iostream>
#include <fstream>
#include <memory>

#include "json.hpp"
#include "jsonReader.h"
#include "perspective_camera.h"
#include "orthogonal_camera.h"
#include "camera.h"
#include "ray.h"
#include "sphere.h"
#include "plotter.h"
#include "primitive_list.h"
//#include "integrator.h"
//#include "flat_integrator.h"
#include "material.h"
#include "flatMaterial.h"


using json::JSON;
typedef vec3 Color;
typedef vec3 Point;

shared_ptr<Camera> g_camera;
shared_ptr<Primitive_list> g_world;
Plotter g_plotter;

/*MOVIDO PARA JSON READER
vector<Material*> g_materials;

void init_materials(){
	Material* red   = new Material(RED,   "red"  );
    Material* green = new Material(GREEN, "green");
    Material* blue  = new Material(BLUE,  "blue" );
    Material* black = new Material(BLACK, "black");
    Material* white = new Material(WHITE, "white");

    g_materials.push_back(red);
	g_materials.push_back(green);
	g_materials.push_back(blue);
	g_materials.push_back(black);
	g_materials.push_back(white);
}
*/

void init_engine(std::string jsonFile, std::string outputFile)
{
    JSON obj = parseFile(jsonFile);

    //g_camera = cameraFromJSON(obj);
    //g_world = primitivesFromJSON(obj);
    //init_materials();


    int nx = 200;
	int ny = 100;
    //g_plotter = Plotter(nx,ny,outputFile);
    g_plotter = nullptr;
}


int main(){
	
	init_engine("./jsonInput/scene.json","./imageOutput/default.ppm");

    int nx = 200;
	int ny = 100;

	for (int j = ny-1; j >= 0 ; j--){
		for(int i = 0; i <  nx; i++){
			float u = float(i) / float (nx);
			float v = float(j) / float (ny);
			
			ray r = g_camera->traceRay(u,v);

			//Col recebe a cor do que o raio atinge
			Color col = g_camera->hitColor(r, g_world);

			int ir  = int(255.99*col[0]);
			int ig  = int(255.99*col[1]);
			int ib  = int(255.99*col[2]);

			g_plotter.changePixel(i,j, Color(ir,ig,ib));
			
		}
	}

	g_plotter.plotFile();
	
}