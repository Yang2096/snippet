#include <iostream>
#include <vector>
using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    if(n == 0) return 0;
    int left = 0, right = n - 1;
    if(target <= nums[0]) return 0;
    if(target > nums[right]) return n;

    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(target == nums[mid])
        {
            return mid;
        }
        else if(target < nums[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }

    }
    return left;
}

int main()
{
    vector<int> nums = {1,3,4,5};
    cout << searchInsert(nums, 2) << endl;
    return 0;
}