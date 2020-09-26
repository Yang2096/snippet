#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
inline int max(int a,int b){
    return a>b?a:b;
}
#define INT_MIN     (-2147483647 - 1) 

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    if(n == 0 || n == 1) return 0;
    long s0 = 0, s1 = -prices[0], temp;
    for(int i = 1; i < n; ++i)
    {
        temp = s0;
        s0 = max(s0, s1 + prices[i] - fee);
        s1 = max(s1, temp - prices[i]);
    }
    return s0;
}

int main()
{
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    cout << maxProfit(prices, fee) << endl;
}

static const auto io_sync_off = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 2;
}();