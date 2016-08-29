#include <iostream>
#include <string>

using namespace std;

class Prototype {
public:
    virtual auto clone() -> Prototype * = 0;
};

class ConcretePrototype : public Prototype {
    string state;
public:
   ~ConcretePrototype() = default;
    ConcretePrototype(const string & s): state(s){}
    ConcretePrototype(): ConcretePrototype("Initialized by default!"){}
    ConcretePrototype(const ConcretePrototype & that_reference){ state = that_reference.state; }
    virtual auto clone() -> ConcretePrototype * override { return new ConcretePrototype(*this); }

    friend ostream & operator<<(ostream & s, ConcretePrototype & o){ return s << "[" << o.state << "]"; }
};

int main()
{
    ConcretePrototype prototype("prototype");

    ConcretePrototype * cloned = prototype.clone();
    cout << *cloned << endl;
    delete cloned;

    cout << prototype << endl;
}
