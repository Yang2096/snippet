#include "pch.h"

vector<string> findRepeatedDnaSequences(string s)
{
    vector<string> ans;
    if(s.length() <= 10)
        return ans;
    unordered_map<string, int> set;
    for (int i = 0; i <= s.length() - 10; ++i)
    {
        string temp = s.substr(i, 10);
        if (set.count(temp))
        {
            set[temp]++;
            if(set[temp] == 1)
                ans.emplace_back(move(temp));
        }
        else
        {
            set.emplace(temp, 0);
        }
    }
    return ans;
}

int main()
{
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    for(auto a : findRepeatedDnaSequences(s))
    {
        cout << a << ' ';
    }
    s = "AAAAAAAAAAAA";
    for (auto a : findRepeatedDnaSequences(s))
    {
        cout << a << ' ';
    }
    s = "CCGGCCGGCCGGCC";
    for (auto a : findRepeatedDnaSequences(s))
    {
        cout << a << ' ';
    }
}