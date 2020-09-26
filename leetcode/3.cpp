#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
using namespace std;

// 可重复集合
multiset<int> s;

int maxEvents(vector<vector<int>>& events) {
    // 按开始时间升序排列, 相同开始时间的按结束时间升序排列
    sort(events.begin(),events.end());
    int n=events.size(),i,j,ans=0;
    s.clear();
    for(i=j=0;j<n||!s.empty();i++)
    {
        // 将events中开始时间与当前时间相同的会议 的 结束时间 存入set中
        for(; j<n && events[j][0]==i; j++)
            s.insert(events[j][1]);

        // 删除结束时间早于当前时间的会议
        while(!s.empty() && *s.begin()<i)
            s.erase(s.begin());

        if(!s.empty())
        {
            s.erase(s.begin());
            ans++;
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> events = {{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7},{2,4}};
    cout << maxEvents(events) << endl;
    events = {{1,4},{4,4},{2,2},{3,4},{1,1}};
    cout << maxEvents(events) << endl;
}