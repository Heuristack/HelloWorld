#include <iostream>
#include <string>
#include <map>
#include <tuple>
#include <utility>

using namespace std;

int main()
{
    map<string, string> m;
    m.emplace(make_pair(string("a"), string("a")));
    m.emplace(make_pair("b", "bb"));
    m.emplace("c", "ccc");
    m.emplace(piecewise_construct, forward_as_tuple("d"), forward_as_tuple(4, 'd')); // pair's piecewise constructor

    string key, value;
    for (pair<string, string> p : m) { tie(key, value) = p; cout << key << ": " << value << endl; }
}
