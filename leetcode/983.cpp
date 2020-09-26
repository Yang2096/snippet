#include "pch.h"

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    vector<int> dp(366, 0);
    for(int day : days)
        dp[day] = -1;

    for (int i = 1; i < 366; ++i)
    {
        if(dp[i] == -1)
        {
            dp[i] = dp[i - 1] + costs[0];
            if(i >= 7)
                dp[i] = min(dp[i], dp[i - 7] + costs[1]);
            else
                dp[i] = min(dp[i], costs[1]);
            if (i >= 30)
                dp[i] = min(dp[i], dp[i - 30] + costs[2]);
            else
                dp[i] = min(dp[i], costs[2]);
        }
        else
        {
            dp[i] = dp[i - 1];
        }
    }
    return dp[365];
}

int main()
{
    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs = {2, 7, 15};

    cout << mincostTickets(days, costs) << " 17" << endl;
    days = {1, 4, 6, 7, 8, 20};
    cout << mincostTickets(days, costs) << " 11" << endl;
}