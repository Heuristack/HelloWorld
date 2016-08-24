#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector<string> vector = {"Hello", "World"};
    copy(vector.begin(), vector.end(), ostream_iterator<string>(cout, ","));
    cout << "\b" << " " << "\b" << "!" << endl;
}
