#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
inline int max(int a,int b){
    return a>b?a:b;
}
#define INT_MIN     (-2147483647 - 1) 

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if(n == 0 || n == 1) return 0;
    // 总喜欢先算出初始的状态
    int d20 = 0, d21 = -prices[0];
    int d10 = max(0, prices[1] - prices[0]), d11 =max(-prices[0], -prices[1]);
    int t0, t1;
    for(int i = 2; i < n; ++i)
    {
        t0 = d10; t1 = d11;
        d10 = max(t0, t1 + prices[i]);
        d11 = max(t1, d20 - prices[i]);
        d20 = t0;
        d21 = t1;
    }

    return d10;
}

int main()
{
    vector<int> prices = {1,2,3,0,2};
    cout << maxProfit(prices) << endl;
}