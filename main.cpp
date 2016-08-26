#include <iostream>
#include <cstdlib>

namespace design_pattern
{
    using std::cout; using std::endl;

    class Base {
    public:
        virtual ~Base(){}
        virtual void succeed() = 0;
    };

    class Implementation : public Base {
    public:
       ~Implementation(){ cout << "I"; }
        Implementation(){ cout << "I"; }
        void succeed(){ cout << " = "; }
    };

    class Decorator : public Base {
        Base * that;
    public:
       ~Decorator(){ delete that; }
        Decorator(Base * base) : that(base) {}
        void succeed(){ that->succeed(); }
    };

    class Degree : public Decorator {
    public:
       ~Degree(){ cout << "D"; }
        Degree(Base *base): Decorator(base){ cout << "D"; }
    };

    class Health : public Decorator {
    public:
       ~Health(){ cout << "H"; }
        Health(Base *base): Decorator(base){ cout << "H"; }
    };
}

using namespace design_pattern;

int main()
{
    std::atexit([](){ cout << endl; });
    Base * pbase = new Health(new Degree(new Implementation));
    pbase->succeed();
    delete pbase;
}
