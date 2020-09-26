#include "pch.h"

int rangeBitwiseAnd(int m, int n)
{
    int ans = 0;
    for (int i = 31; i >= 0; --i)
    {
        if(m & (1 << i) && n & (1 << i))
        {
            ans |= 1 << i;
        }
        else if(m & (1 << i) || n & (1 << i))
        {
            break;
        }
    }
    return ans;
}

int force(int m, int n)
{
    int ans = m;
    for (int i = m + 1; i <= n; ++i)
    {
        ans &= i;
    }
    return ans;
}

int main()
{
    cout << rangeBitwiseAnd(5, 7) << ' ' << force(5, 7) << endl;
    cout << rangeBitwiseAnd(0xf000c, 0xf0f0f) << ' ' << force(0xf000c, 0xf0f0f) << endl;
}