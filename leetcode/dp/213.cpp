#include "..\pch.h"

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    vector<int> dp(n, 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n-1; ++i)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    int ans = dp[n-2];
    dp[1] = nums[1];
    dp[2] = max(nums[1], nums[2]);
    for (int i = 3; i < n ; ++i)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
    }
    ans = max(ans, dp[n - 1]);
    return ans;
}

int main()
{
    vector<int> nums = {2, 3, 2};
    cout << rob(nums) << " 3" << endl;
    nums = {1, 2, 3, 1};
    cout << rob(nums) << " 4" << endl;
}