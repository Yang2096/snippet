#include<iostream>
#include<vector>
#include<queue>
using namespace std;
auto print = [](const vector<vector<int>> &m) {
    for (auto &line : m)
    {
        for (int a : line)
        {
            cout << a << ' ';
        }
        cout <<'\n';
    }
    cout << '\n';
};

int step[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if(matrix[i][j] == 0)
            {
                ans[i][j] = 0;
                q.emplace(i, j);
            }
        }
    }

    int current_size = q.size();
    int level = 1, xx, yy, x, y;
    pair<int, int> temp;
    while (!q.empty())
    {
        while(current_size--)
        {
            temp = q.front();
            x = temp.first;
            y = temp.second;
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                xx = x + step[i][0];
                yy = y + step[i][1];
                if(xx >= 0 && xx < n && yy >= 0 && yy < m)
                {
                    if(matrix[xx][yy] == 1 && ans[xx][yy] == -1)
                    {
                        q.emplace(xx, yy);
                        ans[xx][yy] = level;
                    }
                }
            }
        }
        current_size = q.size();
        level++;
    }
    return ans;
}

int main()
{

    vector<vector<int>> matrix = {{0, 0, 0},
                                  {0, 1, 0},
                                  {0, 0, 0}};
    print(updateMatrix(matrix));
    matrix = {{0, 0, 0},
              {0, 1, 0},
              {1, 1, 1}};
    print(updateMatrix(matrix));
    matrix = {{1, 1, 1},
              {1, 1, 0},
              {1, 1, 1}};
    print(updateMatrix(matrix));
}