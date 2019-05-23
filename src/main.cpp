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
#include "integrator.h"
#include "flat_integrator.h"
#include "material.h"
#include "flatMaterial.h"


using json::JSON;
typedef vec3 Color;
typedef vec3 Point;

shared_ptr<Camera> g_camera;
shared_ptr<Primitive_list> g_world;
std::vector<Material*> g_materials;

void init_engine(std::string jsonFile, std::string outputFile)
{
    // [1] Parser and load scene file
    JSON obj = parseFile(filename);

    // [2] Instantiate the Camera, Background, and Integrator objects.
    g_camera = cameraFromJSON(obj);
    //std::unique_ptr<Sampler> sampler(new StratifiedSampler(...));
    //g_integrator = std::make_unique<FlatIntegrator>(cam, sampler );
    // We create the scene last, becasue we need all the other objects first.
    //g_scene = std::make_unique< Scene > (...);
    world = primitivesFromJSON(obj);

    Material* red   = new Material(255,0,0);
    Material* green = new Material(0,255,0);
    Material* blue  = new Material(0,0,255);
    Material* black = new Material(0,0,0);
    Material* white = new Material(255,255,255);

    g_materials.push_back(red);
	g_materials.push_back(green);
	g_materials.push_back(blue);
	g_materials.push_back(black);
	g_materials.push_back(white);

    int nx = 200;
	int ny = 100;
    Plotter plotter(nx,ny,"./imageOutput/default.ppm");
}


int main(){
	
	init_engine("./jsonInput/scene.json");


	for (int j = ny-1; j >= 0 ; j--){
		for(int i = 0; i <  nx; i++){
			float u = float(i) / float (nx);
			float v = float(j) / float (ny);
			
			ray r = g_camera->traceRay(u,v);

			//Col recebe a cor do que o raio atinge
			Color col = g_camera->hitColor(r, world);

			int ir  = int(255.99*col[0]);
			int ig  = int(255.99*col[1]);
			int ib  = int(255.99*col[2]);

			plotter.changePixel(i,j, Color(ir,ig,ib));
			
		}
	}

	plotter.plotFile();
	
}