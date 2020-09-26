#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void print(TreeNode *root)
{
    if (root == nullptr)
        return;
    queue<TreeNode *> q;
    q.push(root);
    int size;
    while (!q.empty())
    {
        size = q.size();
        while (size-- > 0)
        {
            auto node = q.front();
            q.pop();
            cout << node->val << ' ';
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
    }
}

ListNode* generateList(vector<int>& input)
{
    ListNode *head, *prev = nullptr;
    for(int a : input)
    {
        if(prev == nullptr)
        {
            head = prev = new ListNode(a);
        }
        else
        {
            prev->next = new ListNode(a);
            prev = prev->next;
        }
    }
    return head;
}

ListNode* findMid(ListNode* begin, ListNode* end)
{
    if(begin == nullptr)
        return nullptr;
    if(begin->next == end)
        return begin;
    ListNode *fast, *slow;
    fast = slow = begin;
    while(fast != end)
    {
        fast = fast->next;
        if (fast != end)
            fast = fast->next;
        else
            break;
        slow = slow->next;
    }
    return slow;
}

TreeNode *generateTree(ListNode* begin, ListNode* end)
{
    if(begin == nullptr || begin == end)
        return nullptr;
    auto mid = findMid(begin, end);
    TreeNode *root = new TreeNode(mid->val);
    root->left = generateTree(begin, mid);
    root->right = generateTree(mid->next, end);
    return root;
}

TreeNode *sortedListToBST(ListNode *head)
{
    if(head == nullptr)
        return nullptr;
    return generateTree(head, nullptr);
}

int main()
{
    vector<int> input = {0, 1, 2, 3, 4, 5};
    print(sortedListToBST(generateList(input)));
    input = {1, 2};
    print(sortedListToBST(generateList(input)));
}