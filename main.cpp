#include <iostream>
#include <iomanip>
#include <unordered_map>
#include <string>
#include <iterator>
#include <utility>
#include <typeinfo>

using namespace std;

template<typename K, typename T>
ostream & operator<<(ostream & s, pair<K,T> p){ return s << "[" << p.first << "," << p.second << "]"; }

template <typename T>
void print_hashtable_state(T hashtable)
{
    cout << "size:              " << hashtable.size() << endl;
    cout << "bucket size:       " << hashtable.bucket_count() << endl;
    cout << "load factor:       " << hashtable.load_factor() << endl;
    cout << "max load factor:   " << hashtable.max_load_factor() << endl;

    for (unsigned int i = 0; i != hashtable.bucket_count(); i++) {
        cout << "bucket [" << setw(2) << i << "]: ";
        for (auto p = hashtable.begin(i); p != hashtable.end(i); p++)
            cout << *p << " ";
        cout << endl;
    }
    return;
}

int main()
{
    unordered_map<string, string> hashtable = {{"S","Sunday"},{"M","Monday"},{"T", "Tuesday"}};
    print_hashtable_state(hashtable);

    hashtable.insert({"W","Wednesday"});
    print_hashtable_state(hashtable);

    cout << hashtable["W"] << endl;
    if (hashtable.find("W") != hashtable.end()) cout << "Found" << endl;
}
