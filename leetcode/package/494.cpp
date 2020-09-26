#include "..\pch.h"
int findTargetSumWays(vector<int> &nums, int S)
{
    if(S < 0)
        S = -1 * S;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(S > sum)
        return 0;
    
    int n = nums.size();
    vector<vector<int>> dp(2, vector<int>(sum * 2 + 1, 0));
    dp[0][sum] = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j <= sum * 2; ++j)
        {
            dp[i & 1][j] = 0;
            if (j >= nums[i - 1])
                dp[i&1][j] += dp[1 - i&1][j - nums[i - 1]];
            
            if (j <= (sum * 2 - nums[i - 1]))
                dp[i&1][j] += dp[1 - i&1][j + nums[i - 1]];
            cout << dp[i & 1][j] << ' ';
        }
        cout << endl;
    }
    return dp[n&1][sum + S];
}

int main()
{
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums, 3) << " 5" << endl;
    nums = {1, 0};
    cout << findTargetSumWays(nums, 1) << " 2" << endl;
}