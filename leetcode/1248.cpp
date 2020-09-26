#include "pch.h"

int numberOfSubarrays(vector<int> &nums, int k)
{
    int ans = 0;
    vector<int> idx;
    idx.push_back(-1);
    for (int i = 0; i < nums.size(); ++i)
    {
        if(nums[i]%2)
            idx.push_back(i);
    }
    idx.push_back(nums.size());

    for (int i = 1; i + k < idx.size(); ++i)
    {
        ans += (idx[i] - idx[i - 1]) * (idx[i + k] - idx[i + k - 1]);
    }

    return ans;
}

int main()
{
    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    cout << numberOfSubarrays(nums, 2) << " 16" << endl;
    nums = {2, 4, 1, 6};
    cout << numberOfSubarrays(nums, 1) << " 0" << endl;
    nums = {1, 1, 2, 1, 1};
    cout << numberOfSubarrays(nums, 3) << " 2" << endl;
}