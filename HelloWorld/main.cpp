#include <iostream>

struct B { B(char c): m(c){} char m; };
B return_type_conversion(char c){ return c; }

int main()
{
    B b = return_type_conversion('B');
    std::cout << b.m << std::endl;

    std::cout << return_type_conversion('T').m << std::endl;
}
