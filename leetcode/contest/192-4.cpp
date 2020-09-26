#include "pch.h"

int minCost(vector<int> &houses, vector<vector<int>> &cost, int m, int n, int target)
{
    vector<vector<vector<int>>> dp(m, vector<vector<int>>(target + 1, vector<int>(n + 1, -1)));
    if(houses[0] == 0)
    {
        for(int j = 1; j <= n; ++j)
            dp[0][1][j] = cost[0][j-1];
    }
    else
    {
            dp[0][1][houses[0]] = 0;
    }
    
    int temp;
    for(int i = 1; i < m; ++i)
    {
        if(houses[i] == 0)
        {
            temp = INT32_MAX;
            for(int j = 1; j <= n; ++j)
            {
                dp[i][1][j] = dp[i - 1][1][j] == -1 ? -1 : dp[i - 1][1][j] + cost[i][j-1];
            }
            
            for(int k = 2; k <= target; ++k)
            {
                for(int j = 1; j <= n; ++j)
                {
                    temp = INT32_MAX;
                    for(int j1 = 1; j1 <= n; ++j1)
                    {
                        if(j1 != j)
                        {
                            if(dp[i-1][k-1][j1] != -1)
                                temp = min(temp, dp[i-1][k-1][j1]);
                        }
                        else
                        {
                            if(dp[i-1][k][j1] != -1)
                                temp = min(temp, dp[i-1][k][j1]);
                        }
                        
                    }
                    dp[i][k][j] = temp == INT32_MAX ? -1 : temp + cost[i][j-1];
                }
            }
        }   
        else
        {
            dp[i][1][houses[i]] = dp[i-1][1][houses[i]];
            for(int k = 2; k <= target; ++k)
            {
                temp = INT32_MAX;
                for(int j = 1; j <= n; ++j)
                {
                    if(houses[i] != j)
                    {
                        if(dp[i-1][k-1][j] != -1)
                            temp = min(temp, dp[i-1][k-1][j]);
                    }
                    else
                    {
                        if(dp[i-1][k][j] != -1)
                            temp = min(temp, dp[i-1][k][j]);
                    }
                }
                dp[i][k][houses[i]] = temp == INT32_MAX ? -1 : temp;
            }
        }
    }

    int ans = INT32_MAX;
    for(int j = 1; j <= n; ++j)
    {
        if(dp[m-1][target][j] != -1)
            ans = min(ans, dp[m - 1][target][j]);
    }

    return ans == INT32_MAX ? -1 : ans;
}

int main()
{
    vector<int> houses = {0,0,0,0,0};
    vector<vector<int>> cost = {{1, 10}, {10, 1}, {10, 1}, {1, 10}, {5, 1}};
    cout << minCost(houses, cost, 5,2,3) << endl;
}