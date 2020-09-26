#include <iostream>
#include <string>
using namespace std;
int numDecodings(string s) {
    int ans = 1, prev = 1, temp;
    int len = s.length();
    if(len == 0 || s[0] == '0') return 0;
    for(int i = 1; i < len; ++i)
    {
        temp = ans;
        if(s[i] == '0')
            if(s[i-1] == '1' || s[i-1] == '2')
                ans = prev;
            else
                return 0;
        else
            if(s[i-1] == '1' || (s[i-1] == '2' && s[i] >= '1' && s[i] <= '6'))
                ans += prev;
        prev = temp;
    }
    return ans;
}


int main()
{
    cout << numDecodings("110") << endl;
    cout << numDecodings("111") << endl;
    cout << numDecodings("17") << endl;
    cout << numDecodings("10") << endl;
}