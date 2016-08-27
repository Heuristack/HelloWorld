#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>

using namespace std;

class Component {
public:
    virtual~Component(){}
    virtual void traverse() = 0;
};

class Leaf : public Component {
    string state = 0;
public:
    Leaf(const string & s): state(s){}
    void traverse() override { cout << state; }
};

class Composite : public Component {
    vector<Component*> children;
public:
    void add(Component * component)
    {
        children.push_back(component);
    }
    void traverse() override
    {
        for (Component * component : children) component->traverse();
    }
};

int main()
{
    Composite root, node;
    Leaf a("a"),b("b"),c("c"),d("d");

    root.add(&a);
    root.add(&node);

    node.add(&b);
    node.add(&c);
    node.add(&d);

    root.traverse();
    atexit([](){ cout << endl; });
}
