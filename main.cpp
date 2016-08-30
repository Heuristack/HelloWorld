#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Element {
public:
    virtual ~Element(){}
    virtual void accept(class Visitor & visitor) = 0;
    static string classname(){ return typeid(Element).name(); }
};

class ConcreteElement : public Element {
public:
    void accept(Visitor & visitor) override;
    string classname(){ return typeid(*this).name(); }
};

class DefiniteElement : public Element {
public:
    void accept(Visitor & visitor) override;
    string classname(){ return typeid(*this).name(); }
};

class Visitor {
public:
    virtual void visit(ConcreteElement * element) = 0;
    virtual void visit(DefiniteElement * element) = 0;
};

void ConcreteElement::accept(Visitor & visitor){ visitor.visit(this); }
void DefiniteElement::accept(Visitor & visitor){ visitor.visit(this); }

class ForewardVisitor : public Visitor {
public:
    void visit(ConcreteElement * element) override { cout << "Foreward -> " << element->classname() << endl; }
    void visit(DefiniteElement * element) override { cout << "Foreward -> " << element->classname() << endl; }
};

class BackwardVisitor : public Visitor {
public:
    void visit(ConcreteElement * element) override { cout << "Backward -> " << element->classname() << endl; }
    void visit(DefiniteElement * element) override { cout << "Backward -> " << element->classname() << endl; }
};

int main()
{
    ForewardVisitor fv;
    BackwardVisitor bv;

    ConcreteElement concrete;
    DefiniteElement definite;

    concrete.accept(fv);
    concrete.accept(bv);

    definite.accept(fv);
    definite.accept(bv);
}
