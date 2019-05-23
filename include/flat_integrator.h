#include "camera.h"
#include "vec3.h"

using namespace std;
typedef vec3 Color;

class FlatIntegrator : public Integrator {
protected:
    shared_ptr<const Camera> camera;
//=== Public interface
public:
    ~FlatIntegrator();
    FlatIntegrator();
    FlatIntegrator(shared_ptr<Camera>);

    Color Li(Ray& , shared_ptr<Primitive_list>);

    void render(shared_ptr<Primitive_list>);

};