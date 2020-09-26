#include "pch.h"

bool stoneGame(vector<int> &piles)
{
    int n = piles.size();
    if(n <= 2)
        return true;

    vector<vector<int>> mine(n, vector<int>(n, 0));
    auto yours = mine;
    for (int j = 0; j < n; ++j)
    {
        mine[j][j] = piles[j];
        for (int i = j - 1; i >= 0; --i)
        {
            mine[i][j] = max(piles[i] + yours[i + 1][j], piles[j] + yours[i][j - 1]);
            yours[i][j] = min(mine[i + 1][j], mine[i][j - 1]);
        }
    }
    return mine[0][n - 1] > yours[0][n-1];
}

int main()
{
    vector<int> piles = {5, 3, 4, 5};
    cout << stoneGame(piles) << endl;
}