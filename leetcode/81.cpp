#include <iostream>
#include <vector>

using namespace std;

bool search(vector<int>& nums, int target) {
    // 二分法不是通过比较大小来选择区间  而是选择区间的一种方式是比较大小
    int left = 0, right = nums.size() - 1;
    int mid;
    while(left <= right)
    {
        mid = (right + left) / 2;
        if(nums[mid] == target) 
            return true;
        
        if(nums[mid] == nums[right])    // 重复的元素直接收缩区间
            --right;
        else if(nums[mid] < nums[right])    // 第一次选择  确定mid的左边还是右边才是有序的
        {
            if(nums[mid] < target && target <= nums[right]) // 第二次选择 在有序的区间上判断是否存在target
            {
                left = mid + 1;     // 区间的收缩方向确定第二次选择时区间两端与target相比较时的开闭
            }
            else
            {
                right = mid - 1;
            }
        }
        else
        {
            if(nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
            
        }
    }
    return false;
}

int main() 
{
    vector<int> nums = {2,5,6,0,0,1,2};
    cout << search(nums, 0) << endl;
    nums = {2,5,6,0,0,1,2};
    cout << search(nums, 3) << endl;
    nums = {2,3,4,5,1,1,2,2,2};
    cout << search(nums, 4) << endl;
    cout << search(nums, 5) << endl;
    cout << search(nums, 2) << endl;
    nums = {1,1,1,1,1,1,0,1,1};
    cout << search(nums, 0) << endl;
}