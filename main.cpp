#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::cout;
using std::endl;

int main()
{
    cout << (unsigned)-1 << endl;
    cout << static_cast<unsigned>(-1) << endl;
    cout << -1U << endl;

    cout << UINT_MAX << endl;
    cout << std::numeric_limits<unsigned int>::max() << endl;

    cout << 0U - 1 << endl;
}
