#include<iostream>
#include <vector>
#include <tuple>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
    int m = matrix.size();
    if(m == 0) return 0;
    int n = matrix[0].size();
    vector<tuple<int, int, int>> line(n, make_tuple(0,0,0)); // height left right
    int ans = 0;
    for(int i = 0; i < m; ++i)
    {
        int left = 0;
        for(int j = 0; j < n; ++j)
        {
            if(matrix[i][j] == '1')
            {
                ++left;
                get<0>(line[j]) += 1;
                if(get<0>(line[j]) == 1)
                    get<1>(line[j]) = left;
                else
                    get<1>(line[j]) = min(get<1>(line[j]), left);
            }
            else
            {
                left = 0;
                get<0>(line[j]) = 0;
                get<1>(line[j]) = 0;
            }
        }

        int right = 0;
        for(int j = n - 1; j >= 0; --j)
        {
            if(matrix[i][j] == '1')
            {
                ++right;
                if(get<0>(line[j]) == 1)
                    get<2>(line[j]) = right;
                else
                    get<2>(line[j]) = min(get<2>(line[j]), right);
                ans = max(ans, get<0>(line[j]) * (get<1>(line[j]) + get<2>(line[j]) - 1));
            }
            else
            {
                right = 0;
                get<2>(line[j]) = 0;
            }
        }
        //for(auto& a : line)
        //{
        //    cout << '(' << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a) << ") ";
        //}
        //cout << endl;
    }
    return ans;
}


int main() {
    vector<vector<char>> matrix = {
            {'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
    };

    cout << maximalRectangle(matrix) << endl;
}