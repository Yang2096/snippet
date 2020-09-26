#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int step[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int count(int i)
{
    int sum = 0;
    while (i > 0)
    {
        sum += i % 10;
        i /= 10;
    }
    return sum;
}
bool mat[101][101];
int movingCount(int m, int n, int k)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    memset(mat, 0, sizeof(mat));
    mat[0][0] = true;
    int sum = 1, xx, yy;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            xx = x + step[i][0];
            yy = y + step[i][1];
            if (xx >= 0 && xx < m && yy >= 0 && yy < n && !mat[xx][yy])
            {
                if (count(xx) + count(yy) <= k)
                {
                    q.push({xx, yy});
                    sum++;
                    mat[xx][yy] = true;
                }
            }
        }
    }
    return sum;
}


int main()
{
    cout << movingCount(2, 3, 1) << endl;
}