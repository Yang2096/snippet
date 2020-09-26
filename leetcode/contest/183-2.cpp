#include<iostream>
#include<vector>
#include<string>
using namespace std;
    
char num[505];
int numSteps(string s) {
    int len = s.length();
    for(int i = len - 1; i >= 0; --i)
    {
        num[len - 1 - i] = s[i];
    }
    int c = 0, count;
    int step = 0;
    while(c < len)
    {
        if(c + 1 == len)
        {
            if(num[c] == '0')
            {
                ++step;
            }
            break;
        }
        if(num[c] == '0')
        {
            ++step;
            ++c;
        }
        else
        {
            count = 1;
            for(int i = c; i < len; ++i)
            {
                if(num[i] == '0')
                {
                    num[i] += count;
                    count = 0;
                    break;
                }
                else
                {
                    if(count)
                    {
                        num[i] = '0';
                    }
                    else
                    {
                        break;
                    }
                }
            }
            if(count)
            {
                num[len++] = '1';
            }
            step += 2;
            ++c;
        }

    }
    return step;
}

int main()
{
    cout << numSteps("1101") << endl;
    cout << numSteps("1") << endl;
    cout << numSteps("10") << endl;
}