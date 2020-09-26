#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> letterCombinations(string digits) {
    static vector<string> letters = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    static vector<string> ans;
    ans.clear();
    int len = digits.length();
    if (len == 0) return ans;

    for(char c : letters[digits[0] - '2'])
    {
        string temp("");
        temp+=c;
        ans.push_back(temp);
    }
    for(int i = 1; i < len; ++i)
    {
        int current_size = ans.size(), button = digits[i] - '2';
        for(int k = 1; k < letters[button].size(); ++k)
        {
            for(int j = 0; j < current_size; ++j)
            {
                ans.push_back(ans[j] + letters[button][k]);
            }
        }
        for(int j = 0; j < current_size; ++j)
        {
            ans[j] += letters[button][0];
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    auto ans = letterCombinations(s);
    for(auto & a : ans)
    {
        cout << a << " ";
    }
    return 0;
}
