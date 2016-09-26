#include <iostream>
#include <string>
#include <memory>
using namespace std;

int main()
{
    // can't be initialized by assignment but only by constructor
    unique_ptr<string> up(new string("Hello,World!"));

    // release the ownership
    auto rp = up.release();
    cout << *rp << endl;

    // own an object or not? operator bool()
    if (up == nullptr || !up || !up.get()) cout << "Empty unique pointer!" << endl;
}
