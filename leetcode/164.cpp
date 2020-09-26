#include<vector>
#include<iostream>

using namespace std;

struct bucket{
    bool empty;
    int max_elem;
    int min_elem;
    bucket(int max, int min) : empty(true), max_elem(max), min_elem(min){};
};

int maximumGap(vector<int> &nums)
{
    if(nums.size() < 2)
        return 0;
    int max_num = nums[0], min_num = nums[0];
    for(int a : nums)
    {
        max_num = max(max_num, a);
        min_num = min(min_num, a);
    }

    int bucket_size = max(1u, (max_num - min_num) / (nums.size() - 1));
    int bucket_num = (max_num - min_num) / bucket_size + 1;

    vector<bucket> buckets(bucket_num, bucket(min_num, max_num));
    for(int a : nums)
    {
        int index = (a - min_num) / bucket_size;
        buckets[index].empty = false;
        buckets[index].max_elem = max(buckets[index].max_elem, a);
        buckets[index].min_elem = min(buckets[index].min_elem, a);
    }

    int ans = 0, prev = min_num;
    for (auto &b : buckets)
    {
        if(b.empty)
            continue;
        ans = max(ans, b.min_elem - prev);
        prev = b.max_elem;
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 200, 300, 555, 222, 666, 777, 444, 1001};
    cout << maximumGap(nums) << endl;
    nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << maximumGap(nums) << endl;
}
