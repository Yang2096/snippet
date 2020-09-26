#include "..\pch.h"

int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 1e9));

    for (int i = 0; i <= n; ++i)
        for (int j = i; j <= n; ++j)
            dp[j][i] = 0;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = i; j >= 1; --j)
        {
            for (int k = i ; k >= j; --k)
            {
                if(k == 1)
                    dp[j][i] = min(dp[j][i], 1 + dp[2][i]);
                else if(k == n)
                    dp[j][i] = min(dp[j][i], n + dp[j][n - 1]);
                else
                    dp[j][i] = min(dp[j][i], k + max(dp[j][k - 1] , dp[k + 1][i]));
            }
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = n; j > i; --j)
        {
            cout << dp[i][j] << '\t';
        }
        cout << endl;
    }

    return dp[1][n];
}

int main()
{
    cout << getMoneyAmount(10) << " 16" << endl;
}