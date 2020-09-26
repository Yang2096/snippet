#include <vector>
#include <iostream>
using namespace std;

vector<int> pathInZigZagTree(int label) {
    vector<int> ans;
    int bit_count = label;
    int n = 0;
    while(bit_count > 0)
    {
        n++;
        bit_count >>= 1;
    }
    ans.reserve(n);
    ans.push_back(label);
    int temp = n;
    while(n > 0)
    {
        --n;
        if(n == 0)
        {
            break;
        }
        else
        {
            label = (1<<n) + (1<<(n-1)) - 1 - (label>>1);
            ans.push_back(label);
        }
    }
    
    for(int i = 0; i < temp/2; ++i)
    {
        swap(ans[i], ans[temp - i - 1]);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    auto ans = pathInZigZagTree(n);
    for(auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
