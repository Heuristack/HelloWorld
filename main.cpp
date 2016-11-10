#include <iostream>
#include <vector>
#include <memory>

class T {
public:
   ~T(){ std::cout << "D" << std::endl; }
    T(){ std::cout << "C" << std::endl; }
};

int main()
{
    std::vector<std::unique_ptr<T>> v(10);
    v.push_back(std::make_unique<T>());
}

