#include <iostream>
#include <string>
using namespace std;

struct base_type { void member_function(string s){ cout << s << endl; } };
struct derived_type : base_type {};

int main()
{
    void (base_type:: * base_pointer_to_member_function)(string) = &base_type::member_function;
    void (derived_type:: * derived_pointer_to_member_function)(string) = base_pointer_to_member_function;

    derived_type derived_object;
    (derived_object.*derived_pointer_to_member_function)("derived");
    (derived_object.*base_pointer_to_member_function)("base");
}
