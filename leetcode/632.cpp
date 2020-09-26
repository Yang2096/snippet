#include "pch.h"
vector<int> smallestRange(vector<vector<int>> &nums)
{
    int k = nums.size();
    if (k == 1)
        return {nums[0][0], nums[0][0]};
    int include_count = 0, ans = INT32_MAX, left, right;

    priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int> &, pair<int, int> &)>> heap([](pair<int, int> &a, pair<int, int> &b) { return a.first > b.first; });
    for (int i = 0; i < k; ++i)
        heap.emplace(nums[i][0], i);
    include_count = 0;
    vector<int> visited(k, 1);
    vector<int> range_count(k, 0);

    queue<pair<int, int>> q;
    while (true)
    {
        while (include_count < k)
        {
            if (heap.empty())
                return {left, right};
            auto p = heap.top();
            heap.pop();
            q.push(p);
            if (range_count[p.second]++ == 0)
                include_count++;
            if (visited[p.second] < nums[p.second].size())
            {
                heap.push(make_pair(nums[p.second][visited[p.second]++], p.second));
            }
        }

        while (include_count >= k)
        {
            if (ans > q.back().first - q.front().first)
            {
                ans = q.back().first - q.front().first;
                left = q.front().first;
                right = q.back().first;
            }            
            auto p = q.front();
            q.pop();
            if (--range_count[p.second] == 0)
            {
                include_count--;
            }
        }
    }
}

int main()
{
    vector<vector<int>> nums = {{4, 10, 15, 24, 26},
                                {0, 9, 12, 20},
                                {5, 18, 22, 30}};
    auto ans = smallestRange(nums);
    for(int a : ans)
        cout << a << ' ';
}