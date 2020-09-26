#include<iostream>
#include<vector>
#include<utility>
#include<unordered_map>
using namespace std;

int gcd(int a, int b)
{
    if(a % b)
        return gcd(b, a % b);
    else
        return b;
}

namespace std{
template <typename T1, typename T2>
    struct hash<std::pair<T1, T2>>
    {
        size_t operator()(pair<T1, T2> const &a) const
        {
            auto h1 = std::hash<T1>{}(a.first);
            auto h2 = std::hash<T2>{}(a.second);
            return (h1 << 1) ^ h2;
        }
    };
}

int maxPoints(vector<vector<int>> &points)
{
    if(points.size() < 3)
        return points.size();

    unordered_map<pair<int, int>, int> map;

    int ans = 2;
    int n = points.size();
    int xi, yi, xj, yj, d, same, line;
    auto check = map.end();
    for (int i = 0; i < n - 1; ++i)
    {
        xi = points[i][0];
        yi = points[i][1];
        same = 0;
        line = 0;
        map.clear();
        for (int j = i + 1; j < n; ++j)
        {
            xj = points[j][0] - xi;
            yj = points[j][1] - yi;
            if (xj != 0 && yj != 0)
            {
                d = gcd(xj, yj);
                xj /= d;
                yj /= d;
            }
            else if (xj == 0 && yj == 0)
            {
                ++same;
                continue;
            }
            else if(xj == 0)
                yj = 1;
            else if(yj == 0)
                xj = 1;
            check = map.find(make_pair(xj, yj));
            if (check != map.end())
            {
                line = max(line, ++(check->second));
            }
            else
            {
                map[make_pair(xj, yj)] = 1;
                line = max(line, 1);
            }
        }
        ans = max(ans, line + same + 1);
    }
    return ans;
}

int main()
{
    vector<vector<int>> points = {{1, 1}, {3, 2}, {5, 3}, {4, 1}, {2, 3}, {1, 4}};
    cout << maxPoints(points) << endl;
    points = {{1, 1}, {2, 2}, {3, 3}};
    cout << maxPoints(points) << endl;
    points = {{0, 0}, {1, 1}, {0, 0}};
    cout << maxPoints(points) << endl;
}