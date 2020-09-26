#include "pch.h"

vector<vector<int>> step = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int n,m;
bool search(vector<vector<char>> &board, vector<vector<bool>> & visited, int x, int y, int layer, string & word)
{
    if(layer == word.length() - 1)
        return true;
    visited[x][y] = true;
    int xx, yy;
    for(int i = 0; i < 4; ++i)
    {
        xx = x + step[i][0];
        yy = y + step[i][1];
        if(xx >= 0 && xx < n && yy >= 0 && yy < m && !visited[xx][yy])
        {
            if(board[xx][yy] == word[layer+1])
            {
                if (search(board, visited, xx, yy, layer + 1, word))
                    return true;
            }
        }
    }
    visited[x][y] = false;
    return false;
}

bool exist(vector<vector<char>> &board, string word)
{
    n = board.size();
    m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (board[i][j] == word[0])
            {
                if(search(board, visited, i, j, 0, word))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    vector<vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    cout << exist(board, "ABCCED") <<  " 1" << endl;
    board = { {'A', 'B', 'C', 'E'},
              {'S', 'F', 'E', 'S'},
              {'A', 'D', 'E', 'E'} };
    cout << exist(board, "ABCESEEEFS") << " 1" << endl;
    board = {{'a'}};
    cout << exist(board, "a") << " 1" << endl;
}