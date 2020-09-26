#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

vector<int> findSubstring(string s, vector<string>& words) 
{
    vector<int> ans;
    int n = words.size();
    if(n == 0) return ans;
    int len = s.length();
    int word_len = words[0].size();
    if(len < word_len * n) return ans;

    unordered_map<string, int> word_map;
    for(int i = 0; i < n; ++i)
    {
        if(word_map.find(words[i]) == word_map.end())
        {
            word_map[words[i]] = 1;
        }
        else
        {
            ++word_map[words[i]]; 
        }
    }
    decltype(word_map) temp_map;
    string sub;

    for(int offset = 0; offset < word_len; ++offset)
    {
        for(int i = 0; i <= len - word_len*n - offset; )
        {
            temp_map.clear();
            int k = 0;
            for(; k < n; ++k)
            {
                sub = s.substr(offset+i+word_len*k, word_len);
                auto match = word_map.find(sub);
                if(word_map.end() != match)
                {
                    if(temp_map.find(sub) == temp_map.end())
                    {
                        temp_map[sub] = 1;
                    }
                    else
                    {
                        ++temp_map[sub];
                    }
                }
                else
                {
                    break;
                }
            }
            if(k == n)
            {
                bool flag = true;
                for(auto & e : temp_map)
                {
                    if(word_map[e.first] != e.second)
                    {
                        flag = false;
                        break;
                    }
                }
                if(flag)
                {
                    ans.push_back(offset + i);
                }
                i += word_len;
            }
            else
            {
                i += word_len * (k+1);
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    string s = "barfoothefoobarman";
    vector<string> words = {"foo","bar"};
    for(auto index : findSubstring(s, words))
    {
        cout << index << " ";
    }
    s = "wordgoodgoodgoodbestword";
    words = {"word","good","best","word"};
    for(auto index : findSubstring(s, words))
    {
        cout << index << " ";
    }
    return 0;
}
