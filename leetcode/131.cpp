#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<vector<string>> ans;

bool check(string& s, int left, int right)
{
    --right;
    if(left == right)
        return true;
    while(left < right)
    {
        if(s[left] != s[right])
            return false;
        left++;
        right--;
    }
    return true;
}

void backTrace(string &s, int index, vector<string>& line)
{
    if(index == s.size())
    {
        ans.push_back(line);
        return;
    }
    for (int i = index + 1; i <= s.size(); ++i)
    {
        if(check(s, index, i))
        {
            line.push_back(s.substr(index, i - index));
            backTrace(s, i, line);
            line.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    ans.clear();
    vector<string> line;
    backTrace(s, 0, line);
    return ans;
}

int main()
{
    auto ans = partition("aab");
    auto print = [](vector<vector<string>> &ans) {
        for (auto &line : ans)
        {
            for (auto a : line)
                cout << a << ' ';
            cout << endl;
        }
    };
    print(ans);
    ans = partition("aabb");
    print(ans);
    ans = partition("acaca");
    print(ans);
}