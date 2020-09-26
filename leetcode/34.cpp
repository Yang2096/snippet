#include <iostream>
#include <vector>
using namespace std;

int left_search(vector<int> & nums, int left, int right, int target)
{
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] == target)
        {
            if(mid == left || nums[mid - 1] < target)
                return mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}
int right_search(vector<int> & nums, int left, int right, int target)
{
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] == target)
        {
            if(mid == right || target < nums[mid + 1])
                return mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0, right = nums.size()-1;
    if(right == -1) return vector<int>();
    vector<int> ans = {-1, -1};
    if(right == 0) return nums[0] == target ? vector<int>({0,0}) : ans;

    while(left <= right)
    { 
        int mid = left + (right - left)/2;
        if(target == nums[mid])
        {
            ans[0] = left_search(nums, left, mid, target);
            ans[1] = right_search(nums, mid, right, target);
            break;
        }
        else if(target > nums[mid])
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    vector<int> nums = {5,7,7,8,8,10};
    for(auto e : searchRange(nums, 8))
    {
        cout << e << " ";
    }
    nums = {5,7,7,8,8,10};
    for(auto e : searchRange(nums, 6))
    {
        cout << e << " ";
    }
    nums = {7, 8};
    for(auto e : searchRange(nums, 6))
    {
        cout << e << " ";
    }
    return 0;
}
