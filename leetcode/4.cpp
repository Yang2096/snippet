#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> step = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int minCost(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> mark(m, vector<int>(n, -1));
    mark[0][0] = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    pair<int, int> current;
    int x, y, xx, yy, new_;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        x = current.first;
        y = current.second;
        for(int i = 1; i <= 4; ++i)
        {
            xx = x + step[i][0];
            yy = y + step[i][1];
            if(xx >= 0 && xx < m && yy >=0 && yy < n)
            {
                if(i == grid[x][y])
                    new_ = mark[x][y];
                else
                    new_ = mark[x][y] + 1;
                
                if(mark[xx][yy] == -1 || mark[xx][yy] > new_)
                {
                    mark[xx][yy] = new_;
                    q.push(make_pair(xx, yy));
                }
            }
        }
    }
    return mark[m-1][n-1];
}

int main()
{
    vector<vector<int>> grid = {{1,1,1,1},{2,2,2,2},{1,1,1,1},{2,2,2,2}};
    cout << minCost(grid) << endl;
    grid = {{1,1,3},{3,2,2},{1,1,4}};
    cout << minCost(grid) << endl;
    grid = {{1,2},{4,3}};
    cout << minCost(grid) << endl;
    grid = {{2,2,2},{2,2,2}};
    cout << minCost(grid) << endl;
    
    
}