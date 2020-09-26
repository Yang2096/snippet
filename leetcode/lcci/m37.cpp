#include "pch.h"

struct TreeNode{
    TreeNode(int _val)
    {
        val = _val;
        left = nullptr;
        right = nullptr;
    }

    int val;
    TreeNode * left;
    TreeNode * right;
};

string serialize(TreeNode *root)
{
    string ans = "[";
    if (!root)
        return "[]";

    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        auto t = q.front();
        q.pop();
        if (t)
        {
            ans += to_string(t->val) + ",";
            q.push(t->left);
            q.push(t->right);
        }
        else
            ans += "null,";
    }
    while (ans.back() < '0' || ans.back() > '9')
        ans.pop_back();
    ans += ']';
    return ans;
}

TreeNode *deserialize(string data)
{
    if (data == "[]")
        return nullptr;
    int count = 0, i = 1, value = 0, neg = 1;
    if (data[i] == '-')
    {
        neg = -1;
        i++;
    }
    while (data[i] >= '0' && data[i] <= '9')
    {
        value *= 10;
        value += (data[i] - '0');
        i++;
    }
    TreeNode *root = new TreeNode(value * neg);
    queue<TreeNode *> q;
    q.push(root);
    for (i++; i < data.length();)
    {
        if (data[i] == ',')
        {
            if (!(count & 1))
            {
                q.pop();
            }
            i++;
        }
        else if (data[i] == 'n')
        {
            count++;
            i += 4;
        }
        else if (data[i] == ']')
            return root;
        else
        {
            value = 0;
            neg = 1;
            if (data[i] == '-')
            {
                neg = -1;
                i++;
            }

            while (data[i] >= '0' && data[i] <= '9')
            {
                value *= 10;
                value += (data[i] - '0');
                i++;
            }

            if (count & 1)
            {
                q.front()->right = new TreeNode(value * neg);
                q.push(q.front()->right);
            }
            else
            {
                q.front()->left = new TreeNode(value * neg);
                q.push(q.front()->left);
            }
            count++;
        }
    }
    return root;
}

int main()
{
    string data = "[1,2,3,null,null,4,5]";
    cout << serialize(deserialize(data)) << endl;
    data = "[1,2,3,null,null,4,5,null,7,8]";
    cout << serialize(deserialize(data)) << endl;
}