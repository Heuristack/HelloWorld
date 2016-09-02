#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> dynamic_array = {"A", "B", "C", "D"};
    set<string> binary_search_tree(dynamic_array.begin(), dynamic_array.end());

    rotate(dynamic_array.begin(), dynamic_array.begin()+1, dynamic_array.end());
    for (string e : dynamic_array) cout << e << " ";
    cout << endl;

    rotate(dynamic_array.rbegin(), dynamic_array.rbegin()+1, dynamic_array.rend());
    for (string e : dynamic_array) cout << e << " ";
    cout << endl;

    vector<string>::const_iterator arraypos = find(dynamic_array.begin(), dynamic_array.end(), "C");
    set<string>::const_iterator treepos = binary_search_tree.find("C");

    dynamic_array.erase(arraypos);
    binary_search_tree.erase(treepos);

    for (string e : dynamic_array) cout << e << " "; cout << endl;
    for (string e : binary_search_tree) cout << e << " "; cout << endl;
}
