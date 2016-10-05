#include <iostream>

enum level { warning = 2, notice = 3};

int main()
{
    level l;
    l = warning;

    switch (l) {
        case warning:
        case notice:
            std::cout << l << std::endl;
            break;
    }
}
