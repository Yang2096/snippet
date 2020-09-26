#include <iostream>
#include <string>
#include <vector>
using namespace std;

string countAndSay(int n) {
    if(n == 1) return "1";
    static string str_b;
    string ans("1");
    for(int i = 1; i<n; ++i)
    {
        str_b = "";
        int m = ans.size();
        char ch = ans[0];
        int count = 1;
        for(int j = 1; j < m; ++j)
        {
            if(ans[j] == ch)
            {
                ++count;
            }
            else
            {
                str_b += to_string(count);
                str_b += ch;
                ch = ans[j];
                count = 1;
            }
        }
        str_b += to_string(count);
        str_b += ch;
        ans = str_b;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    cout << countAndSay(n) << endl;
    return 0;
}
