#include <iostream>
#include <set>
#include <iterator>
using namespace std;

template<typename container_type, typename iterator_type = typename container_type::iterator>
void print(const container_type & tree)
{
    cout << "{";
    for (iterator_type i = tree.begin(); i != tree.end(); i++) { cout << *i; if (next(i) != tree.end()) cout << ","; }
    cout << "}";
    cout << endl;
}

template<typename container_type, typename iterator_type = typename container_type::iterator, typename value_type = typename container_type::value_type>
void bounds(const container_type & tree, value_type value)
{
    cout << "lower bound = " << *tree.lower_bound(value) << endl;
    cout << "upper bound = " << *tree.upper_bound(value) << endl;
    iterator_type p, q;
    tie(p, q) = tree.equal_range(value);
    cout << "equal range = " << *p << ":" << *q << endl;

    cout << "elements in the equal range := [" << *p << "," << *q << ") = {";
    for (iterator_type i = tree.lower_bound(value); i != tree.upper_bound(value); i++) { cout << *i; if (next(i) != tree.upper_bound(value)) cout << ","; }
    cout << "}";
    cout << endl;
}

int main()
{
    set<int> tree = {1,2,4,5,6};
    print(tree);

    bounds(tree, 3);
    bounds(tree, 5);

    multiset<int> multitree = {1,2,2,2,4,4,5,5,5,5,6};
    print(multitree);

    bounds(multitree, 3);
    bounds(multitree, 5);
}
