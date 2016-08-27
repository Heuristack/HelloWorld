#include <iostream>
#include <cstdlib>

namespace design_pattern
{
    using std::cout; using std::endl;

    class Implementation {
    public:
        Implementation(){ cout << "I"; }
        virtual~Implementation(){ cout << "I"; }
        virtual void implement() = 0;
    };

    class ConcreteImplementation : public Implementation {
    public:
       ~ConcreteImplementation(){ cout << "C"; }
        ConcreteImplementation(){ cout << "C"; }
        virtual void implement() override { cout << "&"; }
    };

    class DefiniteImplementation : public Implementation {
    public:
       ~DefiniteImplementation(){ cout << "D"; }
        DefiniteImplementation(){ cout << "D"; }
        virtual void implement() override { cout << "*"; }
    };

    class Abstraction {
        Implementation * implementation;    // The conceptal 'bridge', isn't it?
    public:
       ~Abstraction(){ cout << "A"; }
        Abstraction(Implementation * imp): implementation(imp){ cout << "A"; }
        virtual void operate(){ implementation->implement(); }
    };

    class DevelopedAbstraction : public Abstraction {
    public:
        using Abstraction::Abstraction;
        virtual void operate() override { cout << " Developed("; Abstraction::operate(); cout << ") "; }
    };

    class OptimizedAbstraction : public Abstraction {
    public:
        using Abstraction::Abstraction;
        virtual void operate() override { cout << " Optimized("; Abstraction::operate(); cout << ") "; }
    };
}

using namespace design_pattern;

int main()
{
    Implementation * concrete = new ConcreteImplementation();
    Implementation * definite = new DefiniteImplementation();

    Abstraction * optimized = new OptimizedAbstraction(concrete);
    Abstraction * developed = new DevelopedAbstraction(definite);

    optimized->operate();
    developed->operate();

    delete developed;
    delete optimized;
    delete definite;
    delete concrete;

    std::atexit([](){ cout << endl; });
}
