#include<iostream>
#include<vector>
using namespace std;

int findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1, mid;
    while(left < right)
    {
        while(left < nums.size() - 1 && nums[left] == nums[left+1])
            left++;
        while(right > 1 && nums[right] == nums[right-1])
            right--;
        
        if (nums[right] < nums[right - 1])
            return nums[right];
        mid = (left + right) / 2;
        if(nums[mid] > nums[right])
        {
            left = mid + 1;
        }
        else
        {
            right = mid;
        }
    }
    return nums[left];
}

int main()
{
    vector<int> nums = {3, 4, 5, 1, 1, 2};
    cout << (findMin(nums) == 1) << endl;
    nums = {4, 5, 6, 6, 6, 6, 7, 0,0,0,0, 1, 2};
    cout << (findMin(nums) == 0) << endl;
    nums = {2, 2, 1, 2};
    cout << (findMin(nums) == 1) << endl;
    nums = {2, 1, 1, 2};
    cout << (findMin(nums) == 1) << endl;
    nums = {1, 1};
    cout << (findMin(nums) == 1) << endl;
    nums = {1};
    cout << (findMin(nums) == 1) << endl;
    nums = {4, 5, 6, 0, 1, 2, 2, 2, 2};
    cout << (findMin(nums) == 0) << endl;
}