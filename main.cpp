#include <iostream>
#include <cstdlib>

using namespace std;

class Target {
public:
    virtual void operate(){ cout << "T"; }
};

class Source {
public:
    virtual void operate(){ cout << "S"; }
};

class Adaptor : public Target, private Source {
public:
    virtual void operate() override { Source::operate(); }
};

int main()
{
    Target * t = new Adaptor();
    t->operate();
    delete t;
    atexit([](){ cout << endl; });
}
