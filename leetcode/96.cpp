#include<iostream>
#include<vector>

using namespace std;

int count(int left, int right)
{
    if(left < right)
    {
        int ans = 0;
        for(int i = left ; i <= right; ++i)
        {
            int l = count(left, i - 1);
            int r = count(i + 1, right);
            ans += (l * r);
        }
        return ans;
    }
    else
    {
        return 1;
    }
}

int numTrees1(int n) {
    if(n == 0) 
        return 0;
    return count(1, n);
}

int numTrees(int n)
{
    if(n == 0) return 0;
    int ans[n+1] = {0};
    ans[0] = 1;
    ans[1] = 1;

    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= i; ++j)
        {
            ans[i] += ans[j - 1] * ans[i - j];
        }
    }
    return ans[n];
}

int main()
{
    cout << numTrees(3) << ' ' << 5 << endl;
    cout << numTrees(4) << ' ' << 14 << endl;
}