#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
    int len1 = s1.length();
    int len2 = s2.length();
    if(len1 + len2 != s3.length()) return false;
    if(len1 == 0) return s2 == s3;
    if(len2 == 0) return s1 == s3;

    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
    for(int i = 0; i < len1; i++)
    {
        dp[i+1][0] = s1[i] == s3[i];
        if(dp[i+1][0] == false)
            break;
    }
    for(int i = 0; i < len2; i++)
    {
        dp[0][i+1] = s2[i] == s3[i];
        if(dp[0][i+1] == false)
            break;
    }
    for(int i = 1; i <= len1; i++)
    {
        for(int j = 1; j <= len2; j++)
        {
            if(s2[j-1] == s3[i + j - 1])
            {
                dp[i][j] = dp[i][j-1];
            }
            if(s1[i-1] == s3[i + j - 1])
            {
                dp[i][j] = dp[i][j] || dp[i-1][j];
            }
        }
    }
    for(auto& line : dp)
    {
        for(auto b : line)
        {
            cout << b << ' ';
        }
        cout << endl;
    }
    return dp[len1][len2];
}



int main()
{
    cout << isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
    cout << isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
    cout << isInterleave("aabcc", "dbbca", "adabbbccca") << endl;
    cout << isInterleave("db", "b", "cbb") << endl;
}