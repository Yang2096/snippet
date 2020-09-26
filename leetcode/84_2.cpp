#include <vector>
#include <stack>
#include <iostream>
using namespace std;

inline int max(int a, int b)
{
    return a < b ? b : a;
}
template<typename T>
inline T min(T a, T b)
{
    return b < a ? b : a;
}

int largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int ans = 0;
    s.push(-1);
    for(int i = 0; i < heights.size(); ++i)
    {
        while(-1 != s.top() && heights[s.top()] > heights[i])
        {
            int stack_top = s.top();
            s.pop();
            int temp_area = (i - s.top() - 1) * heights[stack_top];
            ans = max(ans, temp_area);
        }
        s.push(i);
    } 
    int right_bound = s.top();
    while(-1 != s.top())
    {
        int stack_top = s.top();
        s.pop();
        ans = max(ans, (right_bound - s.top()) * heights[stack_top]);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> heights = {2,1,5,6,2,3};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}
