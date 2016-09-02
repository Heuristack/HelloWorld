#include <iostream>
#include <string>

using namespace std;

class Peer;
class Command {
    Peer * receiver;
    void (Peer:: * request)();
public:
    Command(Peer * peer = nullptr, void (Peer::*operation)() = nullptr): receiver(peer), request(operation){}
    void execute(){ if(receiver && request) (receiver->*request)(); }
};

class Peer {
    string name;
    Command command;
public:
    Peer(const string & nm, Command cmd): name(nm), command(cmd){}

    void send(){ cout << name << " is sending ... " << endl; command.execute(); }
    void recv(){ cout << name << " is recving ... " << endl; command.execute(); }
    void work(){ cout << name << " is working ... " << endl; command.execute(); }

};

int main()
{
    Peer F("F", Command());
    Peer E("E", Command(&F, &Peer::recv));
    Peer D("D", Command(&E, &Peer::work));

    D.send();
}
