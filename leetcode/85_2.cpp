#include <vector>
#include <iostream>
using namespace std;

inline int max(int a, int b)
{
    return a < b ? b : a;
}

inline int min(int a, int b)
{
    return b < a ? b : a;
}

int maximalRectangle(vector<vector<char>>& matrix) {
    int ans = 0;
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> height(m, 0), left(m, m), right(m, m);
    
    for(int i = 0; i < n; ++i)
    {
        int current_left = 0;
        for(int j = 0; j < m; ++j)
        {
            if(matrix[i][j] == '1')
            {
                height[j] = height[j] + 1;
                ++current_left;
                left[j] = height[j] == 1 ? current_left : min(left[j], current_left);
            }
            else
            {
                height[j] = 0;
                left[j] = 0;
                current_left = 0;
            }
        }

        int current_right = 0;
        for(int j = m - 1; j >= 0; --j)
        {
            if(matrix[i][j] == '1')
            {
                ++current_right;
                right[j] = height[j] == 1 ? current_right : min(right[j], current_right);
                ans = max(ans, (right[j] + left[j] - 1) * height[j]);
            }
            else
            {
                right[j] = 0;
                current_right = 0;
            }
        }
    }
    return ans;
}
/*
        for(int j = 0; j < m; ++j)
        {
            cout<< height[j] << ',' << left[j] << ',' << right[j] << ' ';
        }
        cout << endl;
 */

int main(int argc, char const *argv[])
{
    vector<vector<char>> matrix = {
            {'1','0','1','1','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','1','1','1'}};
    cout << maximalRectangle(matrix) << endl;
    return 0;
}
