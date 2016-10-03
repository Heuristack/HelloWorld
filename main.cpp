#include <iostream>
#include <string>
#include <type_traits>

using std::cout;
using std::endl;

enum class WeekDay : unsigned { Sun, Mon, Tue, Wed, Thu, Fri, Sat };

std::ostream & operator<<(std::ostream & os, WeekDay wd)
{
    std::string s;
    switch (wd) {
        case WeekDay::Sun:
            s = "Sunday";
            break;
        case WeekDay::Mon:
            s = "Monday";
            break;
        case WeekDay::Tue:
            s = "Tuesday";
            break;
        case WeekDay::Wed:
            s = "Wednesday";
            break;
        case WeekDay::Thu:
            s = "Thursday";
            break;
        case WeekDay::Fri:
            s = "Friday";
            break;
        case WeekDay::Sat:
            s = "Saturday";
            break;
        default:
            s = "Unknown";
            break;
    }
    return os << s;
}

int main()
{
    WeekDay wd = WeekDay::Mon;
    cout << wd << endl;
    cout << WeekDay::Sun << endl;

    using WeekDay::Sat;
    cout << Sat << endl;

    cout << std::is_enum<WeekDay>::value << endl;
    cout << std::is_class<WeekDay>::value << endl;

    cout << std::is_object<WeekDay>::value << endl;
    cout << std::is_compound<WeekDay>::value << endl;
}
