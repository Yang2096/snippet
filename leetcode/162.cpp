#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int> &nums)
{
    int left = 0, right = nums.size() - 1, mid;
    while(left < right)
    {
        mid = (left + right) / 2;
        if(mid + 1 < nums.size())
        {
            if(nums[mid + 1] > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        else
        {
            return mid;
        }
    }
    //cout << left << ' ' << mid << ' ' << right << endl;
    return right;
}

int main()
{
    vector<int> nums = {1,2,3,1};
    cout << findPeakElement(nums) << endl;
    nums = {1,2,1,3,5,6,4};
    cout << findPeakElement(nums) << endl;
    nums = {1,2,3,4,5,6,7,8};
    cout << findPeakElement(nums) << endl;
    nums = {2,1};
    cout << findPeakElement(nums) << endl;
    nums = {3, 2, 1};
    cout << findPeakElement(nums) << endl;
}