#include <iostream>
#include <functional>

using std::cout;
using std::endl;

class Function {
public:
    Function(){}
    int operator()(int i){ return i; }
};

int pass_function_object_to_me(Function f, int i){ return f(i); }
int main()
{
    cout << Function()(100) << endl;
    cout << pass_function_object_to_me(Function(), 200) << endl;
}
