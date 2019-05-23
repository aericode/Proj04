#ifndef INTEGRATORH
#define INTEGRATORH

class Integrator {
    public:
        virtual void render(shared_ptr<Primitive_list>) =0;
};

#endif