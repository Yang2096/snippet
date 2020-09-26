#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<string.h>
using namespace std;

int step[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool mark[120][120];

int trapRainWater(vector<vector<int>> & heightMap)
{
    int n = heightMap.size();
    int m = heightMap[0].size();
    if(n <= 2 && m <= 2)
        return 0;
    int ans;

    return ans;
}

int main()
{
    vector<vector<int>> heightMap = {
        {1, 4, 3, 1, 3, 2},
        {3, 2, 1, 3, 2, 4},
        {2, 3, 3, 2, 3, 1}};

    cout << trapRainWater(heightMap) << endl;

    stack<int> s;
}