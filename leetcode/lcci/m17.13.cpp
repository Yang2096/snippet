#include"pch.h"
int respace(vector<string> &dictionary, string sentence)
{
    int n = sentence.length();
    vector<int> dp(n + 1, n);
    dp[0] = 0;
    unordered_set<string> hash_set;
    int _max = INT32_MIN;
    for (string &str : dictionary)
    {
        hash_set.emplace(str);
        _max = max(_max, (int)str.length());
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j <= min(n-i, _max); ++j)
        {
            if(hash_set.count(sentence.substr(i, j)))
            {
                cout << sentence.substr(i, j) << endl;
                dp[i + j] = min(dp[i + j], dp[i]);
            }
            else
            {
                dp[i + j] = min(dp[i+j], dp[i] + j);
            }
        }
    }
    for (int i = 0; i <= n; ++i)
        cout << dp[i] << ' ';
    cout << endl << "  ";
    for (int i = 0; i < n; ++i)
        cout << sentence[i] << ' ';
    cout << endl;
    return dp[n];
}

int main()
{
    vector<string> dictionary = {"looked", "just", "like", "her", "brother"};
    cout << respace(dictionary, "jesslookedjustliketimherbrother") << " 7" << endl;
}