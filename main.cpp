#include <iostream>
#include <vector>
#include <algorithm>

class T {
    int state = -1;
public:
    T(int s): state(s){}
    T(): T(0){}
    int get () const { return state; }
};
using namespace std;
int main()
{
    std::vector<T> v = {T(), T{2}};

    auto last_legal_position_to_retate = v.begin() + v.size();
    rotate(v.begin(), last_legal_position_to_retate, v.end());
    cout << v.front().get() << endl;

    v.erase(v.begin());
    cout << v.front().get() << endl;
    cout << v[0].get() << endl;
}
