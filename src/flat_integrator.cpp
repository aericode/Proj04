#include "vec3.h"
#include "ray.h"
#include "camera.h"
#include "primitive_list.h"
#include "plotter.h"
#include "flat_integrator.h"

typedef vec3 Color;

FlatIntegrator::~FlatIntegrator(){}

FlatIntegrator::FlatIntegrator(){}

FlatIntegrator::FlatIntegrator(shared_ptr<Camera> camera){
	this->camera = camera;
}

void FlatIntegrator::render(shared_ptr<Primitive_list> g_world) {
	int nx = g_plotter.xSize;
	int ny = g_plotter.ySize;


	for (int y = ny-1; y >= 0 ; y--){
		for(int x = 0; x <  nx; x++){

			float u = float(i) / float (nx);
			float v = float(j) / float (ny);

			ray r = main::g_camera->traceRay(u,v);
            Color L = Li( r, g_world ); // Determine the color for the ray.

            main::g_plotter.changePixel(x, y, L)
        }
    }
    // Send image color buffer to the output file.
    g_plotter.plotFile();
}


Color FlatIntegrator::Li(const Ray& ray, shared_ptr<Primitive_list> g_world)
{
    SurfaceInteraction isect;  
    if (!scene.intersect(ray, &isect)) {
        // This might be just:
        L = g_camera -> fadeBG(r);
    }
    else {
        // Some form of determining the incoming radiance at the ray's origin.
        // For this integrator, it might just be:
        // Polymorphism in action.
        FlatMaterial *fm = dynamic_cast< FlatMaterial *>( iscet.primitive->get_material() );
        // Assign diffuse color to L.
        L = fm->getColor(); // Call a method present only in FlatMaterial.
    }
    return L;
}