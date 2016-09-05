#include <cassert>
#include <iostream>
#include <list>
using namespace std;

struct ListNode {
    int val;
    ListNode * next = nullptr;
    ListNode(int x):val(x), next(nullptr){}
};

void print_list(ListNode * l)
{
    cout << "[";
    for (ListNode * p = l; p != nullptr; p = p->next) {
        cout << p->val;
        if (p->next) cout << ",";
    }
    cout << "]" << endl;
}

ListNode * create_list(list<int> integer_list)
{
    ListNode * head = nullptr, * tail = nullptr;
    
    for (list<int>::iterator i = integer_list.begin(); i != integer_list.end(); ++i) {
        int v = *i;
        ListNode * current = new ListNode(v);
        if (head == nullptr) { tail = current; head = tail; }
        else {
            assert(tail->next == nullptr);
            tail->next = current;
            assert(tail->next != nullptr);
            tail = tail->next;
        }
    }
    print_list(head);
    return head;
}

ListNode * add_two_numbers(ListNode * l1, ListNode * l2)
{
    ListNode * head = nullptr, * tail = nullptr;
    int last_quotient = 0;
    for (ListNode * p1 = l1, * p2 = l2; p1 != nullptr || p2 != nullptr; ) {
        int sum = last_quotient;
        if (p1 != nullptr) sum += p1->val;
        if (p2 != nullptr) sum += p2->val;
        last_quotient = sum / 10;
        sum = sum % 10;
        
        ListNode * current = new ListNode(sum);
        if (head == nullptr) { tail = current; head = tail; }
        else {
            assert(tail->next == nullptr);
            tail->next = current;
            assert(tail->next != nullptr);
            tail = tail->next;
        }
        
        if (p1 != nullptr) p1 = p1->next;
        if (p2 != nullptr) p2 = p2->next;
    }
    if (last_quotient > 0) {
        ListNode * last = new ListNode(last_quotient);
        assert(tail->next == nullptr);
        tail->next = last;
        assert(tail->next != nullptr);
        tail = tail->next;
    }
    return head;
}

int main()
{
    ListNode * l1 = create_list({2,3,5,9});
    ListNode * l2 = create_list({1,7,6});
    
    print_list(add_two_numbers(l1, l2));
}
