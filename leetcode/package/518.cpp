#include "pch.h"
// 完全背包 + 背包计数
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    sort(coins.begin(), coins.end());
    vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;
    for (int i = 1; i <= amount; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            //for (int k = 0; k * coins[j - 1] <= i; ++k)
            //{
            //    dp[j][i] = (dp[j][i] + dp[j - 1][i - k * coins[j - 1]]) % 1000000007;
            //}
            dp[j][i] = (dp[j - 1][i] + (i >= coins[j - 1] ? dp[j][i - coins[j - 1]] : 0)) % 1000000007;
        }
    }
    return dp[n][amount];
}

int main()
{
    vector<int> coins = {1, 5, 10, 25};
    cout << change(10, coins) << " 4" << endl;
}