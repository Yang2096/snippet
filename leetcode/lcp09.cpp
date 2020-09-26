#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int minJump(vector<int> &jump)
{
    int n = jump.size();
    queue<pair<int,int>> q;
    vector<bool> vis(n, true);
    q.emplace(0,0);
    int pos = 0, next;
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        next = p.first + jump[p.first];
        if(next >= n)
        {
            return p.second + 1;
        }
        else
        {
            if(vis[next])
            {
                q.emplace(next, p.second + 1);
                vis[next] = false;
            }
            for (int i = p.first - 1; i > pos; --i)
            {
                if(vis[i])
                {
                    q.emplace(i, p.second + 1);
                    vis[i] = false;
                }
            }
            pos = max(pos, p.first);
        }
    }
    return 1;
}

int main()
{
    vector<int> jump = {2, 5, 1, 1, 1, 1};
    cout << (minJump(jump) == 3) << endl;
    jump = {3, 5, 4, 1, 1, 1};
    cout << (minJump(jump) == 3) << endl;
    jump = {2, 2, 1, 2, 1, 2, 1};
    cout << (minJump(jump) == 4) << endl;
    jump = {1};
    cout << (minJump(jump) == 1) << endl;
    jump = {4, 6, 10, 8, 3, 5, 3, 5, 7, 8, 6, 10, 3, 7, 3, 10, 7, 10, 10, 9, 1, 4, 7, 4, 8, 6, 9, 8, 8, 2, 7, 2, 4, 5, 4, 3, 3, 2, 2, 2, 3, 4, 4, 1, 1, 5, 6, 8, 1, 2};
    cout << (minJump(jump) == 11) << endl;
}