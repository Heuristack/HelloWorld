#include <iostream>
#include <functional>
#include <cstdlib>

using std::cout;
using std::ends;
using std::endl;

class Function {
public:
   ~Function(){ cout << "D" << ends; }
    Function(){ cout << "F" << ends; }
    Function(const Function&){ cout << "C" << ends; };
    int operator()(int i){ return i; }
};

int pass_function_object_to_me(Function f, int i){ return f(i); }

int main()
{
    std::atexit([](){ cout << endl; });

    cout << Function()(100);
    cout << pass_function_object_to_me(Function(), 200);

    Function F;
    cout << pass_function_object_to_me(F, 400);

    cout << std::bind(F, 500)();
    cout << std::bind(F, std::placeholders::_1)(600);

    std::function<int()> G = std::bind(F, 800);
    cout << G();
}
