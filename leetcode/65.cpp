#include <string>
#include <iostream>

using namespace std;

bool isNumber(string s)
{
    int state = 0;
    bool flag = false;
    for(char ch : s)
    {
        switch(ch)
        {
            case ' ':
            {
                if(state == 0 || state == 8)
                    break;
                else if(state == 2 || (flag && state == 3) || state == 4 || state == 7)
                    state = 8;
                else
                    return false;
                break;
            }
            case '-':
            case '+':
            {
                if(state == 0)
                    state = 1;
                else if(state == 5)
                    state = 6;
                else
                    return false;
                break;
            }
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                if(state == 0 || state == 1)
                {
                    state = 2;
                    flag = true;
                }
                else if(state == 3)
                    state = 4;
                else if(state == 5 || state == 6)
                    state = 7;
                else if(state != 2 && state != 4 && state != 7)
                    return false;
                break;
            }
            case '.':
            {
                if(state < 3)
                    state = 3;
                else
                    return false;
                break;
            }
            case 'e':
            {
                if(state == 2 || (flag && state == 3) || state == 4)
                    state = 5;
                else 
                    return false;
                break;
            }
            default:
                return false;
        }
    }
    return state == 2 || (flag && state == 3) || state == 4 || state == 7 || state == 8;
}


int main()
{
    string test[] = {
        "0", " 0.1", "2e10", " -90e3", "53.5e92    ", "10e-1", "-10e+1", ".12", "-.12", "10.", "  1.  ", "abc", " --6", " 1e", " e3", "12e34e56", ".", ".e4", "1 4"
    };
    for(auto& s : test)
    {
        cout << isNumber(s) << ' ' << s << '\n';
    }
}