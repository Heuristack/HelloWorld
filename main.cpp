#include <iostream>
#include <chrono>
#include <ratio>

using namespace std;

unsigned fibnacci(unsigned n){ if (n < 2) return n; else return fibnacci(n-1) + fibnacci(n-2); }

int main()
{
    using clock = chrono::high_resolution_clock;

    chrono::time_point<clock> timepoint1, timepoint2;
    chrono::nanoseconds interval;

    timepoint1 = clock::now();
    fibnacci(40);
    timepoint2 = clock::now();

    interval = timepoint2 - timepoint1;

    cout << "Interval: " << interval.count() << " nanoseconds" << endl;
}
