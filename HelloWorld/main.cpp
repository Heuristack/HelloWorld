#include <iostream>

const char * return_const_pointer(int n = 0)
{
    char const * s = nullptr;
    switch(n) {
        case 1:
            s = "Hello,World!";
            break;
        case 2:
            s = "GoodBye!";
            break;
        default:
            s = " ";
            break;
    }

//  char * const t = nullptr;
//  t = "can't not change!";
    return s;
}

int main(){ std::cout << return_const_pointer(1) << return_const_pointer() << return_const_pointer(2) << std::endl; }
