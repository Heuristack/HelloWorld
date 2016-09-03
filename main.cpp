#include <iostream>
#include <list>
#include <memory>
using namespace std;

class Context {};

class AbstractExpression {
public:
    virtual ~AbstractExpression(){}
    virtual void interpret(Context &) = 0;
};

class TerminalExpression : public AbstractExpression
{
public:
    void interpret(Context & context) override { cout << "T"; }
};
class NonterminalExpression : public AbstractExpression {
public:
    void interpret(Context & context) override { cout << "N"; }
};

int main()
{
    Context context;

    list<unique_ptr<AbstractExpression>> abstract_syntax_tree;

    abstract_syntax_tree.push_back(make_unique<TerminalExpression>());
    abstract_syntax_tree.push_back(make_unique<NonterminalExpression>());
    abstract_syntax_tree.push_back(make_unique<TerminalExpression>());
    abstract_syntax_tree.push_back(make_unique<TerminalExpression>());

    for (const unique_ptr<AbstractExpression> & expr : abstract_syntax_tree)
        expr->interpret(context);

    cout << endl;
}
