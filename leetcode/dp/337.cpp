#include "..\pch.h"
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

pair<int, int> search(TreeNode * root)
{
    if(root == nullptr)
        return make_pair(0, 0);
    auto left = search(root->left);
    auto right = search(root->right);
    int first = left.second + right.second + root->val;
    int second = max(max(left.first + right.first, left.second + right.second), max(left.first + right.second, left.second + right.first));
    return make_pair(first, second);
}

int rob(TreeNode *root)
{
    auto p = search(root);
    return max(p.first, p.second);
}