#include <forward_list>
#include <iterator>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    forward_list<string> list { "Hello", "Forward", "List", "Iterator" };
    for (forward_list<string>::iterator i = list.begin(); i != list.end(); i++) cout << *i << endl;
}
