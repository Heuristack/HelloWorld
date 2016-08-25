#include <iostream>
#include <string>

using namespace std;

class X {
    int m = -1;
    ostream & puts(ostream & s){ return s << m; }
public:
    X(int x){ if (x > 80 && x < 90) m = x; }
    X(): X(85){}
    X(string s): X(stoi(s)){}
    friend ostream & operator<<(ostream & s, X & x){ return x.puts(s); }
};

int main()
{
    X x("88");
    cout << x << endl;
}
