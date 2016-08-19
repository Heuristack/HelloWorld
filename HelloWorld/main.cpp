#include <iostream>
#include <string>
#include <memory>

int main()
{
    struct T {
        std::string s_;
        int n_;
        T(const char * s, int n): s_(s), n_(n) {}
    };

    std::cout << std::make_unique<T>("Hello,World!", 8848)->s_ << std::endl;
}
