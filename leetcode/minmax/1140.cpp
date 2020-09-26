#include "pch.h"

int stoneGameII(vector<int> & piles)
{
    int n = piles.size();
    if(n <= 2)
        return accumulate(piles.begin(), piles.end(), 0);

    vector<vector<pair<int, int>>> dp(n + 1, vector<pair<int, int>>(n, make_pair(0, 0)));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int m = 1; m < n; ++m)
        {
            int max_idx = 0, max_gain = -1, sum = 0, temp;
            for (int j = 0; j < 2 * m && i + j < n; ++j)
            {
                sum += piles[i + j];
                temp = sum + dp[i + j + 1][min(n - 1, max(j + 1, m))].second;
                if (temp > max_gain)
                {
                    max_gain = temp;
                    max_idx = j;
                }
            }
            sum = 0;
            for (int j = 0; j <= max_idx; ++j)
                sum += piles[i + j];
            dp[i][m].first = sum + dp[i + max_idx + 1][min(n - 1, max(max_idx + 1, m))].second;
            dp[i][m].second = dp[i + max_idx + 1][min(n - 1, max(max_idx + 1, m))].first;
        }
    }

    for (int m = n-1; m > 0; --m)
    {
        for (int i = 0; i < n; ++i)
        {
            cout << dp[i][m].first << ',' << dp[i][m].second << '\t';
        }
        cout << endl;
    }

    return dp[0][1].first;
}

int main()
{
    vector<int> piles = {2, 7, 9, 4, 4};
    cout << stoneGameII(piles) << " 10" << endl;
    piles = {8, 9, 5, 4, 5, 4, 1, 1, 9, 3, 1, 10, 5, 9, 6, 2, 7, 6, 6, 9};
    cout << stoneGameII(piles) << " 56" << endl;
}