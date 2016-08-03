#include <iostream>
#include <thread>

int main(){
    std::set_terminate([](void){ std::cout << "do terminate!" << std::endl; });
    auto f = std::get_terminate();
    f();
    std::terminate();
}
