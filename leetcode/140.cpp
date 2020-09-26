#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

vector<string> ans;

void dfs(vector<set<int>> dp, vector<string> &wordDict, vector<int>&line, int index)
{
    if(index >= dp.size())
    {
        string a;
        for (int i = 0; i < line.size(); ++i)
        {
            if (i == 0)
                a += wordDict[line[i]];
            else
                a += " " + wordDict[line[i]];
        }
        ans.emplace_back(a);
    } else
    {
        for (int word : dp[index])
        {
            line.push_back(word);
            dfs(dp, wordDict, line, index + wordDict[word].length());
            line.pop_back();
        }
    }
}

vector<string> wordBreak(string s, vector<string> &wordDict)
{
    ans.clear();
    vector<bool> count(26, false);
    for (const auto &word : wordDict)
    {
        for (char ch : word)
        {
            count[ch - 'a'] = true;
        }
    }
    for (char ch : s)
    {
        if (count[ch - 'a'] == false)
            return ans;
    }

    int n = s.length();
    vector<set<int>> dp(n);
    vector<bool> mark(n+1, false);
    mark[0] = true;
    for (int i = 0; i < n; ++i)
    {
        if(mark[i])
        {
            for (int j = 0; j < wordDict.size(); ++j)
            {
                if (i + wordDict[j].length() <= n && s.substr(i, wordDict[j].length()) == wordDict[j])
                {
                    dp[i].insert(j);
                    mark[i + wordDict[j].length()] = true;
                }
            }
        }
    }
    if(mark[n])
    {
        vector<int> line;
        dfs(dp, wordDict, line, 0);
    }
    return ans;
}

int main()
{
    //string s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    string s = "aaaaaaaaaaaaaaaaaaaaaaba";
    vector<string> wordDict = {"aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa", "ba"};
    auto ret = wordBreak(s, wordDict);
    for(auto & line : ret)
    {
        cout << line << endl;
    }
}