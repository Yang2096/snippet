#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

string simplifyPath(string path) {
    list<string> s;
    int stack_top = 0;
    int len = path.length();
    int begin = 0, sub_len = 0;
    for(int i = 0; i < len; ++i)
    {
        if('/' == path[i])
        {
            if(sub_len != 0)
            {
                string p = path.substr(begin, sub_len);
                if(p == "..")
                {
                    if(!s.empty())
                        s.pop_back();
                }
                else if(p != ".")
                    s.emplace_back(std::move(p));
                sub_len = 0;
            }
            begin = i + 1;
        }
        else
        {
            ++sub_len;
        }
    }
    if(sub_len != 0)
    {
        string p = path.substr(begin, sub_len);
        if(p == "..")
        {
            if(!s.empty())
                s.pop_back();
        }
        else if(p != ".")
            s.emplace_back(std::move(p));
    }
    string ans;
    if(s.empty())
        return "/";
    else
    {
        for(auto& p : s)
        {
            ans += '/' + p;
        }
    }
    return ans;
}

int main()
{
    cout << simplifyPath("/home/") << endl;
    cout << simplifyPath("/../") << endl;
    cout << simplifyPath("/home//foo/") << endl;
    cout << simplifyPath("/a/./b/../../c/") << endl;
    cout << simplifyPath("/a/../../b/../c//.//") << endl;
    cout << simplifyPath("/a//b////c/d//././/..") << endl;
    cout << simplifyPath("/../../../../../../a/") << endl;
    cout << simplifyPath("/./././././a/") << endl;
    cout << simplifyPath("//////aasdasda/asda/.////////") << endl;
}