#include <iostream>
#include <functional>
#include <type_traits>

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

int main()
{
    // categories
    cout << std::is_object  <Function>::value << endl;
    cout << std::is_scalar  <Function>::value << endl;
    cout << std::is_trivial <Function>::value << endl;

    // classification
    cout << std::is_fundamental <Function>::value << endl;
    cout << std::is_compound    <Function>::value << endl;

    // class
    cout << std::is_class       <Function>::value << endl;

    // reference
    cout << std::is_reference   <Function>::value << endl;

    cout << std::is_lvalue_reference<Function&>::value << endl;
    cout << std::is_rvalue_reference<Function&>::value << endl;

    cout << std::is_lvalue_reference<Function&&>::value << endl;
    cout << std::is_rvalue_reference<Function&&>::value << endl;
}
