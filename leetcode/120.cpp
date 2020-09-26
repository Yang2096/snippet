#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    static int minimumTotal(vector<vector<int>>& triangle) {
        for(size_t row = 1 ; row < triangle.size(); ++row)
        {
            auto & row_data = triangle[row];
            for(size_t col = 0; col < row_data.size(); ++col)
            {
                if(col == 0)
                {
                    row_data[col] += triangle[row-1][0];
                } 
                else if(col == row_data.size()-1)
                {
                    row_data[col] += triangle[row-1][col-1];
                }
                else
                {
                    row_data[col] += triangle[row-1][col-1] < triangle[row-1][col] ? triangle[row-1][col-1] : triangle[row-1][col];
                }
            }
        }
        int min_path = triangle[triangle.size() - 1][0];
        for(auto & last_row_data : triangle[triangle.size() - 1])
        {
            min_path = last_row_data < min_path ? last_row_data : min_path;
        }
        return min_path;
    }
};

int main()
{
    vector<vector<int> > t = {{-1},{2,3},{1,-1,-3}};
    std::cout << Solution::minimumTotal(t) << '\n';
}