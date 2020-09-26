#include<iostream>
#include<vector>
using namespace std;

int candy(vector<int> &ratings)
{
    int n = ratings.size() - 1;
    int ans = 1;
    int down_step = 1;
    int up_step = 1;
    for (int i = 1; i <= n; ++i)
    {
        ++ans;
        if(ratings[i] < ratings[i-1])
        {
            if(up_step == 1)
                ans += down_step++;
            up_step = 1;
        }else if(ratings[i] > ratings[i-1])
        {
            down_step = 1;
            ans += up_step++;
        }else
        {
            up_step = 1;
            down_step = 1;
        }
    }
    return ans;
}

int candy1(vector<int> & ratings)
{
    int n = ratings.size();
    vector<int> mark(n, 0);
    int step = 1;
    for (int i = 1; i < n; ++i)
    {
        if(ratings[i] > ratings[i-1])
            mark[i] = step++;
        else
        {
            step = 1;
        }
    }
    step = 1;
    int ans = n + mark[n-1];
    for (int i = n - 2; i >= 0; --i)
    {
        if(ratings[i] > ratings[i + 1])
        {
            ans += max(mark[i], step++);
        }
        else
        {
            ans += mark[i];
            step = 1;
        }
    }
    return ans;
}


int main(int argc, char* argv[])
{
    vector<int> ratings = {1, 1, 3, 3, 2, 2, 1, 1};
    cout << candy1(ratings) << " 11" << endl;
    ratings = {8, 3, 2, 2, 1, 1};
    cout << candy1(ratings) << " 10" << endl;
    ratings = {1, 3, 2, 2, 1};
    cout << candy1(ratings) << " 7" << endl;
    ratings = {1, 6, 10, 8, 7, 3, 2};
    cout << candy1(ratings) << " 18" << endl;
}