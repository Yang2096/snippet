#include "pch.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

list<TreeNode *> for_p, for_q, visit;
bool found_p;
bool found_q;
TreeNode *_p, *_q;
void dfs()
{
    if (found_p && found_q)
        return;
    if(visit.back()->left)
    {
        visit.emplace_back(visit.back()->left);
        dfs();
    }
    
    if(visit.back()->right)
    {
        visit.emplace_back(visit.back()->right);
        dfs();
    }

    if (!found_p && visit.back()->val == _p->val)
    {
        for_p = visit;
        found_p = true;
    }

    if (!found_q && visit.back()->val == _q->val)
    {
        for_q = visit;
        found_q = true;
    }
    visit.pop_back();
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    for_q.clear();
    for_p.clear();
    visit.clear();
    found_p = false;
    found_q = false;
    _q = q;
    _p = p;
    visit.push_back(root);

    dfs();

    TreeNode* prev;
    for(auto a = for_p.front(), b = for_q.front(); a && b && a->val == b->val;)
    {
        prev = a;
        for_p.pop_front();
        a = for_p.front();
        for_q.pop_front();
        b = for_q.front();
    }
    return prev;
}