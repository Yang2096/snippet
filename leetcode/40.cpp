#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<vector<int>> ans;
void huisu(vector<int> & candidates, int target, vector<int> & index)
{
    int i = index.size() == 0 ? 0 : index[index.size() - 1] + 1;
    for(; i < candidates.size(); ++i)
    {
        if(target - candidates[i] == 0)
        {
            vector<int> temp;
            index.push_back(i);
            temp.reserve(index.size());
            for(auto j : index)
            {
                temp.push_back(candidates[j]);
            }
            ans.push_back(std::move(temp));
            index.pop_back();
            return;
        }
        else if(target - candidates[i] > 0)
        {
            index.push_back(i);
            huisu(candidates, target - candidates[i], index);
            index.pop_back();
            while(i+1 < candidates.size() && candidates[i+1] == candidates[i])
                ++i;
        }
        else
        {
            return ;
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    ans.clear();
    sort(candidates.begin(), candidates.end());
    int temp = 0;
    vector<int> index;
    huisu(candidates, target, index);
    return ans;
}

int main()
{
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    for(const auto & line : combinationSum2(candidates, target))
    {
        for(int e : line)
        {
            cout << e << ',';
        }
        cout << endl;
    }
}
