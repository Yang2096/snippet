#include <vector>
#include <iostream>
using namespace std;
inline int min(int a, int b)
{
    return a < b ? a : b;
}
inline int max(int a, int b)
{
    return a < b ? b : a;
}

int minHeightShelves(vector<vector<int>>& books, int shelf_width)
{
    int n = books.size();
    if(n == 1) return books[0][1];
    int width;
    int dp[1001];
    // dp[i] 表示第i本书所需的最小高度
    dp[0] = 0;
    dp[1] = books[0][1];
    for(int i = 2; i < n + 1; ++i)
    {
        int j = i - 1;
        width = books[j][0];
        int max_height = books[j][1];
        int min_temp = books[j][1] + dp[j];
        // 从第i本书开始不断把前一本书放到新的这一层(如果能放下)
        while(j > 0 && width + books[j-1][0] <= shelf_width)
        {
            width += books[j - 1][0];   // 累计当前层的宽度
            max_height = max(max_height, books[j - 1][1]);  // 更新当前层的最高值
            min_temp = min(min_temp, max_height + dp[j - 1]);   // 前j-1本书形成的书架加当前一层之和的最小值
            --j;
        }
        dp[i] = min_temp;
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> input = {{1,7},{6,4},{10,7},{6,10},{8,10},{1,10},{10,7}};
    int width = 10;
    cout << minHeightShelves(input, width) << endl;
    return 0;
}
