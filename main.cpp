#include <iostream>
#include <string>
#include <memory>

int main()
{
    class T {
        int m = -100;
    public:
        T(int n):m(n){ std::cout << "C: " << m << std::endl; }
        ~T(){
            std::cout << "D: " << m << std::endl;
            m = -1000;                                 // have effect ?
        }
        void f(std::unique_ptr<T>& p){
            p = std::make_unique<T>(m+1);             // invoke destruction
            p = std::make_unique<T>(m+2);             // invoke destruction
            p = std::make_unique<T>(m+3);             // invoke destruction
//          p = std::make_unique<T>(m+4);             // invoke destruction
//          p = std::make_unique<T>(m+5);             // invoke destruction
            std::cout << "F: " << m << std::endl;   // m is 0 not  -1
        }
        void g(){ std::cout << "G: " << std::endl; }
        void h(){ std::cout << "H: " << m << std::endl; }
    };

    auto p = std::make_unique<T>(1);
    std::cout << "points to 1" << std::endl;

    p = nullptr;
    std::cout << "points to 0" << std::endl;

    p = std::make_unique<T>(2);
    std::cout << "points to 2" << std::endl;

    p->f(p);
    std::cout << "points to 3" << std::endl;

    p->h();
}
