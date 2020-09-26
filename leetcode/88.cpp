#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    if(n == 0) return;
    int tail = m + n - 1;
    while(m > 0 && n > 0)
    {
        if(nums1[m-1] > nums2[n-1])
        {
            nums1[tail] = nums1[--m];
        }
        else
        {
            nums1[tail] = nums2[--n];
        }
        --tail;
    }
    while(n > 0)
    {
        nums1[tail--] = nums2[--n];
    }
}

int main()
{
    vector<int> nums1 = {1,2,3,0,0,0,0};
    vector<int> nums2 = {2,5,6,7};
    merge(nums1, 0, nums2, 4);
    for(auto i : nums1)
    {
        cout << i << ' ';
    }
    cout << endl;
}