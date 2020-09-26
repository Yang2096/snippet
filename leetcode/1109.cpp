#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    vector<int> sum(n + 1, 0);
    for(auto & booking : bookings)
    {
        sum[booking[0] - 1] += booking[2];
        sum[booking[1]] -= booking[2];
    }
    for(int i = 1; i <= n; ++i)
    {
        sum[i] += sum[i-1];
    }
    return vector<int>(sum.begin(), sum.end() - 1);
}

