#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr) return head;
    ListNode ans(head->val);
    ans.next = head;
    ListNode* prev = head, *pprev = &ans;
    int val = head->val, count = 0;
    head = head->next;
    while(head != nullptr)
    {
        if(head->val == val)
        {
            ++count;
            pprev->next = head->next;
            prev = head->next;
            if(prev != nullptr)
            {
                if(val != prev->val)
                {
                    count = 0;
                }
                val = prev->val;
            }
        }
        else
        {
            if(count == 0)
            {
                pprev = prev;    
            }
            else
            {
                pprev->next = head;
            }
            val = head->val;
            count = 0;
            prev = head;
        } 
        
        if(prev != nullptr)
            head = prev->next;
        else
            break;
    }
    if(prev != nullptr)
    {
        if(count != 0 && val == prev->val)
            pprev->next = prev->next;
    }
    return ans.next;
}