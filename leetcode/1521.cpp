#include "pch.h"
int closestToTarget(vector<int> &arr, int target)
{
    int n = arr.size();
    vector<int> count(25, 0);
    vector<int> jump(n, n);
    for (int j = 0; j < 25; ++j)
    {
        if (arr[n - 1] & (1 << j))
        {
            count[j] = 1;
            jump[n - 1] = 1;
        }
        else
            count[j] = 0;
    }
    for (int i = n - 2; i >= 0; --i)
    {
        for (int j = 0; j < 25; ++j)
        {
            if (arr[i] & (1 << j))
            {
                count[j]++;
                jump[i] = min(jump[i], count[j]);
            }
            else
                count[j] = 0;
        }
        cout << jump[i] << ' ';
    }
    cout << endl;

    int ans = INT32_MAX;
    for (int i = 0; i < n; ++i)
    {
        int temp = arr[i], index = i;
        while (index < n)
        {
            temp &= arr[index];
            ans = min(ans, abs(temp - target));
            if (temp < target)
                break;
            index += jump[index];
        }
        if (ans == 0)
            return 0;
    }
    return ans;
}

int main()
{
    vector<int> arr = {9, 12, 3, 7, 15};
    cout << closestToTarget(arr, 5) << " 2" << endl;
    arr = {10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102, 10102};
    cout << closestToTarget(arr, 22) << " " << 10102 - 22 << endl;
}