#include <dispatch/dispatch.h>
#include <stdio.h>

int main()
{
    dispatch_queue_t main_q = dispatch_get_main_queue();

    dispatch_async(main_q, ^{ printf("Hello,World!"); });

    dispatch_main();
    return 0;
}
