#include "pch.h"

inline vector<vector<long long>> matrix_multiply(vector<vector<long long>> a, vector<vector<long long>> b)
{
    vector<vector<long long>> ans = {{0, 0}, {0, 0}};
    ans[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % 1000000007;
    ans[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % 1000000007;
    ans[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % 1000000007;
    ans[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % 1000000007;
    return ans;
}

int numWays(int n)
{
    if (n <= 1)
        return n;

    vector<vector<long long>> mat = {{0, 1}, {1, 1}};
    vector<vector<long long>> temp = {{1, 0}, {0, 1}};
    while (n > 0)
    {
        if (n & 1)
        {
            temp = matrix_multiply(temp, mat);
        }
        mat = matrix_multiply(mat, mat);
        n >>= 1;
    }
    return temp[1][1];
}

int main()
{
    cout << numWays(7) << " 21" << endl;
}