#include<vector>
#include<iostream>
using namespace std;

int findMin(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1;
    while(left < right)
    {
        if(nums[right] < nums[right-1])
            return nums[right];
        int mid = (left + right) / 2;
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
    vector<int> nums = {3, 4, 5, 1, 2};
    cout << (findMin(nums) == 1) << endl;
    nums = {4, 5, 6, 7, 0, 1, 2};
    cout << (findMin(nums) == 0) << endl;
    nums = {2,1};
    cout << (findMin(nums) == 1) << endl;
    nums = {1};
    cout << (findMin(nums) == 1) << endl;
    nums = {4, 5, 6, 0, 1, 2};
    cout << (findMin(nums) == 0) << endl;
}