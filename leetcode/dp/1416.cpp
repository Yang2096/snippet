#include "../pch.h"

int numberOfArrays(string s, int k)
{
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        long long num = 0, times = 1;
        int j = i - 1;
        while (j >= 0)
        {
            if (s[j] != '0')
            {
                num += times * (s[j] - '0');
                if (num > k || num == 0)
                    break;
                else
                    dp[i] = (dp[i] + dp[j]) % 1000000007;
            }
            j--;
            times *= 10;
            if(times > k)
                break;
        }
    }
    return dp[n];
}

int main()
{
    cout << numberOfArrays("1000", 10000) << " 1" << endl;
    cout << numberOfArrays("1000", 10) << " 0" << endl;
    cout << numberOfArrays("1317", 2000) << " 8" << endl;
    cout << numberOfArrays("2020", 2000) << " 1" << endl;
    cout << numberOfArrays("1234567890", 90) << " 34" << endl;
}