#include<iostream>
#include <stack>
#include <vector>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    s.push(-1);
    int size = heights.size();
    int top, ans = 0;
    for (int i = 0; i < size; ++i) {
        while(s.top() != -1 && heights[s.top()] > heights[i])
        {
            top = s.top();
            s.pop();
            ans = max(ans, (i - s.top() - 1) * heights[top]);
            // heights[top]:当前处理的矩形的高度   s.top():左边界   i:右边界
        }
        s.push(i);
    }
    size = s.top();     // 相当于最右边有一个高度为0的矩形
    while(s.top() != -1)
    {
        top = s.top();
        s.pop();
        ans = max(ans, (size - s.top()) * heights[top]);
    }
    return ans;
}

int main()
{
    vector<int> input = {1,1,2,3,4,5};
    cout << largestRectangleArea(input) << 9 << endl;
    input = {5,4,3,2,1};
    cout << largestRectangleArea(input) << 9 << endl;
    input = {1,2,1,1,1,1};
    cout << largestRectangleArea(input) << 6 << endl;
    input = {2,1,2};
    cout << largestRectangleArea(input) << 3 << endl;
}
