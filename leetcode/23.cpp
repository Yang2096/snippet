#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}

};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 1) return lists[0];
    auto cmp = [](ListNode * a, ListNode * b) -> bool {
        return a->val > b->val;
    };
    priority_queue<ListNode*,std::vector<ListNode*>, decltype(cmp)> heap(cmp);
    for(auto node : lists)
    {
        if(nullptr != node)
            heap.push(node);
    }
    ListNode head(0);
    ListNode * current = &head;
    while(!heap.empty())
    {
        current->next = heap.top();
        heap.pop();
        current = current->next;
        if(current->next != nullptr)
        {
            heap.push(current->next);
        }
    }
    return head.next;
}