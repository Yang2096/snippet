#include<iostream>
#include<vector>
using namespace std;

int binary(vector<vector<int>>& increase, int k, int requirement)
{
    int left = 0, right = increase.size() - 1, mid, value;
    while(left <= right)
    {
        mid = (left + right) / 2;
        value = increase[mid][k];
        cout << mid << ',' << requirement << ' ';
        if(value > requirement)
        {
            right = mid - 1;
            if((right >= 0 && increase[right][k] < requirement) || (right == -1))
                return mid;
        }
        else if(value < requirement)
        {
            left = mid + 1;
        }
        else
        {
            int i = mid;
            while(i >= 1 && increase[i-1][k] == requirement)
                i--;
            return i;
        }
    }
    return increase.size();
}

vector<int> getTriggerTime(vector<vector<int>>& increase, vector<vector<int>>& requirements) {
    for(int i = 1; i < increase.size(); ++i)
    {
        for(int j = 0; j < 3; ++j)
        {
            increase[i][j] += increase[i-1][j];
        }
    }
    vector<int> ans;
    ans.reserve(requirements.size());
    int temp = 0;
    for(int i = 0; i < requirements.size(); ++i)
    {
        temp = 0;
        if (requirements[i][0] == 0 && requirements[i][1] == 0 && requirements[i][2] == 0)
        {
            ans.push_back(0);
            continue;
        }
        for (int j = 0; j < 3; ++j)
        {
            int a = binary(increase, j, requirements[i][j]);
            cout << a << ' ';
                temp = max(temp, a);
        }
        cout << endl << temp << endl;
        if(temp == increase.size())
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(temp + 1);
        }
    }
    return ans;
}

int main()
{
    vector<vector<int>> increase = { {2, 8, 4},
                                     {2, 5, 0},
                                     {10, 9, 8} };
    vector<vector<int>> requirements = { {2, 11, 3},
                                         {15, 10, 7},
                                         {9, 17, 12},
                                         {8, 1, 14} };
    for(int a : getTriggerTime(increase, requirements))
    {
        cout << a << ' ';
    }
    cout << endl;
}