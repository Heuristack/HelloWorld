#include <iostream>
#include <string>
#include <regex>

using std::cout;
using std::endl;

int main()
{
    std::string message = "|58=Client tried to increment outgoing seqNum too much (99994430)|";
    cout << message << endl;

    std::regex expression(R"(seqnum)(too)", std::regex_constants::icase);
    cout << std::regex_search(message, expression) << endl;

    std::string m(message.data()+1, message.size()-1);
    cout << m << endl;
}
