#include "pch.h"

int maxCoins(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    vector<int> nums1(n + 2);
    for (int i = 1; i <= n; ++i)
        nums1[i] = nums[i - 1];
    nums1[0] = nums1[n + 1] = 1;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; ++i)
    {
        dp[i][i] = nums1[i - 1] * nums1[i] * nums1[i + 1];
    }

    for (int j = 1; j < n; ++j)
    {
        for (int i = 1; i + j <= n; ++i)
        {
            int temp = -1;
            for (int k = i; k <= i + j; ++k)
            {
                temp = max(temp, dp[i][k - 1] + nums1[i - 1] * nums1[k] * nums1[i + j + 1] + dp[k + 1][i + j]);
            }
            dp[i][i + j] = temp;
        }
    }
    return dp[1][n];
}
int main()
{
    vector<int> nums = { 3, 1, 5, 8};
    cout << maxCoins(nums) << endl;
}