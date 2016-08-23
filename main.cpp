#include <iostream>
#include <string>
#include <algorithm>

#include <ctype.h>

using std::string;
using std::reverse;

inline int tonum(char digit)
{
    int num = 0;

    if (isdigit(digit))
        num = digit - '0';
    else
        num = 10 + digit - 'A';

    return num;
}

inline char todigit(int num)
{
    char digit;

    if (num >= 10)
        digit = 'A' + num - 10;
    else
        digit = '0' + num;

    return digit;
}

string convert_base(string s, int b1, int b2)
{
    string z;

    bool negative = s.front() == '-';

    int n = 0;
    for (string::iterator i = s.begin() + ((negative) ? 1 : 0); i < s.end(); i++) {
        n *= b1;
        n += tonum(*i);
    }

    int r = 0;
    while (n) {
        r = n % b2;
        z.push_back(todigit(r));
        n /= b2;
    }

    if (z.empty())
        z.push_back('0');

    if (negative)
        z.push_back('-');

    reverse(z.begin(), z.end());

    return z;
}

int main()
{
    std::cout << convert_base("56789", 10, 16) << std::endl;
}
