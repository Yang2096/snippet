#include "pch.h"
class MountainArray
{
public:
    int get(int index)
    {
        count++;
        return _nums[index];
    };
    int length(){
        return _nums.size();
    };
    MountainArray(const vector<int> nums) : _nums(nums), count(0){};
    MountainArray & operator=(const vector<int> &nums)
    {
        count = 0;
        _nums = nums;
        return *this;
    }
    int count;
private:
    vector<int> _nums;
};

int n;
int binary_search(int left, int right, int target, MountainArray &moutainArr)
{
    int mid, value, left_value, right_value, index;
    if(left > right)
        return -1;
    mid = (right + left) / 2;
    value = moutainArr.get(mid);
    if(mid > 0)
        left_value = moutainArr.get(mid - 1);
    else
        left_value = -1;
    

    if(mid < n-1)
        right_value = moutainArr.get(mid + 1);
    else
        right = -1;
    
    if (left_value < value && value < right_value)
    {
        if(target == value)
            return mid;
        else if (value < target)
        {
            return binary_search(mid + 1, right, target, moutainArr);
        }
        else
        {
            index = binary_search(left, mid - 1, target, moutainArr);
            if(index != -1)
                return index;
            else
                return binary_search(mid + 1, right, target, moutainArr);
        }
    }
    else if(left_value < value && value > right_value)
    {
        if(target == value)
            return mid;
        else if(value < target)
            return -1;
        else 
        {
            index = binary_search(left, mid - 1, target, moutainArr);
            if(index != -1)
                return index;
            else
                return binary_search(mid + 1, right, target, moutainArr);
        }
    }
    else
    {
        index = binary_search(left, mid - 1, target, moutainArr);
        if(index != -1)
            return index;
        else if(target == value)
            return mid;
        else if(value > target)
        {
            return binary_search(mid + 1, right, target, moutainArr);
        }
        return -1;
    }
}

int findInMountainArray(int target, MountainArray &mountainArr)
{
    n = mountainArr.length();
    return binary_search(0, n-1, target, mountainArr);
}

int main()
{
    MountainArray mountainArr({1, 2, 3, 4, 5, 3, 1});
    cout << findInMountainArray(3, mountainArr) << " 2 " << mountainArr.count << endl;
    mountainArr = {0, 1, 2, 4, 2, 1};
    cout << findInMountainArray(3, mountainArr) << " -1 " << mountainArr.count << endl;
    mountainArr = {0, 5, 3, 1};
    cout << findInMountainArray(1, mountainArr) << " 3 " << mountainArr.count << endl;
}