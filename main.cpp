#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::endl;

int main()
{
    std::stringstream stream {"a,b,c"};
    for (std::string s; std::getline(stream, s, ','); cout << s << endl);
}
