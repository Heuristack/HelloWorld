#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> two_sum(vector<int> nums, int target)
{
    vector<int> two;
    unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); i++) {
        auto r = hashtable.find(nums[i]);
        if (r != hashtable.end()) {
            two.push_back(r->second);
            two.push_back(i);
        }
        int tomatch = target - nums[i];
        hashtable.insert(make_pair(tomatch, i));
    }
    return two;
}

int main()
{
    for (auto x : two_sum({2, 7, 11, 15}, 9)) cout << x << endl;
}
