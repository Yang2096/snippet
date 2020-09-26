#include "pch.h"
string decodeString(string s)
{
    stack<pair<int, string>> st;
    int num = 0;
    st.emplace(1, "");
    bool new_num = true;
    for (char ch : s)
    {
        if (ch >= '0' && ch <= '9')
        {
            if (!new_num)
            {
                num *= 10;
                num += ch - '0';
            }
            else
            {
                num = ch - '0';
                new_num = false;
            }
        }
        else if (ch == '[')
        {
            st.emplace(num, "");
            new_num = true;
        }
        else if (ch == ']')
        {
            int count = st.top().first;
            string re = std::move(st.top().second);
            st.pop();
            while (count--)
            {
                st.top().second += re;
            }
            num = 0;
        }
        else
        {
            st.top().second += ch;
        }
    }
    return st.top().second;
}

int main()
{
    cout << decodeString("2[a2[b3[c]d]]e") << endl;
    cout << decodeString("3[z]2[2[y]pq4[2[jk]e1[f]]]ef") << endl
         << "zzzyypqjkjkefjkjkefjkjkefjkjkefyypqjkjkefjkjkefjkjkefjkjkefef" << endl;
}