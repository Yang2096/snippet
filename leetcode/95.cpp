#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
};

void print(const vector<TreeNode*>& roots)
{
    for(auto root : roots)
    {
        queue<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* current = s.front();
            s.pop();
            if(current == nullptr)
            {
                cout << "null,";
            }
            else
            {
                cout << current->val << ',';
                if(current->left || current->right)
                {
                    s.push(current->left);
                    s.push(current->right);
                }

            }
        }
        cout << endl;
    }
}

TreeNode* copyTree(TreeNode* root)
{
    TreeNode * another = new TreeNode(root->val);
    stack<pair<TreeNode*, TreeNode*>> s;
    s.push(make_pair(another, root));
    pair<TreeNode*, TreeNode*> current;
    while(!s.empty())
    {
        current = s.top();
        s.pop();
        if(current.second->left)
        {
            current.first->left = new TreeNode(current.second->left->val);
            s.push(make_pair(current.first->left, current.second->left));
        }

        if(current.second->right)
        {
            current.first->right = new TreeNode(current.second->right->val);
            s.push(make_pair(current.first->right, current.second->right));
        }
    }
    return another;
}

vector<TreeNode*> ans;

void insert(TreeNode* root, TreeNode* current)
{
    current->left = root;
    ans.push_back(copyTree(current));
    current->left = nullptr;       

    TreeNode * node = root;
    while(node != nullptr)
    {
        if(node->right == nullptr)
        {
            current->left = nullptr;
            node->right = current;
            break;
        }
        else
        {
            current->left = node->right;
            node->right = current;
            ans.push_back(copyTree(root));
            node->right = current->left;
            node = node->right; 
        }
    }   
}

vector<TreeNode*> generateTrees(int n)
{
    ans.clear();
    int size = 1;
    ans.push_back(new TreeNode(1));
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 0; j < size; ++j)
        {
            TreeNode * current = new TreeNode(i);
            insert(ans[j], current);
        }
        size = ans.size();
    }
    return ans;
}

int main()
{
    print(generateTrees(4));
}