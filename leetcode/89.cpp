#include <iostream>
#include <vector>

using namespace std;

int bit2num(vector<bool> &bits, int n)
{
    int ans = 0;
    for(int i = n - 1; i >= 0; --i)
    {
        cout << bits[i] << ' ';
        if(bits[i])
            ans += (1 << i);
    }
    cout << endl;
    return ans;
}

void backtrace(vector<int> &ans, vector<bool> &bits, int layer, int n)
{
    if(layer == n)
    {
        ans.push_back(bit2num(bits, n));
        return;
    }
    
    backtrace(ans, bits, layer + 1, n);
    bits[layer] = !bits[layer];
    backtrace(ans, bits, layer + 1, n);
}

vector<int> grayCode(int n)
{
    vector<bool> bits(n, false);
    vector<int> ans;
    ans.reserve(1 << n);
    backtrace(ans, bits, 0, n);
    return ans;
}

int main()
{
    auto ans = grayCode(4);
    for(auto i : ans)
    {
        cout << i << ' ';
    }
    cout << endl;
}