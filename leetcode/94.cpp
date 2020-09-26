#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    if(root == nullptr) return ans;
    stack<TreeNode*> s;
    s.push(root);
    TreeNode* current;
    while(!s.empty())
    {
        current = s.top();
        if(current->left == nullptr)
        {
            ans.push_back(current->val);
            s.pop();
            if(current->right != nullptr)
                s.push(current->right);
        }
        else
        {
            s.push(current->left);
            current->left = nullptr;
        }
    }
    return ans;
}