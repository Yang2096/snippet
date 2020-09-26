#include "pch.h"

bool check(vector<int> & postorder, int begin, int end, int max, int min)
{
    if(begin >= end)
        return true;
    int mid = postorder[end];
    if(mid > max || mid < min)
        return false;

    int left = end - 1;
    while(left >= begin && postorder[left] > mid)
    {
        if(postorder[left] > max)
            return false;
        left--;
    }
    // left -> first element smaller than mid

    return check(postorder, begin, left, mid, min) &&
           check(postorder, left + 1, end - 1, max, mid);
}

bool verifyPostorder(vector<int> &postorder)
{
    return check(postorder, 0, postorder.size() - 1, INT32_MAX,INT32_MIN);
}

int main()
{
    vector<int> post_order = {1, 3, 2, 6, 5};
    cout << verifyPostorder(post_order) << " 1" << endl;
    post_order = {1, 6, 3, 2, 5};
    cout << verifyPostorder(post_order) << " 0" << endl;
}