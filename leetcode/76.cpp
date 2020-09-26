#include <iostream>
#include <string>
using namespace std;

string minWindow(string s, string t) {
    int mark[128] = {0};    // 无需额外标记， 不在t中的字母一样可以加减
    int mark2[128] = {0};   
    for(char ch : t)
    {
        ++mark2[ch];
    }
    int left = 0, right = 0;
    int s_len = s.length(), t_len = t.length();
    int min_len = s_len, b = 0, l = 0;
    int valid = 0;
    while(right < s_len || (right == s_len && valid == t_len))
    {
        if(valid == t_len)
        {
            if(right - left <= min_len)
            {
                l = min_len = right - left;
                b = left;
            }
            int pos = s[left];
            if(mark2[pos] > 0)
            {
                if(--mark[pos] < mark2[pos])
                    --valid;
            }
            left++;
        }
        else
        {
            int pos = s[right];
            if(mark2[pos] > 0)
            {
                if(++mark[pos] <= mark2[pos])
                    ++valid;
            }
            ++right;
        }
        
    }
    return s.substr(b, l);
}

int main()
{
    cout << minWindow("aaabdcaaadddddddddddaaaaabc", "aabc") << endl;
    cout << minWindow("a", "aa") << endl;
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << minWindow("a", "a")<< endl;
}