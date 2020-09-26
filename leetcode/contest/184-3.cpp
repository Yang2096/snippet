#include<vector>
#include<string>
#include<iostream>
#include<tuple>
using namespace std;

string entityParser(string text) {
    auto s = vector<vector<int>>(27, vector<int>(256, 0));

    s[0]['&'] = 1;

    s[1]['a'] = 2;
    s[1]['g'] = 3;
    s[1]['l'] = 4;
    s[1]['f'] = 5;
    s[1]['q'] = 6;

    s[2]['p'] = 7;
    s[2]['m'] = 8;

    s[7]['o'] = 9;
    s[9]['s'] = 10;     
    s[10][';'] = 11;    // '

    s[8]['p'] = 12;
    s[12][';'] = 13;     // &

    s[3]['t'] = 14;
    s[14][';'] = 15;    // >

    s[4]['t'] = 16;
    s[16][';'] = 17;    // <

    s[5]['r'] = 18;
    s[18]['a'] = 19;
    s[19]['s'] = 20;
    s[20]['l'] = 21;
    s[21][';'] = 22;    // /

    s[6]['u'] = 23;
    s[23]['o'] = 24;
    s[24]['t'] = 25;
    s[25][';'] = 26;    // "

    s[11]['&'] = 1;
    s[13]['&'] = 1;
    s[15]['&'] = 1;
    s[17]['&'] = 1;
    s[22]['&'] = 1;
    s[26]['&'] = 1;    

    int state = 0, start = 0, end, ch;
    vector<tuple<int, int, char>> replace;
    for(int i = 0; i < text.length(); ++i)
    {
        state = s[state][(unsigned char)text[i]];
        switch(state)
        {
            case 1 :
            {
                start = i;
                break;
            }
            case 11 :
            {
                replace.emplace_back(start, i, '\'');
                break;
            }
            case 13 :
            {
                replace.emplace_back(start, i, '&');
                break;
            }
            case 15 :
            {
                replace.emplace_back(start, i, '>');
                break;
            }
            case 17 :
            {
                replace.emplace_back(start, i, '<');
                break;
            }
            case 23 :
            {
                replace.emplace_back(start, i, '/');
                break;
            }
            case 27 :
            {
                replace.emplace_back(start, i, '\"');
                break;
            }
            default:
                break;
        }
    }

    start = 0;
    string ans;
    for(auto & data : replace)
    {
        ans += text.substr(start, get<0>(data) - start);
        ans += get<2>(data);
        start = get<1>(data) + 1;
    }
    ans += text.substr(start);
    return ans;
}

int main()
{
    cout << entityParser("&quot;&frasl;&gt;&amp;&lt;&apos;") << endl;
}