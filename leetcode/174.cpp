#include <iostream>
#include <vector>

using namespace std;


void print(vector<vector<int>> dp)
{
    for (auto &line : dp)
    {
        for (auto &p : line)
        {
            cout << p << ' ';
        }
        cout << endl;
    }
}

int calculateMinimumHP(vector<vector<int>> &dungeon)
{
    int n = dungeon.size();
    int m = dungeon[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[n-1][m-1] = max(1, 1 - dungeon[n-1][m-1]);

    for(int i = m - 2; i>= 0; --i)
    {
        dp[n-1][i] = max(1, dp[n-1][i+1] - dungeon[n-1][i]);
    }


    for(int i = n - 2; i >= 0; --i)
    {
        dp[i][m-1] = max(1, dp[i+1][m-1] - dungeon[i][m-1]);
        for(int j = m - 2; j >= 0; --j)
        {
            dp[i][j] = max(1, min(dp[i][j + 1], dp[i+1][j]) - dungeon[i][j]);
        }
    }
    print(dp);
    return dp[0][0];
}

int main()
{
    vector<vector<int>> dungeon = { {-2, -3, 3},
                                    {-5, -10, 1},
                                    {10, 30, -5} };
    cout << calculateMinimumHP(dungeon) << endl; 
    dungeon = {{1,-2,3},
                {2,-2,-2}};
    cout << calculateMinimumHP(dungeon) << endl;
}