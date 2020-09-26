#include "pch.h"

void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    if(n <= 1 || k % n == 0)
        return;
    k = k % n;
    for (int i = 0; i < n / 2; ++i)
    {
        swap(nums[i], nums[n - i - 1]);
    }
    for (int i = 0; i < k/2; ++i)
    {
        swap(nums[i], nums[k - i - 1]);
    }
    for (int i = k; i < (n + k) / 2; ++i)
    {
        swap(nums[i], nums[n + k - i - 1]);
    }
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    rotate(nums, 1);
    auto print = [](vector<int> &nums) {
        for(int a : nums)
            cout << a << ' ';
        cout << endl;
    };
    print(nums);
    rotate(nums, 2);
    print(nums);
    nums = {1, 2, 3, 4, 5, 6};
    rotate(nums, 2);
    print(nums);
    nums = {1, 2, 3};
    rotate(nums, 2);
    print(nums);
}