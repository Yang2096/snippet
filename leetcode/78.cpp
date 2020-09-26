#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int size = nums.size();
    if(0 == size) return ans;
    vector<bool> bits(size, false);
    vector<int> line;
    bool count = true;
    while(true)
    {
        for(int i = 0; i < size; ++i)
        {
            if(bits[i])
                line.push_back(nums[i]);
        }
        ans.emplace_back(std::move(line));
        int i = 0;
        count = true;
        do
        {
            if(bits[i])
            {
                bits[i++] = false;
            }
            else
            {
                bits[i++] = true;
                count = false;
            }
        }while(count && i < size);
        if(count && i == size)
        {
            return ans;
        }
    }
}

int main()
{
    vector<int> num = {1};
    auto print = [](vector<vector<int>> ans)->void{
        for(auto& line : ans)
        {
            for(int a : line)
            {
                cout << a << ' ';
            }
            cout << endl;
        }
    };
    print(subsets(num));
}