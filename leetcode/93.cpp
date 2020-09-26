#include<iostream>
#include<string> 
#include<vector>

using namespace std;

vector<string> ans;
int split[4];
void backTrace(string &s, int layer, int comma)
{
    if(layer == 4)
    {
        //cout << split[0] << split[1] << split[2] << comma << endl;
        if(comma == s.length())
        {
            string line;
            line += s.substr(0, split[0]) + '.';
            line += s.substr(split[0], split[1] - split[0]) + '.';
            line += s.substr(split[1], split[2] - split[1]) + '.';
            line += s.substr(split[2], comma - split[2]);
            ans.emplace_back(std::move(line));
        }
        return;
    }
    
    int current = 0;
    for(int i = 0; i < 3; ++i)
    {
        current *= 10;
        current += (s[comma + i]-'0');
        if(current > 255)
            break;
        split[layer] = comma + i + 1;
        backTrace(s, layer + 1, comma + i + 1);
        if(current == 0)
            break;
    }
}

vector<string> restoreIpAddresses(string s) {
    ans.clear();
    backTrace(s, 0, 0);
    return ans;
}

int main()
{
    auto ans = restoreIpAddresses("25525511135");
    for(auto & line : ans)
    {
        cout << line << endl;
    }
    ans = restoreIpAddresses("0000");
    for(auto & line : ans)
    {
        cout << line << endl;
    }
    ans = restoreIpAddresses("0255100");
    for(auto & line : ans)
    {
        cout << line << endl;
    }
}