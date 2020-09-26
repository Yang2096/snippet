#include "pch.h"

double maxProbability(int n, const vector<vector<int>> &edges,const vector<double> &succProb, int start, int end)
{
    vector<vector<pair<int, double>>> mat(n);
    int edge_num = edges.size();
    for (int i = 0; i < edge_num; ++i)
    {
        mat[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
        mat[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
    }




}


int main()
{
    cout << maxProbability(3, {{0, 1}, {1, 2}, {0, 2}}, {0.5, 0.5, 0.3}, 0, 2) << " 0.3" << endl;
}