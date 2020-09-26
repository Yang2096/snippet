#include <vector>
#include <iostream>
using namespace std;
inline int min(int a, int b)
{
    return a < b ? a : b;
}
inline int max(int a, int b)
{
    return a < b ? b : a;
}
int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<int> dp(m, 0);
    dp[0] = grid[0][0];
    for(int i = 1; i < m; ++i)
    {
        dp[i] = dp[i-1] + grid[0][i];
    }
    for(int i = 1; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(0 == j)
            {
                dp[j] += grid[i][0];
            }
            else
            {
                dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
            }
        }
    }
    return dp[m-1];
}

int main()
{
    vector<vector<int>> grid = {{1,3,1},
                                {1,5,1},
                                {4,2,1}};
    cout << minPathSum(grid) << endl;
}