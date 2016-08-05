#include <iostream>
#include <chrono>

using namespace std;

int main()
{
    cout << chrono::system_clock::period::num << endl;
    cout << chrono::system_clock::period::den << endl;
    cout << boolalpha << chrono::system_clock::is_steady << endl;

    cout << chrono::high_resolution_clock::period::num << endl;
    cout << chrono::high_resolution_clock::period::den << endl;
    cout << boolalpha << chrono::high_resolution_clock::is_steady << endl;

    cout << chrono::steady_clock::period::num << endl;
    cout << chrono::steady_clock::period::den << endl;
    cout << boolalpha << chrono::steady_clock::is_steady << endl;

}
