#include "..\pch.h"

bool canPartition(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum & 1)
        return false;
    sum = sum >> 1;
    vector<bool> dp(sum + 1, false);
    dp[0] = true;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = sum; j >= nums[i]; --j)
        {
            dp[j] = dp[j] || dp[j - nums[i]];
        }
    }
    return dp[sum];
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    cout << canPartition(nums) << " 1" << endl;
    nums = {1, 2, 3, 5};
    cout << canPartition(nums) << " 0" << endl;
}