#include <iostream>
#include <utility>
#include <string>

using namespace std;

int main()
{
    // min and max
    cout << min({2,4,6,8,3}) << endl;
    cout << max(nano::den, mega::num) << endl;
    cout << minmax({10,2,4,8,1}).first << endl;

    // ratio
    typedef typename ratio<1,30>::type onethird_t;
    cout << "1/30 := [numerator = " << onethird_t::num << "; " << "denominator = " << onethird_t::den << "]" << endl;
    cout << "nano := [numerator = " << nano::num << "; " << "denominator = " << nano::den << "]" << endl;
    cout << exa::num << endl;

    // comparison operators deduction
    class X {
        string state = "0";
    public:
        X(const string & s): state(s){}
        X(): X(""){}
        bool operator==(const X & that_reference) const { return state[0] == that_reference.state[0]; }
        bool operator <(const X & that_reference) const { return state[0]  < that_reference.state[0]; }
        ostream & puts(ostream & s) const { return s << "X = [" << state << "]"; }
    };

    using namespace std::rel_ops;

    X this_x("1");
    X that_x("2");
    if (this_x != that_x) cout << "!=" << endl;
    if (this_x <= that_x) cout << "<=" << endl;

    // swap
    swap(this_x, that_x);
    if (this_x >  that_x) cout << "> " << endl;
    if (this_x >= that_x) cout << ">=" << endl;

    this_x.puts(cout) << endl;
    that_x.puts(cout) << endl;

    min({this_x, that_x}).puts(cout) << endl;
    max({this_x, that_x}).puts(cout) << endl;
}
