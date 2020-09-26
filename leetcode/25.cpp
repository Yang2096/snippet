#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if(1 == k) return head;
    ListNode before_head(0);
    before_head.next = head;
    ListNode * block_tail = &before_head;
    ListNode * block_head;
    while(nullptr != block_tail)
    {
        int count = 0;
        block_head = block_tail;
        while(count++ < k)
        {
            if(block_tail->next != nullptr)
            {
                block_tail = block_tail->next;
            }
            else
            {
                return before_head.next;
            }
        }
        // 翻转链表
        ListNode * current = block_head->next;
        ListNode * nxt = current->next;
        while(current != block_tail)
        {
            if(nxt != nullptr)
            {
                auto temp = nxt->next;
                nxt->next = current;
                current = nxt;
                nxt = temp;
            }
        }
        block_tail = block_head->next;
        block_tail->next = nxt;
        block_head->next = current;
    }
    return before_head.next;
}

string listNodeToString(ListNode* node) {
    if (node == nullptr) {
        return "[]";
    }

    string result;
    while (node) {
        result += to_string(node->val) + ", ";
        node = node->next;
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    vector<int> input = {1,2,3,4,5};
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for(int item : input) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;

    ListNode * ret = reverseKGroup(ptr, 6);
    cout << listNodeToString(ret) << endl;

    return 0;
}