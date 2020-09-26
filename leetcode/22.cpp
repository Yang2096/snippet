#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void generator(vector<string> & ans, string s, int unmatched, int rest)
{
    if(rest == 0)
    {
        ans.push_back(s);
        return;
    }
    if(unmatched < rest)
        generator(ans, s + '(', unmatched + 1, rest);
    if(unmatched > 0)
        generator(ans, s + ')', unmatched - 1, rest - 1);
}


vector<string> generateParenthesis(int n) {
    vector<string> ans;
    generator(ans, "", 0, n);
    return ans;
}



int main(int argc, char const *argv[])
{
    for(auto & str : generateParenthesis(4))
    {
        cout << str << endl;
    }
    return 0;
}
