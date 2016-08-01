#include <iostream>

using namespace std;

class Functor {
    char * statement = nullptr;
public:
    inline Functor & operator() (char * s = nullptr);
    friend ostream & operator<< (ostream & s, Functor & f);
};

Functor & Functor::operator() (char * s)
{
    statement = s;
    return *this;
}

ostream & operator<< (ostream & s, Functor & f)
{
    s << f.statement;
    return s;
}

int main()
{
    Functor object;
    char s[] = "Hello,World!";
    cout << object(s) << endl;
}
