#include <iostream>

struct B { B(char c): m(c){} char m; };
struct D : B { using B::B; /* implicitly declares D(char) */ };

int main()
{
    B b('B');
    std::cout << b.m << std::endl;

    D d('D');
    std::cout << d.m << std::endl;
}
