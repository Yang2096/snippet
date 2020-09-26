#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<vector<int>> ans;
void add(vector<int>& nums, vector<int>& line)
{
    vector<int> l;
    l.reserve(line.size());
    for(int a : line)
    {
        l.push_back(nums[a]);
    }
    ans.emplace_back(std::move(l));
}

void backTrace(vector<int>& nums, vector<int>& line, int len)
{
    int i;
    if(line.size() == 0)
        i = 0;
    else
        i = line.back() + 1;
    
    while(i < len)
    {
        line.push_back(i);
        add(nums, line);
        backTrace(nums, line, len);
        line.pop_back();
        do{
            ++i;
        }
        while(i < len && nums[i-1] == nums[i]);
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    ans.clear();
    int size = nums.size();
    vector<int> line;
    ans.push_back(line);
    backTrace(nums, line, size);
    return ans;
}

int main()
{
    vector<int> input={};
    auto ans = subsetsWithDup(input);
    for(auto &line : ans)
    {
        for(int a : line)
        {
            cout << a << ' ';
        }
        cout << endl;
    }
    
}