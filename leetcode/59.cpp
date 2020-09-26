#include <iostream>
#include <vector>
using namespace std;

static vector<vector<int>> direction = { {1,0}, {0,1}, {-1,0}, {0,-1}};

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> result(n, vector<int>(n, 0));
    int d = 0;
    int x = 0;
    int y = 0;
    int count = 1;
    while(true)
    {
        if(result[x][y] == 0)
        {
            result[x][y] = count++;
        }
        int next_x = x + direction[d][1];
        int next_y = y + direction[d][0];
        if(next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || result[next_x][next_y] != 0)
        {
            d = (d+1)%4;
            x += direction[d][1];
            y += direction[d][0];
        }
        else
        {
            x = next_x;
            y = next_y;
        }
        if(count > n*n)
            break;
    }
    return result;
}

int main() {
    int n;
    while(cin >> n)
    {
        auto result = generateMatrix(n);
        for(const auto& row : result)
        {
            for(const auto& col : row)
            {
                cout << col << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}