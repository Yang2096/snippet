#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int maxWidthRamp(vector<int> &A)
{
    stack<int> s;
    int ans = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (s.empty() || A[i] < A[s.top()])
        {
            s.push(i);
        }
    }

    for(int i = A.size() - 1; i >= 0; --i)
    {
        while(!s.empty() && A[i] >= A[s.top()])
        {
            ans = max(ans, i - s.top());
            s.pop();
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {6,0,8,2,1,5};
    cout << maxWidthRamp(nums) << endl;
    nums = {9,8,1,0,1,9,4,0,4,1};
    cout << maxWidthRamp(nums) << endl;
}