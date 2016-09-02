#include <iostream>
#include <string>
using namespace std;

struct object_type { void member_function(string s){ cout << s << endl; } };

int main()
{
    void (object_type:: * pointer_to_member_function)(string) = &object_type::member_function;

    object_type object;
    (object.*pointer_to_member_function)("[object.]");

    object_type * pointer_to_object;
    (pointer_to_object->*pointer_to_member_function)("[pointer->]");
}
