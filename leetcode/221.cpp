#include "pch.h"
int maximalSquare(vector<vector<char>> &matrix)
{
    int n = matrix.size();
    if (n == 0)
        return 0;
    int m = matrix[0].size();
    if(m == 0)
        return 0;

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(3, 0)));
    dp[0][0][0] = dp[0][0][2] = matrix[0][0] - '0';
    int ans = dp[0][0][2];
    for (int i = 1; i < m; ++i)
    {
        dp[0][i][0] = matrix[0][i] == '1' ? dp[0][i - 1][0] + 1 : 0;
        dp[0][i][2] = dp[0][i][1] = matrix[0][i] - '0';
        ans = max(ans, dp[0][i][2]);
    }
    for (int i = 1; i < n; ++i)
    {
        dp[i][0][2] = dp[i][0][0] = matrix[i][0] - '0';
        dp[i][0][1] = matrix[i][0] == '1' ? dp[i - 1][0][1] + 1 : 0;
        ans = max(ans, dp[i][0][2]);
        for (int j = 1; j < m; ++j)
        {
            if (matrix[i][j] == '1')
            {
                dp[i][j][0] = dp[i][j - 1][0] + 1;
                dp[i][j][1] = dp[i - 1][j][1] + 1;
                dp[i][j][2] = (min(dp[i][j][0], dp[i][j][1]) <= dp[i - 1][j - 1][2]) ? min(dp[i][j][0], dp[i][j][1]) : (dp[i-1][j-1][2] + 1);
                ans = max(ans, dp[i][j][2] * dp[i][j][2]);
            }
        }
    }
    return ans;
}

int main()
{
    vector<vector<char>> matrix = {{'1', '0', '1', '1', '1'},
                                   {'1', '0', '1', '0', '1'},
                                   {'1', '1', '1', '1', '1'},
                                   {'1', '0', '0', '1', '0'}};
    cout << maximalSquare(matrix) << endl;
    matrix = {{'0', '0', '0', '0', '0'}, {'1', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    cout << maximalSquare(matrix) << endl;
    matrix = {{'0', '0', '1', '0'},
              {'1', '1', '1', '1'},
              {'1', '1', '1', '1'},
              {'1', '1', '1', '0'},
              {'1', '1', '0', '0'},
              {'1', '1', '1', '1'},
              {'1', '1', '1', '0'}};
    cout << maximalSquare(matrix) << endl;
}