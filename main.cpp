#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

int main()
{
    string s = {"tcp://127.0.0.1:9"};

    s.erase(0, s.find("://") + string("://").size());
    s.erase(s.begin(), find(s.begin(), s.end(), ':')+1);

    assert(stoi(s) == 9);
}
