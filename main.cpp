#include <iostream>
#include <string>
#include <utility>

using std::cout;
using std::endl;

int main()
{
    int m = 100, n = 200;
    std::swap(m,n);
    cout << m << n << endl;

    std::string s = "100", t = "200";
    std::swap(s,t);
    cout << s << t << endl;
}
