#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

vector<string> stringMatching(vector<string>& words) {
    sort(words.begin(), words.end(), [](const string & a, const string b)->bool{
        return a.length() < b.length();
    });
    set<string> ans;
        for(auto a : words)
    {
        cout << a << endl;
    }
    for(int i = 1; i < words.size(); ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            if(words[i].find(words[j]) != string::npos)
            {
                ans.emplace(words[j]);
            }
        }
    }
    return vector<string>(ans.begin(), ans.end());
}


int main()
{
    vector<string> words = {"leetcoder","leetcode","od","hamlet","am"};
    for(auto a : stringMatching(words))
    {
        cout << a << endl;
    }
}
