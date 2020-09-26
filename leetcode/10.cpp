#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, false));
    dp[0][0] = true;
    for (int j = 2; j <= m; ++j)
    {
        if(p[j-1] == '*')
            dp[0][j] = dp[0][j - 2];
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(s[i] == p[j] || p[j] == '.')
                dp[i + 1][j + 1] = dp[i][j];
            else if(p[j] == '*')
            {
                if(j != 0)
                {
                    dp[i + 1][j + 1] = dp[i + 1][j - 1];
                    if (s[i] == p[j - 1] || '.' == p[j - 1])
                    {
                        dp[i + 1][j + 1] = dp[i + 1][j + 1] || dp[i][j] || dp[i + 1][j] || dp[i][j + 1];
                    }
                }
                else
                {
                    dp[i + 1][j + 1] = false;
                }
            }
        }
    }
    return dp[n][m];
}


int main()
{
    cout << (isMatch("", "") == true) << endl;
    cout << (isMatch("", "a*b*d*") == true) << endl;
    cout << (isMatch("aa", "a") == false) << endl;
    cout << (isMatch("aa", "a*") == true) << endl;
    cout << (isMatch("ab", ".*") == true) << endl;
    cout << (isMatch("aab", "c*a*b") == true) << endl;
    cout << (isMatch("mississippi", "mis*is*p*.") == false) << endl;
    cout << (isMatch("akugkfuEIUNAKJSNC", ".*") == true) << endl;
}