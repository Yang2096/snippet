#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    vector<pair<double, int>> mtx(n, make_pair(0.0, 0));
    mtx[0] = make_pair(1.0, 0);
    for(auto& i : edges)
        if(i[0] > i[1])
            swap(i[0], i[1]);
    sort(edges.begin(), edges.end());
    for(auto & i : edges)
    {
        cout << i[0] << ' ' << i[1] << endl;
    }
    for(int i = 0; i < edges.size();)
    {
        int start = i;
        while(i < edges.size() && edges[i][0] == edges[start][0])
            i++;
        int size = i - start;
        
        for(int j = start; j < i; ++j)
        {
            int from = edges[j][0] - 1;
            int to = edges[j][1] - 1;
            mtx[to].first = mtx[from].first / size;
            mtx[to].second = mtx[from].second + 1;
            if(from + 1 == target)
                if(mtx[from].second < t)
                    mtx[from].first = 0.0;
        }
    }
    if(mtx[target - 1].second <= t)
        return mtx[target-1].first;
    else
        return 0.0;
}

int main()
{
    vector<vector<int>> edges = {{1,2},{1,3},{1,7},{2,4},{2,6},{3,5}};
    cout << frogPosition(7, edges, 2, 4) << endl;
    edges = {{2,1},{3,2},{4,1},{5,1},{6,4},{7,1},{8,7}};
    cout << frogPosition(8, edges, 7, 7) << endl;
}