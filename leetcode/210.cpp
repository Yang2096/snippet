#include "pch.h"
vector<int> findOrder(int numCourses, vector<vector<int>> prerequisites)
{
    vector<vector<bool>> mat(numCourses, vector<bool>(numCourses, false));
    vector<int> count(numCourses, 0);

    for (auto &line : prerequisites)
    {
        mat[line[1]][line[0]] = true;
        count[line[1]]++;
    }
    
    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
    {
        if (count[i] == 0)
            q.emplace(i);
    }
    vector<int> ans;
    vector<bool> visited(numCourses, false);
    while (!q.empty())
    {
        int to = q.front();
        q.pop();
        ans.push_back(to);
        visited[to] = true;
        for (int i = 0; i < numCourses; ++i)
        {
            if (!mat[i][to])
                continue;
            
            if(visited[i])
                return {};

            count[i]--;
            if (count[i] == 0)
            {
                q.push(i);
            }
        }
    }
    if (ans.size() != numCourses)
        return {};
    else
        return vector<int>{ans.rbegin(), ans.rend()};
}

int main()
{
    auto ans = findOrder(2, {{1,0}});
    for(int a : ans)
        cout << a << ' ';
    cout << endl;
    ans = findOrder(4, {{1, 0}, {2, 0}, {3, 1}, {3, 2}});
    for (int a : ans)
        cout << a << ' ';
    cout << endl;
}