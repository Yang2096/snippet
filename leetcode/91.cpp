#include <iostream>
#include <vector>
#include <string>
using namespace std;

int numDecodings(string s) {
    int len = s.length();
    if(len == 0) return 0;
    if(s[0] == '0') return 0;
    vector<int> ans(len + 1, 0);
    ans[0] = ans[1] = 1; 
    for(int i = 1; i < len; ++i) 
    {
        if(s[i] != '0')
        {
            ans[i+1] = ans[i];
            if(s[i] <= '6' && s[i-1] >= '1' && s[i-1] <= '2')
            {
                ans[i+1] += ans[i-1];
            }
        }
        else
        {
            if(s[i-1] != '1' && s[i-1] != '2')
            {
                return 0;
            }
            else
            {
                ans[i+1] = ans[i-1];
            }
        } 
    }
    return ans[len];
}

int main()
{
    cout << numDecodings("10") << endl;
    cout << numDecodings("101") << endl;
    cout << numDecodings("1011") << endl;
    cout << numDecodings("110") << endl;
    cout << numDecodings("1101") << endl;
    cout << numDecodings("226126") << endl;
    cout << numDecodings("22612612") << endl;
}