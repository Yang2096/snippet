#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> direction = { {1,0}, {0,1}, {-1,0}, {0,-1}};

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    int n = matrix.size();
    if(n == 0) return result;
    int m = matrix[0].size();
    vector<vector<bool>> mark(n, vector<bool>(m, true));
    int d = 0;
    int x = 0;
    int y = 0;
    while(true)
    {
        if(mark[x][y])
        {
            result.push_back(matrix[x][y]);
            mark[x][y] = false;
        }
        int next_x = x + direction[d][1];
        int next_y = y + direction[d][0];
        if(next_x >= n || next_x < 0 || next_y >= m || next_y < 0 || !mark[next_x][next_y])
        {
            d = (d+1)%4;
            x += direction[d][1];
            y += direction[d][0];
        }
        else
        {
            x = next_x;
            y = next_y;
        }
        if(x >= n || x < 0 || y >= m || y < 0 || !mark[x][y])
            break;
    }
    return result;
}

int main() {
    vector<vector<int>> matrix = {
        {1}};
    auto result = spiralOrder(matrix);
    for(auto i : result)
    {
        cout << i << " ";
    }
    return 0;
}