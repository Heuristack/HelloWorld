#include <iostream>
#include <functional>
using namespace std;

void passingbyreference(int & n1, int & n2, int const & n3)
{
    cout << "I: [" << n1 << ", " << n2 << ", " << n3 << "]" << endl;
    ++n1;
    ++n2;
    cout << "I: [" << n1 << ", " << n2 << ", " << n3 << "]" << endl;
}

int main()
{
    int n1 = 11, n2 = 12, n3 = 13;

    function<void()> bounded = bind(passingbyreference, n1, ref(n2), cref(n3));

    n1 = 21, n2 = 22, n3 = 23;

    cout << "B: [" << n1 << ", " << n2 << ", " << n3 << "]" << endl;
    bounded();
    cout << "A: [" << n1 << ", " << n2 << ", " << n3 << "]" << endl;
}
