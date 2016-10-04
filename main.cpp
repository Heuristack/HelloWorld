#include <iostream>
#include <type_traits>
#include <string>

using std::cout;
using std::endl;

int main()
{
    cout << std::is_constructible<std::string>::value << endl;
    cout << std::is_default_constructible<std::string>::value << endl;
    cout << std::is_copy_constructible<std::string>::value << endl;
    cout << std::is_move_constructible<std::string>::value << endl;

    cout << std::is_assignable<std::string, std::string>::value << endl;
    cout << std::is_copy_assignable<std::string>::value << endl;
    cout << std::is_move_assignable<std::string>::value << endl;

    cout << std::is_destructible<std::string>::value << endl;
}
