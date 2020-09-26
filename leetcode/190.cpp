#include "pch.h"

uint32_t reverseBits(uint32_t n)
{
    uint32_t ans = 0;
    for (int i = 0; i < 32; ++i)
    {
        ans |= (n & 1) << (31 - i);
        n >>= 1;
    }
    return ans;
}

int main()
{
    uint32_t n = 0x12345678;
    cout << hex << reverseBits(n) << endl;
}