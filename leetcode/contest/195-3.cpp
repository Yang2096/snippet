#include "pch.h"
#include <math.h>
int fast_pow(int n)
{
    long long temp = 2, ans = 1;
    while(n)
    {
        if(n & 1)
            ans = (ans * temp) % 1000000007;
        temp = (temp * temp) % 1000000007;
        n >>= 1;
    }
    return ans;
}
int numSubseq(vector<int> &nums, int target)
{
    int n = nums.size();   
    sort(nums.begin(), nums.end());
    if(nums[n-1] + nums[n-1] <= target)
        return pow(2, n) - 1;
    if(nums[0] + nums[0] > target)
        return 0;

    long long ans = 0;
    int pow2 = 1;
    for (int i = 0; i < n; ++i)
    {
        if(nums[i] + nums[0] > target)
            break;
        
        if(nums[i] + nums[i] <= target)
            ans = (ans + pow2) % 1000000007;
        else
        {
            auto it = upper_bound(nums.begin(), nums.begin() + i, target - nums[i]);
            ans = (ans + pow2 + 1000000007 - fast_pow(distance(it, nums.begin() + i))) % 1000000007;
        }
        pow2 = (pow2 << 1) % 1000000007;
    }
    return ans;
}

int main()
{
    vector<int> nums;
    nums = {1, 2, 3, 4, 5};
    cout << numSubseq(nums, 7) << " 17" << endl;
    nums = {2, 3, 3, 4, 6, 7};
    cout << numSubseq(nums, 12) << " 61" << endl;
    nums = {5, 2, 4, 1, 7, 6, 8};
    cout << numSubseq(nums, 16) << " 127" << endl;
}