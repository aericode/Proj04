#include "camera.h"
#include "ray.h"
#include <memory>

using namespace std;

class Scene {

    private:
        shared_ptr<Primitive> objects; // The scene graph of objects, acceleration structure.
        shared_ptr<Camera> camera;

    //=== Public interface
    public:
        Scene( shared_ptr<Primitive> , shared_ptr<Camera>);

        bool intersect( ray&, float, float, SurfaceInteraction);
        bool intersect_p( ray& , float, float);
};