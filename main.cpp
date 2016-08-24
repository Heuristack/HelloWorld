#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    vector<int> vector(10,1);
    for (auto & e : vector) cout << e << " "; cout << endl;

    partial_sum(vector.begin(), vector.end(), vector.begin());
    for (auto & e : vector) cout << e << " "; cout << endl;

    adjacent_difference(vector.begin(), vector.end(), vector.begin());
    for (auto & e : vector) cout << e << " "; cout << endl;
}
