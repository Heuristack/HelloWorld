#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

bool parity(unsigned long n)
{
    bitset<CHAR_BIT * sizeof(unsigned long)> s(n);
    if (s.count() % 2)
        return true;
    return false;
}

int main()
{
    unsigned long n = 0B0000000000000000000111001001001010010111001000000010111101010100UL;
    bitset<CHAR_BIT * sizeof(unsigned long)> s(n);
    cout << "parity(0B" << s << "UL = " << n << ") = " << parity(n) << endl;
    return 1;
}
