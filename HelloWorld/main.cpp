#include <stdio.h>
#include <time.h>

int main()
{
    int i = !time(NULL);

    if (!i)
        puts("No optimization!");

    if (!__builtin_expect(i,0))
        puts("Weight branch by '__builtin_expect' instruction!");
}
