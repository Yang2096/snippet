#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    int head = newInterval[0];
    int tail = newInterval[1];
    int i = 0;
    for(; i < intervals.size(); ++i)
    {
        auto & interval = intervals[i];
        if(interval[1] < head)
        {
            result.push_back(interval);
        }
        else if(interval[0] > tail)
        {
            break;
        }
        else 
        {
            tail = max(interval[1], tail);
            head = min(interval[0], head);
        }
    }
    result.push_back({head, tail});
    for(; i < intervals.size(); ++i)
    {
        result.push_back(intervals[i]);
    }
    return result;
}

int main(int argc, char *argv[])
{
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{13,16}};
    vector<int> newInterval = {14,15};
    auto result = insert(intervals,newInterval);
    for(const auto &interval : result)
    {
        cout << interval[0] << " " << interval[1] << endl;
    }
}