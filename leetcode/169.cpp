#include<iostream>
#include<vector>

using namespace std;


int partition(vector<int> &nums, int left, int right)
{
    int low = left, high = left;
    int p = right, v = nums[right];
    while(high < p)
    {
        if(nums[high] < v)
        {
            swap(nums[high], nums[low]);
            low++;
        }
        high++;
    }
    swap(nums[p], nums[low]);
    return low;
}

int quickSort(vector<int> &nums, int left, int right, int pos)
{
    int k = partition(nums, left, right);
    if (k == pos)
        return nums[k];
    else if (k > pos)
        return quickSort(nums, left, k - 1, pos);
    else
        return quickSort(nums, k + 1, right, pos);
}

int majorityElement(vector<int> &nums)
{
    return quickSort(nums, 0, nums.size() - 1, nums.size() / 2);
}

int main()
{
    vector<int> nums = {3,3};
    cout << majorityElement(nums) << endl;
}