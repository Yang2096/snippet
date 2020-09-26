#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> ans;
    if(n < 3) return ans;
    
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n -2; ++i)
    {
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int sum = - nums[i];
        int left = i+1, right = n-1;
        while(left < right)
        {
            int temp = nums[left] + nums[right];
            if(temp == sum)
            {
                ans.push_back({nums[i], nums[left++], nums[right--]});
                while((left < n - 1) && (nums[left] == nums[left-1]))
                    ++left;
                while((right > i + 1) && (nums[right] == nums[right+1]))
                    --right;
            }
            else if(temp > sum)
            {
                --right;
            }
            else
            {
                ++left;
            }
        }
    }
    return ans;
}   

int main(int argc, char const *argv[])
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto ans = threeSum(nums);
    for(auto & three : ans)
    {
        for(int i : three)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
