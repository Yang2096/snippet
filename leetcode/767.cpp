#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

string reorganizeString(string S) {
    int total = S.length();
    if(total == 1) return S;
    using c_pair = pair<int, char>;
    vector<c_pair> alphabet(26, {0,0});
    int max = -1;
    for(char c : S)
    {
        if(++alphabet[c-'a'].first > max)
        {
            max = alphabet[c-'a'].first;
        }
    }

    if(max - 1 > total - max)
    {
        return "";
    }
    else
    {
        int char_count = 0;
        for(int i = 0; i < 26; ++i)
        {
            if(alphabet[i].first) 
            {
                alphabet[i].second = 'a' + i;
               ++char_count;
            }
        }
        auto comp = [](c_pair&a, c_pair&b){ return a.first > b.first; };
        sort(alphabet.begin(), alphabet.end(), comp);
        int count = 0;
        char _s[total];
        for(int i = 0; i < char_count; ++i)
        {
            int temp = alphabet[i].first;
            while(temp-- > 0)
            {
                _s[count++] = alphabet[i].second;
            }
        }
        count = 0;
        int max_count = 0;
        while(max_count < max)
        {
            S[count++] = _s[0];
            int follow = max_count++ + max;
            while(follow < total)
            {
                S[count++] = _s[follow];
                follow+=max;
            }
        }
        return S;
    }
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << reorganizeString(s) << endl;
    return 0;
}
