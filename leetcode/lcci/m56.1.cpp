#include "pch.h"

vector<int> singleNumbers(vector<int> &nums)
{
    int xo = 0;
    for(int a : nums)
        xo ^= a;
    int bit_index = 0;
    while(bit_index < 32)
    {
        if(xo & (1 << bit_index))
            break;
        bit_index++;
    }

    int first = 0, second = 0;
    for(int a : nums)
    {
        if(a & (1 << bit_index))
            first ^= a;
        else
            second ^= a;
    }
    return {first, second};
}

int main()
{
    vector<int> nums = {1, 2, 10, 4, 1, 4, 3, 3};
    auto ans = singleNumbers(nums);
    cout << ans[0] << ' ' << ans[1] << endl;
}