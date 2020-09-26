#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> nums;

int getK(int k)
{
    for (int i = 1; i < 10; ++i)
    {
        if(nums[i] == 0)
            --k;
        if(k == 0)
            return i;
    }
    return 0;
}

string getPermutation(int n, int k) {
    vector<int> perm = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    nums = vector<int>(10, 0);
    vector<char> ans(n, '0');

    int n_ = n;

    int temp, j;
    for(int i = 0; i < n_; ++i, --n)
    {
        if(k == 0) break;
        j = k / perm[n - 1];
        if(j == 0)
        {
            temp = getK(1);
        }
        else
        {
            k -= perm[n - 1] * j;
            if(k > 0)
                temp = getK(j+1);
            else
            {
                temp = getK(j);
            }
            
        }
        if(temp == 0)
            return string(ans.begin(), ans.end());
        ans[i] = temp + '0';
        nums[temp] = 1;
    }
    if(k == 0)
    {
        for(int i = n_ - 1; i >= n_ - n; --i)
        {
            temp = getK(1);
            ans[i] = temp + '0';
            nums[temp] = 1;
        }
    }
    return string(ans.begin(), ans.end());
}


int main() 
{
    for(int i = 1; i <= 6; ++i)
    {
        auto ans = getPermutation(3, i);
        for(char i : ans)
        {
            cout << i;
        }
        cout << endl;
    }
    auto ans = getPermutation(3, 3);
    for(char i : ans)
    {
        cout << i;
    }
    cout << ' ' << "213" <<  endl;
    ans = getPermutation(3, 1);
    for(char i : ans)
    {
        cout << i;
    }
    cout << ' ' << "123" << endl;
    ans = getPermutation(3, 6);
    for(char i : ans)
    {
        cout << i;
    }
    cout << ' ' << "321" << endl;
    ans = getPermutation(3, 4);
    for(char i : ans)
    {
        cout << i;
    }
    cout << ' ' << "231" << endl;
    ans = getPermutation(9, 362880);
    for(char i : ans)
    {
        cout << i;
    }
    cout << ' ' << "987654321" << endl;
}