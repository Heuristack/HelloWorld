#include <string>
#include <tuple>
#include <iostream>

int main()
{
    std::tuple<std::string, int> t {"Hello,World!", 1};
    auto p = std::make_tuple("Hello,World!", 2);

    auto x = [=](std::tuple<std::string, int> t){ std::cout << "(\"" << std::get<0>(t) << "\", " << std::get<1>(t) << ")" << std::endl; };
    x(t);
    x(p);
}
