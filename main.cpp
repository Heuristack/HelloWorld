#include <iostream>
#include <vector>
#include <forward_list>
#include <deque>
#include <list>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> vector(10,1);
    forward_list<int> forward_list(10);
    deque<int> deque(10);
    list<int> list(10);
    partial_sum(vector.begin(), vector.end(), vector.begin());

    cout << *rotate_copy(vector.begin(), vector.begin()+1, vector.end(), forward_list.before_begin()) << endl;
    cout << *rotate_copy(vector.begin(), vector.begin()+1, vector.end(), list.begin()) << endl;
    cout << *rotate_copy(vector.begin(), vector.begin()+1, vector.end(), deque.begin()) << endl;

    for (auto & e : vector) cout << e << " "; cout << endl;
    for (auto & e : forward_list) cout << e << " "; cout << endl;
    for (auto & e : list) cout << e << " "; cout << endl;
    for (auto & e : deque) cout << e << " "; cout << endl;
}
