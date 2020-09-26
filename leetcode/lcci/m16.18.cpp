#include "pch.h"

bool patternMatching(const string &pattern, const string &value)
{
    int count[2] = {0, 0};
    for (char c : pattern)
        count[c - 'a']++;
    int n = value.length(), m = pattern.length();
    if (n == 0 && m == 0)
        return true;
    else if (n == 0)
        return m == 1;
    else if (n != 0 && m == 0)
        return false;
    int a_len, b_len, a_start, b_start;
    for (a_len = 0; a_len <= n; ++a_len)
    {
        if (a_len * count[0] > n)
            break;
        b_len = count[1] ? (n - count[0] * a_len) / count[1] : 0;
        if (n != (a_len * count[0] + b_len * count[1]))
            continue;

        a_start = b_start = -1;
        if (pattern[0] == 'a')
            a_start = 0;
        else
            b_start = 0;
        int index = (pattern[0] == 'a') ? a_len : b_len;

        for (int i = 1; i < m; ++i)
        {
            bool check = false;
            if (pattern[i] == 'a')
            {
                if (a_start == -1)
                    a_start = index;
                for (int k = 0; k < a_len; ++k)
                {
                    if (value[a_start + k] != value[index + k])
                    {
                        check = true;
                        break;
                    }
                }
                if (check)
                    break;
                index += a_len;
            }
            else
            {
                if (b_start == -1)
                    b_start = index;
                for (int k = 0; k < b_len; ++k)
                {
                    if (value[b_start + k] != value[index + k])
                    {
                        check = true;
                        break;
                    }
                }
                if (check)
                    break;
                index += b_len;
            }
        }
        if (index == n)
        {
            if (a_start != -1 && b_start != -1 && value.substr(a_start, a_len) == value.substr(b_start, b_len))
                continue;
            else
                return true;
        }
    }
    return false;
}

int main()
{
    string patten = "bbbbbbbbabbbbbbbbbbbabbbbbbba";
    string value = "zezezezezezezezezkxzezezezezezezezezezezezkxzezezezezezezezkx";
    cout << patternMatching(patten, value) << endl;
}