#include "pch.h"
vector<int> countSmaller(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return {};
    if (n == 1)
        return {0};
    vector<int> ans(n), temp(n), index(n), index_temp(n);
    for (int i = 0; i < n; ++i)
        index[i] = i;

    int k = 1;
    while (k < n)
    {
        int base = 0, a_idx = 0;
        while (base < n)
        {
            int left = 0, right = 0;
            while (left < k && left + base < n && right < k && right + base + k < n)
            {
                if (nums[left + base] > nums[right + base + k])
                {
                    index_temp[a_idx] = index[right + base + k];
                    temp[a_idx++] = nums[right++ + base + k];
                }
                else
                {
                    index_temp[a_idx] = index[left + base];
                    ans[index[left + base]] += right;
                    temp[a_idx++] = nums[left++ + base];
                }
            }
            while (left < k && left + base < n)
            {
                index_temp[a_idx] = index[left + base];
                ans[index[left + base]] += right;
                temp[a_idx++] = nums[left++ + base];
            }
            while (right < k && right + base + k < n)
            {
                index_temp[a_idx] = index[right + base + k];
                temp[a_idx++] = nums[right++ + base + k];
            }
            base += (k << 1);
        }
        k <<= 1;
        swap(index_temp, index);
        swap(temp, nums);
    }
    return ans;
}

int main()
{
    vector<int> nums = {5, 2, 6, 1, 4, 6, 9, 2, 4, 6, 0};
    auto ans = countSmaller(nums);
    for(int a : ans)
        cout << a << ' ';
    cout << endl;
}