#include <iostream>
#include <vector>
using namespace std;

bool canJump(vector<int>& nums) {
    int max = 0;
    int n = nums.size();
    if(n == 1) return true;
    for(int i=0;i<n-1; ++i)
    {
        if(i > max)
            return false;
        if(nums[i] + i > max)
            max = nums[i] + i;
        if(max >= n-1)
            return true;
    }
    return false;
}

int main() {
    vector<int> nums = {0};
    cout << canJump(nums) << endl;
    return 0;
}