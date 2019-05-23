#include "vec3.h"
#include "ray.h"
#include "camera.h"
#include "primitive_list.h"
#include "plotter.h"
#include "material.h"
#include "flatMaterial.h"
#include "flat_integrator.h"

#define MINSIGHT (float)0
#define MAXSIGHT (float)100000

typedef vec3 Color;


FlatIntegrator::FlatIntegrator(shared_ptr<Camera> camera){
	this->camera = camera;
}

void FlatIntegrator::render(shared_ptr<Primitive_list> g_world) {
	/*
    int nx = g_plotter.xSize;
	int ny = g_plotter.ySize;


	for (int y = ny-1; y >= 0 ; y--){
		for(int x = 0; x <  nx; x++){

			float u = float(i) / float (nx);
			float v = float(j) / float (ny);

			ray r = camera->traceRay(u,v);
            Color L = Li( r, g_world ); // Determine the color for the ray.

            //PLOTTER DESATIVADO
            //main::g_plotter.changePixel(x, y, L)
        }
    }
    //PLOTTER DESATIVADO
    //g_plotter.plotFile();
    */
}


Color FlatIntegrator::Li(ray& r, shared_ptr<Primitive_list> g_world)
{
    SurfaceInteraction isect; 
    Color pixColor;

    if (!g_world->intersect(r, MINSIGHT, MAXSIGHT, isect) ){

        //get Background
        pixColor = camera -> fadeBG(r);
    }
    else {
        //downcast de material pra flatMaterial
        FlatMaterial *fm = dynamic_cast< FlatMaterial *>( isect.primitive );
        
        pixColor = fm->getColor();
    }
    return pixColor;
}