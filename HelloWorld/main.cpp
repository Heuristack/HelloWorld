#include <iostream>
#include <thread>
#include <atomic>

std::atomic<bool> ready(false);

void count1m(int id)
{
    while(!ready){
        std::this_thread::yield();
    }
    for (volatile int i = 0; i < 1000000; i++){}
    std::cout << id;
}

int main()
{
    std::thread threads[10];
    for (int i = 0; i < 10; i++) threads[i] = std::thread(count1m,i);
    ready = true;                       // go!
    for (auto & t : threads) t.join();
    std::cout << std::endl;
    return 0;
}
