#include "pch.h"

int waysToChange(int n)
{
    vector<int> coins = {1, 5, 10, 25};
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int j = 0; j <= 3; ++j)
    {
        for (int i = coins[j]; i <= n; ++i)
        {
            dp[i] = (dp[i] + dp[i - coins[j]]) % 1000000007;
        }
    }
    return dp[n];
}

int main()
{
    cout << waysToChange(10) << " 4" << endl;
}