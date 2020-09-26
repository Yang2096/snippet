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

ListNode* swapPairs(ListNode* head) {
    ListNode before_head(0);
    ListNode * before = &before_head;
    ListNode * current = head;
    before->next = current;
    while(current != nullptr)
    {
        if(current->next != nullptr)
        {
            before->next = current->next;
            current->next = current->next->next;
            before->next->next = current;
            before = current;
            current = current->next;
        }
        else
        {
            break;
        }
    }
    return before_head.next;
}