#include <iostream>

unsigned divide(unsigned numerator, unsigned denominator)
{
    unsigned quotient = 0;
    while (numerator >= denominator) {
        numerator -= denominator;
        quotient++;
    }
    return quotient;
}

int main()
{
    std::cout << divide(8,1) << std::endl;
}
