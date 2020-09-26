#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool dp[1005][1005];
string longestPalindrome(string s)
{
    int n = s.length();
    int pos = 0, len = 1;
    for (int i = 0; i < n; ++i)
        dp[i][i] = true;
    for (int j = 1; j < n; ++j)
    {
        for (int i = j - 1; i >= 0; --i)
        {
            if (s[i] == s[j])
            {
                if (i + 1 <= j - 1)
                {
                    if (dp[i + 1][j - 1])
                        dp[i][j] = true;
                }
                else
                    dp[i][j] = true;
            }
            else
                dp[i][j] = false;
            
            if(dp[i][j])
            {
                if(j - i + 1 > len)
                {
                    pos = i;
                    len = j - i + 1;
                }
            }
        }
    }
    return s.substr(pos, len);
}

int main()
{
    cout << longestPalindrome("babab") << endl;
    cout << longestPalindrome("babad") << endl;
    cout << longestPalindrome("cbbd") << endl;
}