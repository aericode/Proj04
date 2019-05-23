#ifndef FLATINTEGRATORH
#define FLATINTEGRATORH

#include "integrator.h"
#include "primitive_list.h"
#include "camera.h"
#include "vec3.h"
#include "ray.h"

using namespace std;
typedef vec3 Color;

class FlatIntegrator : public Integrator {
protected:
    shared_ptr<Camera> camera;
//=== Public interface
public:
    FlatIntegrator(shared_ptr<Camera>);

    Color Li(ray& , shared_ptr<Primitive_list>);

    void render(shared_ptr<Primitive_list>);

};

#endif