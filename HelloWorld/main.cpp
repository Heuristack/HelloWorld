#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> indices(10);
    int count = 0;
    std::generate(indices.begin(), indices.end(), [&count]{ return count++; });
    std::for_each(indices.begin(), indices.end(), [](int element){ std::cout << element << std::endl; });
}
