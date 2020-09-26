#include <iostream>
#include <vector>
#include <string.h>
#include <queue>
#include <set>
using namespace std;


int sum(vector<vector<int>> & mat, vector<int> & step)
{
    int s = 0;
    for(int i = 0; i < step.size(); ++i)
    {
        s += mat[i][step[i]];
    }
    return s;
}

int kthSmallest(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();

    vector<int> step(m, 0);
    multiset<pair<int, vector<int>>> heap;
    int ans ;
    heap.emplace(sum(mat, step), step);
    for(int i = 1; i < k; ++i)
    {
        auto p = heap.begin();
        ans = p->first;
        auto v = p->second;
        heap.erase(p);
        for(int i = 0; i < m; ++i)
        {
            if(v[i] < n -1 )
            {
                v[i]++;
                heap.emplace(sum(mat, v), v);
                v[i]--;
            }

        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> mat = {{1, 3, 11}, {2, 4, 6}};
    cout << kthSmallest(mat, 5) << " 7" << endl;
    mat = { {1, 10, 10},
            {1, 4, 5},
            {2, 3, 6} };
    cout << kthSmallest(mat, 7) << " 9" << endl;
}