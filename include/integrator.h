class Integrator {
    public:
        virtual ~Integrator();
        virtual void render(shared_ptr<Primitive_list>) =0;
};