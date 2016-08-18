#include <iostream>
#include <array>
#include <iterator>
#include <algorithm>
#include <functional>

int main()
{
    const int n = 100;
    std::array<int, n> container;
    std::generate(container.begin(), container.end(), [=](){ static int x = 0; return x += 1; });
    std::for_each(container.begin(), container.end(), [=](int e){ std::cout << e << " "; });
    std::cout << std::endl;

    std::cout << container.size() << std::endl;
    std::cout << std::boolalpha << container.empty() << std::endl;

    // max between the 1st and last element using less functor as the predicate
    std::cout << std::max(container.front(), container.back(), std::less<int>()) << std::endl;
    std::cout << std::min(container[0], container.at(container.size())) << std::endl;

    // max in the range of [begin, end) using greater functor as the predicate
    std::cout << *std::max_element(container.begin(), std::end(container), std::greater<int>{}) << std::endl;
}
