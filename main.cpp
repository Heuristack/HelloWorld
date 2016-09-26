#include <iostream>
#include <memory>
using namespace std;

class Testable {
    bool status = true;
public:
   ~Testable() = default;
    Testable() = default;
    Testable(bool s): status(s){}

    explicit operator bool() const { return status; }
};

int main()
{
    Testable condition(false);
    if (!condition) cout << "!" << endl;

    // only explicit conversion is permitted
    bool converted = static_cast<bool>(condition);
}
