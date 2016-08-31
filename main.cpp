#include <iostream>
#include <random>

using namespace std;

class NodeHandler {
    NodeHandler * successor = nullptr;
public:
    NodeHandler() = default;
    void set_successor(NodeHandler * s){ successor = s; }
    NodeHandler & add(NodeHandler * s){ if (successor) successor->add(s); else successor = s; return *this; }
    virtual void handle(int i){ if (successor) successor->handle(i); }
};

class HeadHandler : public NodeHandler {
public:
    void handle(int i) override {
        if (i >= 0 && i < 10)
            cout << "H: " << i << endl;
        else
            NodeHandler::handle(i);
    }
};

class BodyHandler : public NodeHandler {
public:
    void handle(int i) override {
        if (i >= 10 && i < 90)
            cout << "B: " << i << endl;
        else
            NodeHandler::handle(i);
    }
};

class TailHandler : public NodeHandler {
public:
    void handle(int i) override {
        if (i >= 90 && i < 100)
            cout << "T: " << i << endl;
        else
            NodeHandler::handle(i);
    }
};

int main()
{
    HeadHandler head;
    BodyHandler body;
    TailHandler tail;

    head.add(&body).add(&tail);     // build the responsibiliy chain

    random_device device;
    default_random_engine engine(device());
    uniform_int_distribution<int> distribution(0,99);

    for (int i = 0; i < 20; i++)
        head.handle(distribution(engine));
}
