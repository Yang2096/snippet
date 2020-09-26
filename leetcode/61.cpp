#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(nullptr) {}
 };

ListNode* rotateRight(ListNode* head, int k) {
    int length = 0;
    decltype(head) tail, temp = head;
    while(temp != nullptr)
    {
        ++length;
        tail = temp;
        temp = temp->next;
    }       

    if(length <= 1 || k % length == 0)
        return head;

    k = length - (k % length);
    temp = head;
    auto prev = temp;
    while(--k)
    {
        prev = temp;
        temp = temp->next;
    }
    tail->next = head;
    head = temp->next;
    temp->next = nullptr;
    return head;
}

int main(int argc, char* argv[])
{
    auto print_list = [](ListNode * head)->void{
        while(head != nullptr)
        {
            cout << head->val << ' ';
            head = head->next;
        }
        cout << endl;
    };
    int n = 6;

    ListNode * head = nullptr;
    for(int i = n; i > 0; --i)
    {
        auto temp = new ListNode(i);
        temp->next = head;
        head = temp;
    }

    for(int i = 0; i < 10; ++i)
        print_list(head = rotateRight(head, i));
}


