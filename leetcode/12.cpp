#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int num2str(int num, string & ans,int base, char c1, char c2, char c3)
{
    for(int i = 0; i < num / base; ++i)
    {
        ans += c1;
    }
    num -= base * (num / base);
    if(num >= (base-base/10))
    {
        ans += c2;
        ans += c1;
        num -= (base-base/10);
    }else if(num >= base/2)
    {
        ans += c3;
        num -= base/2;
    }else if(num >= (base/2-base/10))
    {
        ans += c2;
        ans += c3;
        num -= (base/2-base/10);
    }
    return num;
}

string intToRoman(int num) {
    static string ans;
    ans = "";
    num = num2str(num, ans, 1000, 'M', 'C', 'D');
    num = num2str(num, ans, 100, 'C', 'X', 'L');
    num = num2str(num, ans, 10, 'X', 'I', 'V');
    for(int i=0;i<num;++i)
        ans+='I';
    return ans;
}

int main(int argc, char const *argv[])
{
    int num;
    while(cin>>num)
    {
        if(num==0) break;
        cout << intToRoman(num) << endl;
    }
    return 0;
}
