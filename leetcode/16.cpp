#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
#define INT_MIN     (-2147483647 - 1)
#define INT_MAX       2147483647

int threeSumClosest(vector<int>& nums, int target) {
    int n = nums.size();
    int diff = INT_MAX;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n - 2; ++i)
    {
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int sum = target - nums[i];
        int left = i+1, right = n-1;
        while(left < right)
        {
            int temp = nums[left] + nums[right];
            if(temp == sum)
            {
                return target;
            }
            else if(temp > sum)
            {
                --right;
            }
            else
            {
                ++left;
            }
            diff = std::abs(diff) < std::abs(sum - temp) ? diff : sum - temp;
        }
    }
    return target - diff;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {0,0,0};
    auto ans = threeSumClosest(nums, 1);
    cout << ans << endl;
    return 0;
}