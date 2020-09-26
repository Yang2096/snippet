#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isScramble(string s1, string s2) {
    if(s1.size() != s2.size())
    {
        return false;
    }
    if(s1 == s2)
    {
        return true;
    }
    string ss1(s1);
    string ss2(s2);
    sort(ss1.begin(), ss1.end());
    sort(ss2.begin(), ss2.end());
    if(ss1 != ss2)
    {
        return false;
    }
    int n = ss1.size();
    if(n <= 3)
    {
        return true;
    }

    for(int i = 1; i < n; ++i)
    {
        if(isScramble(s1.substr(0,i), s2.substr(0,i))
        && isScramble(s1.substr(i,n-i), s2.substr(i,n-i)))
        {
            return true;
        }

        if(isScramble(s1.substr(0,i), s2.substr(n-i,i))
        && isScramble(s1.substr(i,n-i), s2.substr(0,n-i)))
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    cout << isScramble("great", "rgeat") << endl;
    cout << isScramble("great", "tgrea") << endl;
    return 0;
}
