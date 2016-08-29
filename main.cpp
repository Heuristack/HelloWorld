#include <iostream>
#include <string>

using namespace std;

class Singleton
{
    static Singleton * instanceptr;
    string stat;
protected:
   ~Singleton(){ cout << "C"; }
    Singleton(const string & s): stat(s){ cout << "C"; }
    Singleton(): Singleton("Initialized by default!"){}
public:
    static Singleton & instance()
    {
        if (nullptr == instanceptr)
            instanceptr = new Singleton();
        return *instanceptr;
    }
    string & state(){ return stat; }
};
Singleton * Singleton::instanceptr = nullptr;

int main()
{
    Singleton::instance().state() = "Guarantee only one instance of Singleton exists!";

    cout << Singleton::instance().state();
    cout << endl;
}
