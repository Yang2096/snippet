#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> ans;
void huisu(int k, int target, vector<int> & index)
{
    int i = index.size() == 0 ? 1 : index[index.size() - 1] + 1;
    for(; i < 10 && i <= target; ++i)
    {
        if(target == i)
        {
            vector<int> temp;
            index.push_back(i);
            if(index.size() == k)
                ans.push_back(index);
            index.pop_back();
            return;
        }
        else if(target > i)
        {
            index.push_back(i);
            huisu(k, target - i, index);
            index.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int target) {
    ans.clear();
    int temp = 0;
    vector<int> index;
    huisu(k, target, index);
    return ans;
}

int main()
{
    int k = 3;
    int target = 9;
    for(const auto & line : combinationSum3(k, target))
    {
        for(int e : line)
        {
            cout << e << ',';
        }
        cout << endl;
    }
}
