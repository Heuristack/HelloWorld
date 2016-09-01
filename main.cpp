#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <tuple>

using namespace std;

int main()
{
    set<string> stringset;
    set<string>::iterator iterator;
    bool result;

    tie(iterator, ignore) = stringset.insert("Hello,World!");
    tie(ignore, result) = stringset.insert("Hello,World!");

    cout << *iterator << endl;
    cout << boolalpha << result << endl;
}
