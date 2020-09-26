#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    static int maxProfit(vector<int>& prices) {
        if(prices.empty())
            return 0;
        int mini = prices[0], result = 0, single_deal = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            single_deal = max(prices[i] - mini, single_deal);
            mini = min(prices[i], mini);
            if(prices[i] < prices[i - 1]){
                result += single_deal;
                mini = prices[i];
                single_deal = 0;
            }
        }
        if(result == 0)
            return single_deal;
        else
            return result + single_deal;
    }
};

int main()
{
    vector<int> a = {7,1,5,3,6,4};
    cout << Solution::maxProfit(a);
}