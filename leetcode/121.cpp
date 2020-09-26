#include<iostream>
#include<vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int s0 = -prices[0], s1 = 0;        // s0 表示买入  s1 表示卖出
    for (int i = 1; i < prices.size(); ++i)
    {
        s0 = max(s0, -prices[i]);
        s1 = max(s1, prices[i] + s0);
    }
    return s1;
}


int main()
{
    vector<int> input = {7, 2, 5, 3, 6, 4, 1, 4, 6};
    cout << maxProfit(input) << endl;
    input = {7, 6, 5, 4, 3, 1, 2};
    cout << maxProfit(input) << endl;
}