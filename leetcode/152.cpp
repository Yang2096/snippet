#include<vector>
#include<iostream>
using namespace std;

int maxProduct(vector<int> &nums)
{
    int ans = INT32_MIN, n = 1, p = 1;
    for (int a : nums)
    {
        if(a < 0)
        {
            swap(n, p);
        }
        p = max(a, p * a);
        n = min(a, n * a);
        ans = max(p, ans);
    }
    return ans;
}

int main()
{
    vector<int> nums = {2,3,-2,4};
    cout << (maxProduct(nums) == 6) << endl;
    nums = {-2, 0, -4};
    cout << (maxProduct(nums) == 0) << endl;
    nums = {-2, 2, -4};
    cout << (maxProduct(nums) == 16) << endl;
    nums = {0, 2, 0, -4, -2};
    cout << (maxProduct(nums) == 8) << endl;
    nums = { 2, -5, -2, -4, 3};
    cout << (maxProduct(nums) == 24) << endl;
}