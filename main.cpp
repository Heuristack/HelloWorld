#include <iostream>
#include <string>
#include <memory>

using namespace std;

class C {
    int internal_state = 10;
};

class T
{
    int internal_state = 20;
    string state;
public:
   ~T(){ cout << "D" << endl; }
    T(): T("Initialized by default!"){}
    T(const string & s): state(s){ cout << "C" << endl; }

    const string & get(){ return state; }
    int get_value(){ return internal_state; }
    unique_ptr<T> clone(){ auto p = make_unique<T>(state); p->internal_state = internal_state; return p; }
};

int main()
{
    unique_ptr<T> originalptr = make_unique<T>("original");
    cout << originalptr->get() << endl;

    unique_ptr<T> clonedptr = originalptr.get()->clone();
    cout << clonedptr->get() << endl;
    cout << clonedptr->get_value() << endl;

}
