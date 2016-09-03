#include <iostream>
#include <string>
using namespace std;

int main()
{
    char inputbuf[0xFF];
    while (cin.getline(inputbuf, 0xFF, '\n')) cout << string(inputbuf) << endl;
}
