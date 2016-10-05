#include <iostream>
using namespace std;

int main()
{
    bool test = true;
    int casenum = 2;
    if (test) {
        switch(casenum) {
            case 1:
            case 2:
                cout << "location 1" << endl;
                // break;
            default:
                cout << "location 2" << endl;
        }
        cout << "location 3" << endl;
    }
    else {
        cout << "location 4" << endl;
    }
    cout << "location 5" << endl;
}
