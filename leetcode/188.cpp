#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
inline int max(int a,int b){
    return a>b?a:b;
}
#define INT_MIN     (-2147483647 - 1) 

int maxProfit(int k, vector<int>& prices) {
    int n = prices.size();
    if(n == 0 || k == 0) return 0;
    if(n/2 <= k)
    {
        int s0 = 0, s1 = -prices[0]; 
        for(int i=1;i<n;++i)
        {
            int temp = s0;
            s0 = max(s0, s1 + prices[i]);
            s1 = max(s1, temp - prices[i]);
        }
        return s0;
    }
    else
    {
        auto dp = new int [k+1][2];
        for(int j=0;j<=k;++j)
        {
            dp[j][0] = 0;
            dp[j][1] = -prices[0];  
        }

        for(int i=1;i<n;++i)
        {
            for(int j=k;j>=1;--j)
            {
                dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
                dp[j][1] = max(dp[j][1], dp[j-1][0] - prices[i]);
            }
        }

        int ans = dp[k][0];
        delete dp;
        return ans;
    }
}

int main()
{
    vector<int> prices = {1,2};
    cout << maxProfit(1, prices) << endl;
}

