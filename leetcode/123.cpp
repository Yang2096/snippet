#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
inline int max(int a,int b){
    return a>b?a:b;
}
#define INT_MIN     (-2147483647 - 1) 
int maxProfit_v1(vector<int>& prices) {
    auto dp = new int[prices.size()][3][2];
    // init state
    for(int i=0;i<prices.size();++i)
    {
        dp[i][0][0] = 0;    // 所有最多买0次的状态未持有股票其值定为0
        dp[i][0][1] = -100000;  // 而最多买零次时不能买
    }
    for(int i=0;i<3;++i)
    {
        dp[0][i][0] = 0;    // 第一天的时候未持有股票其值定为0
        dp[0][i][1] = -prices[0];  // 第一天如果持有,肯定是买了
    }

    for(int i=1;i<prices.size();++i)
    {
        // 当前持有股票 = max(昨天就持有, 昨天没有今天买入)
        dp[i][1][1] = max(dp[i-1][1][1], dp[i-1][0][0] - prices[i]);
        // 当前没有股票 = max(昨天就没有, 昨天有今天卖出)
        dp[i][1][0] = max(dp[i-1][1][0], dp[i-1][1][1] + prices[i]);
        dp[i][2][1] = max(dp[i-1][2][1], dp[i-1][1][0] - prices[i]);
        dp[i][2][0] = max(dp[i-1][2][0], dp[i-1][2][1] + prices[i]);
    }
    // final state
    int ans = dp[prices.size()-1][2][0];
    delete dp;
    return ans;
}

int maxProfit(vector<int>& prices) {
    // 第一天
    if(prices.size() == 0) return 0;
    int s10 = 0, s11 = -prices[0], s20 = 0, s21 = -prices[0];
    for(int i=1;i<prices.size();++i)
    {
        s20 = max(s20, s21 + prices[i]);
        s21 = max(s21, s10 - prices[i]);
        s10 = max(s10, s11 + prices[i]);
        s11 = max(s11, -prices[i]);
    }
    return s20;
}
int main()
{
    vector<int> prices = {};
    //cout << maxProfit_v1(prices) << endl;
    cout << maxProfit(prices) << endl;
}