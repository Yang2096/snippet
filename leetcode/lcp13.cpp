#include "pch.h"

vector<pair<int, int>> stones;
vector<pair<int, int>> machines;
vector<vector<bool>> mark;
pair<int, int> start, target;
int step[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
int n, m;
bool total_check(vector<string> &maze)
{
    queue<pair<int, int>> q;
    mark = vector<vector<bool>>(n, vector<bool>(m, true));
    q.push(start);
    mark[start.first][start.second] = false;
    int x, y, xx, yy;
    int machine_count = 0;
    bool is_target_reachable = false, is_stone_reachable = false;
    while (!q.empty())
    {
        tie(x,y) = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i)
        {
            xx = x + step[i][0];
            yy = y + step[i][1];
            if(xx < n && xx >= 0 && yy < m && yy >= 0 && maze[xx][yy] != '#' && mark[xx][yy])
            {
                mark[xx][yy] = false;
                switch(maze[xx][yy])
                {
                    case 'T':
                        is_target_reachable = true;
                        break;
                    case 'M':
                        machine_count++;
                        break;
                    case 'O':
                        is_stone_reachable = true;
                        break;
                }
                q.emplace(xx, yy);
            }
        }
    }
    return is_target_reachable && machine_count == machines.size() && (stones.size() == 0 || is_stone_reachable);
}

vector<int> bfs(vector<string> &maze, map<pair<int,int>,int> & stone_map, pair<int,int> machine)
{
    vector<int> distance(stone_map.size(), 1 << 28);
    queue<pair<int, int>> q;
    q.push(machine);
    for(auto & line : mark)
        for(auto cell : line)
            cell = true;
    mark[machine.first][machine.second] = false;

    int x, y, xx, yy, layer = 0;
    while (!q.empty())
    {
        layer++;
        int size = q.size();
        while(size--)
        {
            tie(x, y) = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i)
            {
                xx = x + step[i][0];
                yy = y + step[i][1];
                if (xx >= 0 && xx < n && yy >= 0 && yy < m && mark[xx][yy])
                {
                    mark[xx][yy] = false;
                    if (maze[xx][yy] == 'O' || maze[xx][yy] == 'T')
                        distance[stone_map[make_pair(xx, yy)]] = layer;
                
                    if(maze[xx][yy] != '#')
                        q.emplace(xx, yy);
                }
            }
        }
    }
    return distance;
}

int minimalSteps(vector<string> &maze)
{
    n = maze.size();
    m = maze[0].length();
    stones.clear();
    machines.clear();
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            switch (maze[i][j])
            {
            case 'S':
                start = make_pair(i, j);
                break;
            case 'T':
                target = make_pair(i, j);
                break;
            case 'O':
                stones.emplace_back(i, j);
                break;
            case 'M':
                machines.emplace_back(i, j);
                break;
            default:
                break;
            }
        }
    }
    if(!total_check(maze))
        return -1;

    // target -> first stone
    map<pair<int, int>, int> stone_map;
    stone_map[target] = 0;
    for (int i = 0; i < stones.size(); ++i)
        stone_map[stones[i]] = i + 1;

    // start -> first machine
    int m_num = machines.size();
    vector<vector<int>> distances(m_num + 1); // between stone and machine

    distances[0] = bfs(maze, stone_map, start);
    if(m_num == 0)
        return distances[0][0];
    for (int i = 1; i <= m_num; ++i)
        distances[i] = bfs(maze, stone_map, machines[i - 1]);
    
    vector<vector<int>> dis(m_num + 1, vector<int>(m_num + 1, -1));
    for(int i = 0; i < m_num; ++i)
    {
        for(int j = i + 1; j <= m_num; ++j)
        {
            int _min = INT32_MAX;
            for(int k = 1; k <= stones.size(); ++k)
            {
                _min = min(_min, distances[i][k] + distances[j][k]);
            }
            dis[i][j] = dis[j][i] = _min;
        }
    }

    vector<vector<int>> dp(1 << m_num, vector<int>(16, -1));
    for(int i = 0; i < m_num; ++i)
        dp[1 << i][i] = dis[0][i+1];
    for(int mask = 1; mask < (1 << m_num); ++mask)
    {
        for(int i = 0; i < m_num; ++i)
        {
            if((mask & (1 << i)))
            {
                for(int j = 0; j < m_num; ++j)
                {
                    if(!(mask & (1 << j)))
                    {
                        int next = mask | (1 << j);
                        if(dp[next][j] == -1 || dp[next][j] > dp[mask][i] + dis[i+1][j+1])
                            dp[next][j] = dp[mask][i] + dis[i+1][j+1];
                    }
                }
            }
        }
    }

    int ret = -1;
    int last = (1 << m_num) - 1;
    for(int i = 0; i < m_num; ++i)
        if(ret == -1 || ret > dp[last][i] + distances[i+1][0])
            ret = dp[last][i] + distances[i+1][0];
    return ret;
}

int main()
{
    vector<string> maze = {"S#O", "M..", "M.T"};
    cout << minimalSteps(maze) << " 16" << endl;
    maze = {"S#O", "M.T", "M.."};
    cout << minimalSteps(maze) << " 17" << endl;
    maze = { "...#...", 
             ".......", 
             "...S...", 
             ".......", 
             "..T.#..", 
             "#..#.#.", 
             "...#..." };
    cout << minimalSteps(maze) << " 3" << endl;
    maze = {"T#O", 
            ".##", 
            "O..", 
            ".#.", 
            "OSM", 
            "#.." };
    cout << minimalSteps(maze) << " 9" << endl;
}