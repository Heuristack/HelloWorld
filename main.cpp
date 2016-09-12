#include <functional>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <vector>
#include <map>
#include <limits>
#include <random>
#include <chrono>
#include <string>
#include <ratio>
#include <iostream>
#include <iomanip>
using namespace std;

template<typename Distribution, typename Engine>
void print_distribution_shape(Distribution d, Engine e, const string & s)
{
    cout << s << ": ";
    cout << "min = " << d.min() << ", max = " << d.max() << "\n";

    map<long long, int> histogram;
    for (int i = 0; i < hecto::num * 2; ++i) ++histogram[d(e)];
    cout << "=====\n";
    for (const pair<int, int> & p : histogram) cout << "[" << setw(3) << p.first << "]: " << string(p.second, '*') << "\n";
    cout << "=====\n";
}

int main()
{

    // limits of integers
    using integer_limits = numeric_limits<int>;
    cout << "limits of integers: ";
    cout << "has infinity = " << integer_limits::has_infinity << ", ";
    cout << "digits = " << integer_limits::digits10 << ", ";
    cout << "min = " << numeric_limits<int>::min() << ", max = " << numeric_limits<int>::max();
    cout << "\n";

    // non-deterministic random device (random number generator)
    cout << "properties of random device: ";
    random_device device;
    cout << "entropy = " << device.entropy() << ", ";
    cout << "min = " << device.min() << ", max = " << device.max();
    cout << "\n";
    map<int,int> device_histogram;
    for (int i = 0; i < 10000; ++i) ++device_histogram[device()];
    for (const pair<int, int> & p : device_histogram) if (p.first % 10 == 0 && p.first > 2 * giga::num) cout << p.first << ": " << p.second << "\n";
    cout << "\n";

    // random engines and distributions
    default_random_engine engine;
    normal_distribution<> normal(0,4);
    print_distribution_shape(normal, engine, "Normal Distribution");

    lognormal_distribution<> lognormal;
    print_distribution_shape(lognormal, engine, "Log-Normal Distribution");
}
