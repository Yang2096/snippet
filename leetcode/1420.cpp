#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

long long dp[51][101][51];
int numOfArrays(int n, int m, int k)
{
    if(m < k || n < k)
        return 0;
    memset(dp, 0, sizeof(dp));


    for(int i = 1; i <= m; ++i)
        dp[1][i][1] = 1;
    for(int i = 1; i <= n; ++i)
        dp[i][1][1] = 1;

    for (int c = 1; c <= k; ++c)
        for (int a = 2; a <= n; ++a)
        {
            int temp = 0;
            for (int b = 2; b <= m; ++b)
            {
                if (c > a || c > b)
                    dp[a][b][c] = 0;
                else
                {
                    dp[a][b][c] = (temp + dp[a - 1][b - 1][c - 1] + b * dp[a - 1][b][c]) % 1000000007;
                    temp = (temp + dp[a - 1][b - 1][c - 1]) % 1000000007;
                }
            }
        }

    long long ans = 0;
    for(int i = 1; i <= m; ++i)
    {
        ans = (ans + dp[n][i][k]) % 1000000007;
    }
    
    return ans;
}

int numOfArrays1(int n, int m, int k)
{
    if (m < k || n < k)
        return 0;
    if (m == 1)
        return 1;
    if(n == 1 && k == 1)
        return m;
    int ans = 0;

    ans = numOfArrays1(n-1, m-1, k-1);
    
    if(n > 0)
        ans = (ans + m * numOfArrays1(n - 1, m, k)) % 1000000007;
    return ans;
}

int main()
{
    cout << numOfArrays(1, 2, 1) << " 2" << endl;
    cout << numOfArrays(2, 2, 1) << " 3" << endl;
    cout << numOfArrays(2, 3, 1) << " 6" << endl;
    cout << numOfArrays(3, 2, 2) << " 3" << endl;
    cout << numOfArrays(3, 2, 1) << " 5" << endl;
    cout << numOfArrays(3, 3, 2) << " 12" << endl;
    cout << numOfArrays(3, 3, 1) << " 14" << endl;
    cout << numOfArrays(5, 2, 3) << " 0" << endl;
    cout << numOfArrays(4, 3, 2) << " 39" << endl;
    cout << numOfArrays(5, 4, 3) << " 160" << endl;
    cout << numOfArrays(9, 1, 1) << " 1" << endl;
    cout << numOfArrays(50, 100, 25) << " 34549172" << endl;
    cout << numOfArrays(37, 17, 7) << " 418930126" << endl;
    cout << numOfArrays(50, 100, 50) << " 538992043" << endl;
}