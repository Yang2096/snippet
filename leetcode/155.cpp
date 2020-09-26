#include<stack>
#include<utility>
using namespace std;
class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack() {
        mi = INT32_MAX;
    }
    
    void push(int x) {
        mi = min(mi, x);
        s.emplace(mi, x);
    }
    
    void pop() {
        s.pop();      
        if(s.empty())
            mi = INT32_MAX;
        else
        {
            auto [m, x] = s.top();
            mi = m;
        }
    }
    
    int top() {
        auto [m, x] = s.top();
        return x;
    }
    
    int getMin() {
        return mi;
    }
private:
    stack<pair<int,int>> s;
    int mi;
};
