#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    if(4 > n) return vector<vector<int>>();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n - 3; ++i)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int target1 = target - nums[i];
        for(int j = i + 1; j < n - 2; ++j)
        {
            if(j > i + 1 && nums[j] == nums[j-1]) continue;
            int target2 = target1 - nums[j];
            int left = j + 1; 
            int right = n - 1;
            while(left < right)
            {
                int target3 = nums[left] + nums[right];
                if(target3 == target2)
                {
                    ans.push_back({nums[i], nums[j], nums[left++], nums[right--]});
                    while(left < n - 1 && nums[left] == nums[left-1]) ++left;
                    while(right > j && nums[right] == nums[right+1]) --right;
                }
                else if(target3 > target2)
                {
                    --right;
                }
                else
                {
                    ++left;
                }
            }
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 0, -1, 0};
    for(auto & four_number : fourSum(nums, 0))
    {
        for(auto number : four_number)
        {
            cout << number << " ";
        }
        cout << endl;
    }
    return 0;
}
