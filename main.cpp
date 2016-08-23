#include <iostream>

bool* toggle(bool doors[], int num, int person)
{
    for (int i = 1; i <= num; i += person)
        doors[i] = !doors[i];
    return doors;
}

int main()
{
    constexpr int num = 500;
    bool doors[num+1] = {};
    for (int i = 1; i <= num; i++) toggle(doors, num, i);
    for (int i = 1; i <= num; i++) if (doors[i]) std::cout << i << std::endl;
}
