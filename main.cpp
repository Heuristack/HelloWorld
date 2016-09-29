#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <ratio>
#include <exception>
#include <system_error>
#include <vector>
#include <algorithm>
using namespace std;

int m = 4;
int main()
try {
    using limit = numeric_limits<unsigned>;

    cout << limit::max() << endl;
    cout << fixed << setprecision(0) << pow(limit::radix, limit::digits) - 1 << endl;
    cout << mega::num << endl;
    cout << giga::num << endl;

    error_code ec{};
    cout << ec.message() << endl;

    vector<int> container = {1,2,3,4,5,6,7,8};
    for_each(container.begin(), container.end(), [](int e){ cout << e << " "; });
    cout << endl;

    replace_if(container.begin(), container.end(), [](int e){ return e < m; }, 5);
    m = 6;
    replace_if(container.begin(), container.end(), [](int e){ return e < m; }, 5);
    for_each(container.begin(), container.end(), [](int e){ cout << e << " "; });
    cout << endl;
}
catch(exception e){ cout << e.what() << endl; }
catch(...){}
