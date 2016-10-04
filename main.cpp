#include <iostream>
using namespace std;

int main()
{
    cout << __cplusplus << endl;
    cout << __clang__ << endl;
    cout << __VERSION__ << endl;

    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    cout << __DATE__ << endl;
    cout << __TIME__ << endl;

    cout << __STDC__ << endl;
    cout << __STDC_HOSTED__ << endl;

    cout << __APPLE__ << endl;
    cout << __MACH__ << endl;
}
