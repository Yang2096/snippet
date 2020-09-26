#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    if(k == 0) return ans;
    vector<int> line;
    line.reserve(k);
    vector<int> mark(n, 1);
    int last = 0;
    while(true)
    {
        for(int i = last; i < n && n - i >= k - line.size(); ++i)
        {
            if(mark[i])
            {
                line.push_back(i + 1);
                mark[i] = 0;
                if(line.size() == k)
                {
                    ans.emplace_back(line);
                    line.pop_back();
                    mark[i] = 1;
                }
            }
        }
        if(line.empty())
            break;
        else
        {
            last = line.back();
            line.pop_back();
            mark[last - 1] = 1;
        }
    }
    return ans;
}


int main()
{
    auto ans = combine(4, 3);
    auto print = [](decltype(ans) ans)->void{
        for(auto& line : ans)
        {
            for(int a : line)
            {
                cout << a << ' ';
            }
            cout << endl;
        }
    };
    print(ans);
    print(combine(4,4));
    print(combine(4,2));
    print(combine(5,1));
    print(combine(1,1));
    print(combine(1,0));
    print(combine(5,4));
    print(combine(7,5));
}