#include "pch.h"

int search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if(nums[mid] == target)
            return mid;
        else
        {
            if(nums[mid] < nums[left])
            {
                if(nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                if(nums[mid] > target && target >= nums[left])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 0) << " 4" << endl;
    cout << search(nums, 3) << " -1" << endl;
    nums = {1};
    cout << search(nums, 1) << " 0" << endl;
    nums = {2,1};
    cout << search(nums, 1) << " 1" << endl;
}