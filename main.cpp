#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::cout;
using std::endl;

int main()
{
    static bool try_to_capture_me = false;
    cout << [](){ return try_to_capture_me = true; }() << endl;
    cout << try_to_capture_me << endl;
}
