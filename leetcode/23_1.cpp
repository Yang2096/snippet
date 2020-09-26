#include "pch.h"
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL){}
                                   
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode*>, function<bool(ListNode *, ListNode *)>> heap([](ListNode *a, ListNode *b) {
        return a->val < b->val;
    });
    for(auto l : lists)
        if(l) 
            heap.push(l);
    ListNode fake_head(0);
    ListNode *temp = &fake_head;
    while (!heap.empty())
    {
        temp->next = heap.top();
        temp = temp->next;
        heap.pop();
        if(temp->next)
        {
            heap.push(temp->next);
        }
    }
    return fake_head.next;
}