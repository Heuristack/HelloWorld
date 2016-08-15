#include <unordered_map>
#include <map>
#include <string>
#include <iostream>

using namespace std;

int main()
{

    map<string, int> m { {"Dijkstra",1972}, {"Scott",1976}, {"Wilkes",1967}, {"Hamming",1968} };
    m["Ritchie"] = 1983;
    for (auto x : m) cout << '{' << x.first << ',' << x.second << '}';
    cout << endl;

    unordered_map<string, int> um { {"Dijkstra",1972}, {"Scott",1976}, {"Wilkes",1967}, {"Hamming",1968} };
    um["Ritchie"] = 1983;
    for (auto x : um) cout << '{' << x.first << ',' << x.second << '}';
    cout << endl;
}
