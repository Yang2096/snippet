#include "pch.h"

int reversePairs1(vector<int> &nums)
{
    int ans = 0;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i + 1; j < nums.size(); ++j)
        {
            if(nums[i] > nums[j])
                ans++;
        }
    }
    return ans;
}

int reversePairs(vector<int> nums)
{
    int pair_count = 0;
    int n = nums.size();
    int k = 1, left, right, step;
    vector<int> temp(n);
    while (k < n)
    {
        step = 0;
        for (int i = 0; i < n; i += 2 * k)
        {
            left = right = 0;
            while (left < k && right < k && right + i + k < n)
            {
                if(nums[left + i] > nums[right + i + k])
                {
                    temp[step++] = nums[right + i + k];
                    right++;
                }
                else
                {
                    temp[step++] = nums[left + i];
                    left++;
                    pair_count += right;
                }
            }
            while(left < k && left + i < n)
            {
                temp[step++] = nums[left++ + i];
                pair_count += right;
            }
            while (right < k && right + i + k < n)
                temp[step++] = nums[right++ + i + k];
        }
        k <<= 1;
        using std::swap;
        swap(temp, nums);
    }
    //for(int a : nums)
    //{
    //    cout << a << ' ';
    //}
    //cout << endl;
    return pair_count;
}

int main()
{
    vector<int> nums = {7, 5, 6, 4};
    cout << reversePairs(nums) << " 5" << endl;
    nums = {7, 5, 6, 4, 1, 3, 8, 2, 9};
    cout << reversePairs(nums) <<  ' ' << reversePairs1(nums) << endl;
}