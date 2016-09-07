#include <iostream>
#include <forward_list>
#include <iterator>
using namespace std;

template<typename container_type, typename const_iterator_type = typename container_type::const_iterator>
void print(const container_type & container)
{
    cout << "{";
    for (const_iterator_type i = container.begin(); i != container.end(); i++) { cout << *i; if (next(i) != container.end()) cout << ","; }
    cout << "}";
    cout << endl;
}

int main()
{
    forward_list<int> linklist = {1,2,3,4,5,97,98,99};
    print(linklist);

    forward_list<int> linklist_copy(linklist);

    linklist.push_front(5);
    print(linklist);

    linklist.remove(5);
    print(linklist);

    for (forward_list<int>::const_iterator pos_before = linklist.before_begin(); next(pos_before) != linklist.end(); ++pos_before) {
        if (*next(pos_before) % 2 == 0) { linklist.erase_after(pos_before); }
        
    }
    print(linklist);

    linklist.sort(greater<int>());
    print(linklist);

    linklist.reverse();
    print(linklist);

    linklist.merge(linklist_copy);
    print(linklist);
}
