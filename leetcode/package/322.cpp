#include "..\pch.h"

int coinChange(vector<int> &coins, int amount)
{
    sort(coins.begin(), coins.end());
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    for (int j = 0; j < coins.size(); ++j)
    {
        for (int i = coins[j]; i <= amount; ++i)
        {
            //只用coins[1~j-1] vs 再用一个coins[j]
            dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }
    return (dp[amount] == amount + 1) ? -1 : dp[amount];
}

int main()
{
    vector<int> coins = {1, 2, 5};
    cout << coinChange(coins, 11) << " 3" << endl;
    coins = {1, 2, 5, 10};
    cout << coinChange(coins, 10) << " 1" << endl;
    coins = {4};
    cout << coinChange(coins, 7) << " -1" << endl;
}