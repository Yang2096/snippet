#include "pch.h"

string addStrings(string num1, string num2)
{
    int n = num1.length();
    int m = num2.length();
    vector<char> sum(max(m, n) + 1, 0);
    int i = n - 1, j = m - 1, count = 0, current = 0;
    while (i >= 0 && j >= 0)
    {
        sum[current] = ((num1[i] - '0' + num2[j] - '0' + count) % 10) + '0';
        count = (num1[i] - '0' + num2[j] - '0' + count) / 10;
        --i;
        --j;
        ++current;
    }

    while (i >= 0)
    {
        sum[current] = (num1[i] - '0' + count) % 10 + '0';
        count = (num1[i] - '0' + count) / 10;
        --i;
        ++current;
    }

    while (j >= 0)
    {
        sum[current] = (num2[j] - '0' + count) % 10 + '0';
        count = (num2[j] - '0' + count) / 10;
        --j;
        ++current;
    }
    if(count == 1)
        sum[current] = '1';
    while (sum.back() == 0)
        sum.pop_back();
    return string(sum.rbegin(), sum.rend());
}

int main()
{
    cout << addStrings("99999999", "11") << endl;
}