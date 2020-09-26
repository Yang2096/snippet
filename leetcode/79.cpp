#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <tuple>
using namespace std;

vector<vector<int>> step = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool exist(vector<vector<char>>& board, string word) {
    int len = word.size();
    if(len == 0) return true;
    
    int m = board.size();
    if(m == 0) return false;
    int n = board[0].size();
    if(n == 0) return false;

    vector<vector<bool>> mark(m, vector<bool>(n, true));
    int x, y, layer, xx, yy, k;
    stack<tuple<int, int, int, int>> s;

    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; ++j)
        {
            if(board[i][j] == word[0])
            {
                // dfs
                s.push(make_tuple(i, j, 0, 0));
                while(!s.empty())
                {
                    auto current = s.top();
                    x = get<0>(current);
                    y = get<1>(current);
                    layer = get<2>(current);
                    if(layer == len - 1)
                        return true;
                    k = get<3>(current);
                    mark[x][y] = false;
                    for(; k < 4; ++k)
                    {
                        xx = x + step[k][0];
                        yy = y + step[k][1];
                        if(xx >= 0 && xx < m && yy >= 0 && yy < n && mark[xx][yy])
                        {
                            if(board[xx][yy] == word[layer + 1])
                            {
                                if(layer == len - 2)
                                {
                                    return true;
                                }
                                else
                                {
                                    get<3>(s.top()) = k + 1;
                                    s.push(make_tuple(xx, yy, layer + 1, 0));
                                    break;
                                }
                            }                    
                        }
                    }
                    if(k == 4)
                    {
                        mark[x][y] = true;
                        s.pop();
                    }
                }
            }
        }
    }
    return false;
}


int main()
{
    vector<vector<char>> board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };

    cout << exist(board, "ABCCED") << endl;
    cout << exist(board, "SEE") << endl;
    cout << exist(board, "ABCB") << endl;

    board = {
        {'A'}
    };
    cout << exist(board, "A") << endl;
}