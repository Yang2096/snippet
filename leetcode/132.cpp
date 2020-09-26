#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool check(string &s, int left, int right)
{
    --right;
    if (left == right)
        return true;
    while (left < right)
    {
        if (s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

int minCut(string s)
{
    cout << s << endl;
    int n = s.size();
    vector<int> dp(n + 1);
    dp[0] = -1;
    for (int i = 1; i <= n; ++i)
    {
        dp[i] = dp[i-1] + 1;
        for (int j = i - 1; j > 0; --j)
        {
            if(s[j - 1] == s[i - 1] && check(s, j-1, i))
            {
                dp[i] = min(dp[i], dp[j-1] + 1);
            }
        }
    }
    return dp[n];
}

int main()
{
    cout << minCut("cbbbcc") << " 1" << endl;
    cout << minCut("abcdefghij") << " 9" << endl;
    cout << minCut("aab") << " 1" << endl;
    cout << minCut("a") << " 0" << endl;
    cout << minCut("aaaaaaaaaaaa") << " 0" << endl;
    cout << minCut("acaca") << " 0" << endl;
    cout << minCut("acacabcb") << " 1" << endl;
    cout << minCut("aabb") << " 1" << endl;
}