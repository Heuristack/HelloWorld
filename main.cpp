#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::cout;
using std::endl;

int main()
{
    bool try_to_capture_me = false;
    cout << [=]() mutable { return try_to_capture_me = true; }() << endl;
    cout << try_to_capture_me << endl;
}
