#include<iostream>
#include<vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode *sortList(ListNode *head)
{
    if(head == nullptr)
        return nullptr;
    
    ListNode *h1 = head, *h2 = head;
    int length = 0;
    while(h1)
    {
        h1 = h1->next;
        ++length;
    }

    ListNode fakeHead(-1), *prev;
    fakeHead.next = head;
    int size = 1, count1, count2;
    while(size < length)
    {
        prev = &fakeHead;
        while(prev)
        {
            h2 = h1 = prev->next;
            count1 = size;
            while (count1-- && h2)
                h2 = h2->next;
            if(!h2)
                break;
            count1 = size;
            count2 = size;
            while (count1 && count2 && h2)
            {
                if(h1->val <= h2->val)
                {
                    prev->next = h1;
                    h1 = h1->next;
                    --count1;
                }
                else
                {
                    prev->next = h2;
                    h2 = h2->next;
                    --count2;
                }
                prev = prev->next;
            }

            if(count1)
            {
                prev->next = h1;
                while(count1--)
                    prev = prev->next;
                prev->next = h2;
            }
            else
            {
                prev->next = h2;
                while(count2-- && prev)
                    prev = prev->next;
            }
        }
        size <<= 1;
    }
    return fakeHead.next;
}

int main()
{
    vector<int> l = {4, 3, 8, 7, 2, 6, 9, 5};
    ListNode fakeHead(0), *prev;
    prev = &fakeHead;
    for(int a : l)
    {
        prev->next = new ListNode(a);
        prev = prev->next;
    }

    prev = sortList(fakeHead.next);

    while(prev)
    {
        cout << prev->val << ' ';
        prev = prev->next;
    }
    cout << endl;
}
