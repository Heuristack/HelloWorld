#include <iostream>
#include <string>
#include <memory>

int main()
{
    class T {
        int m = 0;
    public:
        T(int n):m(n){ std::cout << "C: " << m << std::endl; }
        ~T(){ std::cout << "D: " << m << std::endl; m = 0; }
        void f(std::unique_ptr<T>& p){ p = nullptr; std::cout << "F: " << m << std::endl; }
    };

    auto p = std::make_unique<T>(1);
    std::cout << "points to 1" << std::endl;

    p = nullptr;
    std::cout << "points to 0" << std::endl;

    p = std::make_unique<T>(2);
    std::cout << "points to 2" << std::endl;

    p->f(p);
}
