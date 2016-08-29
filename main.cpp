#include <iostream>
#include <cstdlib>

using namespace std;

class T {
    int state = -1;
public:
    T(int s): state(s){}
    T(const T & that_lvalue_reference): state(that_lvalue_reference.state){ cout << "C"; }
    T(T && that_rvalue_reference): state(std::move(that_rvalue_reference.state)){ cout << "M"; }

    ostream & puts(ostream & s){ return s << "state: " << state; }
    friend ostream & operator<<(ostream & s, T & t){ return t.puts(s); }
};

T return_local_object()
{
    T local_object(100);
    return local_object;
}

int main()
{
    T this_object(100);
    T that_object(std::move(this_object));
    T returned_object(std::move(return_local_object()));
    atexit([](){ cout << endl; });
}
