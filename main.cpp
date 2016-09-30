#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using std::cout;
using std::endl;

int main()
{
    std::vector<int> v {};
    for (int i = 0; i < v.size() - 1; i++)
        cout << "i = " << i << endl;
}
