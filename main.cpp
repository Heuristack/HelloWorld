#include <iostream>
#include <utility>
#include <typeinfo>
#include <typeindex>

using namespace std;

template<typename T> void print_nemuric_limits()
{
    cout << "Nemuric Limits for Type: " << typeid(T).name() << endl;
    using limits = numeric_limits<T>;
    cout << "digits: " << limits::digits << endl;
    cout << "max: " << limits::max() << endl;
    cout << "min: " << limits::min() << endl;
    cout << "is exact: " << limits::is_exact << endl;
    cout << "epsilon: " << limits::epsilon() << endl;
    cout << endl;
}

int main()
{
    print_nemuric_limits<unsigned long long>();
    print_nemuric_limits<double>();
}
