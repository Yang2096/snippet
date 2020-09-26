#include<iostream>
#include<stack>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    stack<int> s1, s2;
    while(l1)
    {
        s1.push(l1->val);
        l1 = l1->next;
    }

    while(l2)
    {
        s2.push(l2->val);
        l2 = l2->next;
    }

    if(s1.size() < s2.size())
        s1.swap(s2);

    ListNode head(-1),
    int val, count = 0;
    while (!s2.empty())
    {
        val = s2.top() + s1.top() + count;
        count = val / 10;
        val = val % 10;
        ListNode *new_node = new ListNode(val);
        new_node->next = head.next;
        head.next = new_node;
        s1.pop();
        s2.pop();
    }

    while(!s1.empty())
    {
        val = s1.top() + count;
        count = val / 10;
        val = val % 10;
        ListNode *new_node = new ListNode(val);
        new_node->next = head.next;
        head.next = new_node;
        s1.pop();
    }
    if(count)
    {
        ListNode *new_node = new ListNode(1);
        new_node->next = head.next;
        head.next = new_node;
    }
    return head.next;
}