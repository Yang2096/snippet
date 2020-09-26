#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> result;
    if(intervals.size() == 0) return result;
    if(intervals.size() == 1) return intervals;
    sort(intervals.begin(), intervals.end(), [](const vector<int> & a, const vector<int> & b){
        return a[0] < b[0];
    });
    int head = intervals[0][0];
    int tail = intervals[0][1];
    for(const auto & interval : intervals)
    {
        if(interval[0] <= tail)
            tail = max(interval[1], tail);
        else
        {
            result.push_back({head, tail});
            head = interval[0];
            tail = interval[1];
        }
    }
    if(result.size() == 0 || tail > result.back()[1])
        result.push_back({head, tail});
    return result;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> intervals = {{1,100},{15,18},{8,10},{2,6}, {17, 24}};
    auto result = merge(intervals);
    for(const auto &interval : result)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
}