#include "pch.h"

string stoneGameIII(vector<int>& stoneValue) {
    int n = stoneValue.size();

    vector<int> dp(n + 1, INT32_MIN);
    dp[n] = 0;
    int sum = 0;
    for (int i = n - 1; i >= 0; --i)
    {
        sum += stoneValue[i];
        for (int j = 0; j < 3 && i + j < n; ++j)
        {
            dp[i] = max(dp[i], sum - dp[i + j + 1]);
        }
    }
    if (sum - dp[0] > dp[0])
        return "Bob";
    else if (dp[0] > sum - dp[0])
        return "Alice";
    else
        return "Tie";
}

int main()
{
    vector<int> stones = {1, 2, 3, -9};
    cout << stoneGameIII(stones) << " Alice" << endl;
    stones = {1, 2, 3, -9};
    cout << stoneGameIII(stones) << " Alice" << endl;
    stones = {1, 2, 3, 6};
    cout << stoneGameIII(stones) << " Tie" << endl;
    stones = {1, 2, 3, 7};
    cout << stoneGameIII(stones) << " Bob" << endl;
    stones = {1, 2, 3, -1, -2, -3, 7};
    cout << stoneGameIII(stones) << " Alice" << endl;
    stones = {-1, -2, -3};
    cout << stoneGameIII(stones) << " Tie" << endl;
}