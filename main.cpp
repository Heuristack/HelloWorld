#include <iostream>
#include <functional>

using std::cout;
using std::endl;

std::function<int (int)> make_closure_capture_nothing(){ return [](int i)->int{ return i; }; }

int main()
{
    cout << make_closure_capture_nothing()(100) << endl;
}
