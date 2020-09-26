#include <iostream>
#include <vector>
#include <unordered_set>
#include <string.h>
using namespace std;

bool not_in(unordered_set<char>& c, char ch)
{
    return c.find(ch) == c.end();
}
void print_board(vector<vector<char>> & board)
{
    for(auto & line : board)
    {
        for(auto e : line)
        {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool row[9][9];
bool col[9][9];
bool box[9][9];
void solveSudoku(vector<vector<char>>& board) {
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(row));
    memset(box, 0, sizeof(row));
    int ch;
    for(int i = 0; i<9; ++i)
    {
        for(int j = 0; j < 9; ++j)
        {
            ch = board[i][j] - '1';
            if(board[i][j] != '.')
            {
                row[i][ch] = true;
                col[j][ch] = true;
                box[(i/3)*3 + j/3][ch] = true;
            }
        }
    }
    const auto const_ch(board);
    int i = 0, r, c;
    while(i < 81)
    {
        r = i / 9;
        c = i % 9;
        if(const_ch[r][c] != '.') 
        {
            ++i; continue;
        }

        ch = 0;
        if(board[r][c] != '.')
        {
            ch = board[r][c] - '1';
            row[r][ch] = false;
            col[c][ch] = false;
            box[(r/3)*3 + c/3][ch] = false;
            board[r][c] = '.';
            ++ch;
        }
        for(; ch < 9; ++ch)
        {
            if(!row[r][ch] && !col[c][ch] && !box[(r/3)*3 + c/3][ch])
            {
                board[r][c] = ch + '1';
                row[r][ch] = true;
                col[c][ch] = true;
                box[r/3*3 + c/3][ch] = true;
                ++i;
                break;
            }
        }
        if(ch >= 9)
        {
            --i;
            while(const_ch[i/9][i%9] != '.')
                --i;
            //print_board(board);
        }
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};
    solveSudoku(board);
    print_board(board);
    return 0;
}
