#include <cstring>
#include <cstdio>

int main()
{
    const char s[] = "Hello,World!";
    const char * p = "Hello,World!";

    printf("size: %d\n", sizeof(s));
    printf("length: %d\n", strlen(s));

    printf("size: %d\n", sizeof(p));
    printf("length: %d\n", strlen(p));

}
