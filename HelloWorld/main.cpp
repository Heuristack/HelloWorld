#include <iostream>

namespace Name
{
    namespace Old
    {
        const char * f(){ return "old"; }
    }

    inline
    namespace New
    {
        const char * f(){ return "new"; }
    }
}

int main()
{
    std::cout << Name::Old::f() << std::endl;
    std::cout << Name::New::f() << std::endl;

    std::cout << Name::f() << std::endl;

    using namespace Name;
    std::cout << f() << std::endl;

}
