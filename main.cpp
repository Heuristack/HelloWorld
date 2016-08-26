#include <iostream>

namespace design_pattern
{
    class I {
    public:
        virtual ~I(){}
        virtual void succeed() = 0;
    };

    class Decorator : public I {
        I * that;
    public:
        Decorator(I * i): that(i) {}
        Decorator() : Decorator(this) {}

        void succeed(){ std::cout << "=" << std::endl; that->succeed(); }
    };
}

int main()
{
    design_pattern::Decorator decorator;
    decorator.succeed();
}
