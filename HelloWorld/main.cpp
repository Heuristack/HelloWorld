#include <iostream>
#include <chrono>

using namespace std;

int main()
{

    const char * p = "Hello,World!";
    string str(p);

    chrono::time_point<chrono::high_resolution_clock> s, e;
    chrono::duration<double> d;

    s = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000000; i++) for (const auto & c : str) if (c == 'A');
    e = chrono::high_resolution_clock::now();
    d = e - s;
    cout << d.count() << endl;

    s = chrono::high_resolution_clock::now();
    for (int i = 0; i < 10000000; i++) for (auto c : str) if (c == 'A');
    e = chrono::high_resolution_clock::now();
    d = e - s;
    cout << d.count() << endl;
}
