#include "pch.h"

inline vector<vector<long long>> matrix_multiply(vector<vector<long long>> a, vector<vector<long long>> b)
{
    vector<vector<long long>> ans = {{0,0},{0,0}};
    ans[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % 1000000007;
    ans[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % 1000000007;
    ans[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % 1000000007;
    ans[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % 1000000007;
    return ans;
}

int fib(int n)
{
    if(n == 0)
        return 0;
    if (n <= 2)
        return 1;
    n--;
    vector<vector<long long>> mat = {{0, 1}, {1, 1}};
    vector<vector<long long>> temp = {{1, 0}, {0, 1}};
    while (n > 0)
    {
        if(n & 1)
        {
            temp = matrix_multiply(temp, mat);
        }
        mat = matrix_multiply(mat, mat);
        n >>= 1;
    }
    return temp[1][1];
}

int fib_(int n)
{
    vector<int> f = {1, 1};
    int a, b;
    for (int i = 3; i <= n; ++i)
    {
        a = f[1];
        b = (f[0] + a) % 1000000007;
        f[0] = a;
        f[1] = b;
    }
    return f[1];
}

int main()
{
    cout << fib(3) << ' ' << fib_(3) << endl;
    cout << fib(5) << ' ' << fib_(5) << endl;
    cout << fib(8) << ' ' << fib_(8) << endl;
    cout << fib(1000) << ' ' << fib_(1000) << endl;
    cout << fib(100000) << ' ' << fib_(100000) << endl;
}