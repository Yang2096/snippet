#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    if(prices.size() == 0)
        return 0;
    int s10 = -prices[0], s11 = 0, s20 = -prices[0], s21 = 0;
    for (int i = 1; i < prices.size(); ++i)
    {
        s10 = max(s10, -prices[i]);
        s11 = max(s11, s10 + prices[i]);
        s20 = max(s20, s11 - prices[i]);
        s21 = max(s21, s20 + prices[i]);
    }
    return s21;
}


int main()
{
    vector<int> input = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << maxProfit(input) << " 6" << endl;
    input = {1, 2, 3, 4, 5};
    cout << maxProfit(input) << " 4" << endl;
    input = {7, 6, 4, 3, 1};
    cout << maxProfit(input) << " 0" << endl;
    input = {1, 5, 4, 3};
    cout << maxProfit(input) << " 4" << endl;
}