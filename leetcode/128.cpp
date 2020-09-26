#include<vector>
#include<iostream>
#include<unordered_map>

using namespace std;

int longestConsecutive(vector<int> & nums)
{
    int max_length = 1, current_length;
    unordered_map<int, int> map;
    for(int num : nums)
    {
        int length = 1;
        if(map.find(num) != map.end())
            continue;
        auto left = map.find(num - 1);
        if(left != map.end())
            length += left->second;
        auto right = map.find(num + 1);
        if(right != map.end())
        {
            length += right->second;
            map[right->second + num] = length;
        }
        if(left != map.end())
        {
            map[num - left->second] = length;
        }
        map[num] = length;
        cout << num << ' ' << length << endl;
        max_length = max(length, max_length);
    }
    cout << "------------------" << endl;
    for(auto& p : map)
    {
        cout << p.first << ' ' << p.second << endl;
    }
    return max_length;
}

int main()
{
    vector<int> input = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    cout << longestConsecutive(input) << endl;
}