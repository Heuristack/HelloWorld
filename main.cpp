#include <iostream>

using namespace std;

void noordefault(){ cout << "0" << endl; }
void noordefault(int m = 0){ cout << "1" << endl; }

int main()
{
//  noordefault();  // this call is ambiguous
    noordefault(10);
}
