#include <type_traits>
template<typename T> struct S { static_assert(std::is_destructible<T>(), "Template argument should be destructible!"); };

int main()
{
    class C { ~C() = delete; };
    S<C> object;
}
