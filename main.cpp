#include <iostream>
#include <string>
using namespace std;

bool is_subsequence(string s, string t)
{
    if (s.empty()) return true;
    int i = 0;
    for (int k = 0; k < t.size(); k++) {
        if (s[i] == t[k]) i++;
        if (i == s.size() - 1) break;
    }
    if (i == s.size() - 1) return true;
    else return false;
}

int main()
{
    cout << is_subsequence("", "ahbgdc") << endl;
    cout << is_subsequence("abc", "ahbgdc") << endl;
    cout << is_subsequence("axc", "ahbgdc") << endl;
}
