#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int strStr(string text, string target)
{
    int m = target.size();
    if(0 == m) return 0;

    // 坏字符 : 将当前不匹配的字符(坏字符)与其在target中出现的最右位置对齐
    // 若不存在, 则将target移动到坏字符后方. 若意图向左移动, 则向右移动一位
    vector<int> bad_char(256, m);
    for(int i = 0; i < m; ++i)
    {
        bad_char[target[i]] = i;
    }
    
    // suffix 以i位置为结尾与以最后一个字符为结尾字符的字符串的公共后缀长度
    vector<int> suffix(m, 0);
    suffix[m-1] = m;
    for(int i = m - 2; i >=0; --i)
    {
        int count = 0;
        while((i - count >= 0) && (target[i-count] == target[m-1-count]))
            ++count;
        suffix[i] = count;
    }
    // 好后缀 
    // 1. 初始化为全m 表示后缀未重复出现过
    vector<int> good_suf(m, m);

    // 2. j位置的后缀的子串出现在文本开头 
    int j = 0;
    for(int i = m - 1; i >= 0; --i)
    {
        if(suffix[i] == i + 1)
        {
            for(; j < m - i - 1; ++j)
            {
                // 可以移动的长度
                if(good_suf[j] == m)
                    good_suf[j] = m - 1 - i;
            }
        }
    }
    // 3. m-1-suffix[i] 处后缀在前面出现过
    for(int i = 0; i <= m - 2; ++i)
    {
        good_suf[m - 1 - suffix[i]] = m - 1 - i;
    }

    int i = 0, n = text.size();
    while(i <= n - m)
    {
        int j = m - 1;
        while(j >= 0 && text[i+j] == target[j])
        {
            --j;
        }
        if(j < 0)
        {
            return i;
        }
        else
        {
            i += max(good_suf[j], j - bad_char[text[i+j]]);
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    string text("bbbbababbbaabbba");
    string target("abb");
    cout << strStr(text, target) << endl;
    cout << text.find(target) << endl;
    return 0;
}
