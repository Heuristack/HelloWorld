#include <iostream>
#include <random>
#include <map>

int generate_uniform_integers(int a, int b)
{
    std::random_device dev;
    std::uniform_int_distribution<int> dist(a, b);
    return dist(dev);
}

int main()
{
    std::map<int, int> map;
    for (int i = 0; i < 200; i++)
        ++map[generate_uniform_integers(0, 9)];

    for (std::map<int,int>::iterator i = map.begin(); i != map.end(); i++)
        std::cout << i->first << ": " << std::string(i->second, '*') << std::endl;
}

