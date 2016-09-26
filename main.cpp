#include <iostream>
using namespace std;

class Testable {
    bool status = true;
public:
   ~Testable() = default;
    Testable() = default;
    Testable(bool s): status(s){}

    operator bool(){ return status; }
};

int main()
{
    Testable condition(false);
    if (!condition) cout << "!" << endl;
}
