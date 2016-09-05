#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    string::size_type longest = 0;
    unordered_map<char, string::size_type> hashtable;
    for (string::size_type p = 0, q = 0; q < s.size(); q++) {
        string::size_type thislength = q - p + 1;
        if (thislength >= longest) { longest = thislength; }
        hashtable[s[q]] = q;
        if (q + 1 < s.size()) {
            auto i = hashtable.find(s[q+1]);
            if (i != hashtable.end() && i->second >= p ){
                p = i->second + 1;
                hashtable[s[p]] = p;
            }
        }
    }
    return longest;
}

int main()
{
    cout << lengthOfLongestSubstring("aaab") << endl;
}
