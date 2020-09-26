#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

unordered_map<string, string> kv;

void store(string & s)
{
    int l = s.find('=');
    kv.emplace(s.substr(0, l), s.substr(l+1));
}

string replace(string a)
{
    size_t p = a.find('$');
    while (string::npos != p)
    {
        size_t end = a.find('}', p);
        auto data = kv.find(a.substr(p + 2, end - p - 2));
        a = a.substr(0, p) + data->second + a.substr(end + 1);
        p = a.find('$');
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    string s;
    while (n--)
    {
        cin >> s;
        store(s);
    }
    cout << replace(s.substr(s.find('=') + 1)) << endl;
}