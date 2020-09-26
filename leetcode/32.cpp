#include <vector>
#include <iostream>
using namespace std;
inline int max (int a, int b)
{
    return a < b ? b : a;
}
int longestValidParentheses(string s) {
    int n = s.length();
    if(n <= 1) return 0;
    int dp[n + 1];
    int ans = dp[0] = dp[1] = 0;
    for(int i = 2; i < n + 1; ++i)
    {
        if(s[i - 1] == '(')
        {
            dp[i] = 0;
        }
        else
        {
            if(s[i-2] == '(')
            {
                dp[i] = dp[i - 2] + 2;
            }
            else if(i - dp[i-1] > 1 && s[i - dp[i-1] - 2] == '(')
            {
                dp[i] = dp[i - dp[i-1] - 2] + dp[i - 1] + 2;
            }
            else
            {
                dp[i] = 0;
            }
            ans = max(dp[i], ans);
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << longestValidParentheses(s) << endl;
    return 0;
}
