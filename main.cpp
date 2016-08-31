#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;

unsigned fibnacci(unsigned n){ if (n < 2) return n; else return fibnacci(n-1) + fibnacci(n-2); }

int main()
{
    auto s = chrono::high_resolution_clock::now();
    fibnacci(41);
    auto e = chrono::high_resolution_clock::now();
    auto d = chrono::duration_cast<chrono::duration<double, ratio<1,1>>>(e - s);
    cout << "duration: " << d.count() << "seconds" << endl;
}
