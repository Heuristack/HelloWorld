#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Subject {
public:
    virtual ~Subject(){ cout << "S"; }
    virtual void execute() = 0;
};

class RealSubject : public Subject {
    string state;
public:
   ~RealSubject(){ cout << "R"; }
    RealSubject(): RealSubject("default"){}
    RealSubject(const string & s): state(s){ cout << "R"; }
    virtual void execute() override { cout << "[" << state << "]"; }
};

class Proxy : public Subject {
    RealSubject * that;
public:
   ~Proxy(){ delete that; cout << "P"; }
    Proxy(const string & s){ cout << "P"; that = new RealSubject(s); }
    virtual void execute() override { cout << "{"; that->execute(); cout << "}"; }
    RealSubject * operator->(){ return that; }
};

int main()
{
    Proxy proxy("surrogate");
    proxy.execute();
    proxy->execute();
    atexit([](){ cout << endl; });
}
