#include "pch.h"

bool PredictTheWinner(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
        return true;
    vector<vector<pair<int,int>>> dp(n + 1, vector<pair<int,int>>(n + 1, make_pair(0,0)));

    for (int i = 1; i <= n; ++i)
    {
        dp[i][i].first = nums[i - 1];
        for (int j = i - 1; j >= 1; --j)
        {
            int left = nums[j-1] + dp[j + 1][i].second;
            int right = nums[i-1] + dp[j][i - 1].second;
            if(left >= right)
            {
                dp[j][i].first = max(dp[j][i].first, left);
                dp[j][i].second = dp[j + 1][i].first;
            }
            else
            {
                dp[j][i].first = max(dp[j][i].first, right);
                dp[j][i].second = dp[j][i - 1].first;
            }
        }
    }
    return dp[1][n].first >= dp[1][n].second;
}

int main()
{
    vector<int> nums = {1, 5, 2};
    cout << PredictTheWinner(nums) << " 0" << endl;
    nums = {1, 5, 233, 7};
    cout << PredictTheWinner(nums) << " 1" << endl;
}