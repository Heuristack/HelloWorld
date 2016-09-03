#include <iostream>
#include <string>
using namespace std;

class Colleague;
class Mediator {
public:
    virtual ~Mediator(){}
    virtual void send(string message, Colleague * colleague) = 0;
};

class ConcreteMediator : public Mediator {
    Colleague * thisone = nullptr;
    Colleague * thatone = nullptr;
public:
    void send(string message, Colleague * colleague);
    void registerthis(Colleague * colleague){ thisone = colleague; }
    void registerthat(Colleague * colleague){ thatone = colleague; }
};

class Colleague {
protected:
    Mediator & mediator;
public:
    Colleague(Mediator & m): mediator(m){}
    void send(string message){ mediator.send(message, this); }
    virtual void notify(string message) = 0;
};

void ConcreteMediator::send(string message, Colleague * colleague) {
    if (colleague == thisone) thatone->notify(message);
    if (colleague == thatone) thisone->notify(message);
}

class ConcreteColleague : public Colleague {
public:
    using Colleague::Colleague;
    void notify(string message){ cout << "ConcreteColleague: " << message << endl; }
};

class DefiniteColleague : public Colleague {
public:
    using Colleague::Colleague;
    void notify(string message){ cout << "DefiniteColleague: " << message << endl; }
};

int main()
{
    ConcreteMediator mediator;
    ConcreteColleague concrete(mediator);
    DefiniteColleague definite(mediator);

    mediator.registerthis(&concrete);
    mediator.registerthat(&definite);

    concrete.send("Hi! How are you?");
    definite.send("I am fine! Thank you! And you?");
    concrete.send("I am fine too!");
}
