#include <iostream>

int main()
{
    char s[] = "Hello,World!";
    char const & r = s[0];
    r = 'R';

    std::cout << r << std::endl;
}
