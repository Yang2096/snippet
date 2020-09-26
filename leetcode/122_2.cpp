#include <iostream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices) {
    if(prices.size() == 0)
        return 0;
    int s0 = -prices[0], s1 = 0, temp;
    for (int i = 1; i < prices.size(); ++i)
    {
        temp = s0;
        s0 = max(s0, s1 - prices[i]);
        s1 = max(s1, prices[i] + temp);
        cout << s0 << ' ' << s1 << endl;
    }
    return s1;
}

int main()
{
    vector<int> prices = {1,2,3,4,5};
    cout << maxProfit(prices) << endl;
    prices = {7, 1, 5, 3, 6, 4};
    cout << maxProfit(prices) << endl;
    prices = {7, 6, 4, 3, 1};
    cout << maxProfit(prices) << endl;
}