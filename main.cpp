#include <iostream>
#include <random>
#include <functional>

using namespace std;
using namespace std::placeholders;

int printnum(int p, int o, int q)
{
    auto & s = cout;
    s << "1: " << p << "; ";
    s << "2: " << o << "; ";
    s << "3: " << q << "; ";
    return 0;
}

int main()
{
    default_random_engine engine;
    normal_distribution<double> distribution(10,4);

    function<double()> normalrand = bind(distribution, engine);

    for (int i = 0; i < 10; i++) cout << normalrand() << endl;

    printnum(1, 2, 3);
    cout << endl;

    function<int(int)> print1 = bind(printnum, _1, 0, 0);
    print1(100);
    cout << endl;
}
