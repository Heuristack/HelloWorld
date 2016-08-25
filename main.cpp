#include <iostream>
#include <string>

using namespace std;

class X {
    int m = -1;
    ostream & puts(ostream & s){ return s << m; }
public:
    X(int x){ m = x; cout << "C: " << m << endl; }
    X(): X(100){}
    X(string s): X(stoi(s)){}
    ~X(){ cout << "D: " << m << endl; }

    int delete_self(X * p){ delete p; return m; }
    int delete_self(){ delete this; /* Herein, what can I do after I deleted myself? */ return m; }

    friend int delete_friend(X * p);
    friend ostream & operator<<(ostream & s, X & x){ return x.puts(s); }
};

int delete_friend(X * p){ delete p; return p->m; }

int main()
{
    X * p = new X(99);
    cout << p->delete_self() << endl;
}
