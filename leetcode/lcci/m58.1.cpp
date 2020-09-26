#include "pch.h"

void reverse(string &s, int left, int right)
{
    int mid = (left + right - 1) >> 1;
    for (int i = left; i <= mid; ++i)
    {
        swap(s[i], s[right - 1 - i + left]);
    }
}
string reverseWords(string s)
{
    int left = 0, right = s.length();
    while (left < right && s[left] == ' ')
        left++;
    while (right > 0 && s[right - 1] == ' ')
        right--;

    if (right < left)
        return "";

    reverse(s, left, right);

    int i = left, j = left;
    while (i < right)
    {
        while (j < right && s[j] != ' ')
            j++;
        reverse(s, i, j);
        while (j < right && s[j] == ' ')
            j++;
        i = j;
    }
    string ans;
    ans.reserve(right - left);
    i = left;
    j = 0;
    while (i < right)
    {
        if (s[i] == ' ')
            ans += ' ';
        while (s[i] == ' ')
            i++;
        ans += s[i++];
    }
    return ans;
}

int main()
{
    string s = " the sky i s   blue  ";
    cout << reverseWords(s) << endl;
    s = "the sky is blue";
    cout << reverseWords(s) << endl;
    s = " s ";
    cout << reverseWords(s) << endl;
    s = "  ";
    cout << reverseWords(s) << endl;
}