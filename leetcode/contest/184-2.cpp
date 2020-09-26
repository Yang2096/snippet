#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

int line[1005];

vector<int> processQueries(vector<int>& queries, int m) {
    for(int i = 1; i <= m; ++i)
    {
        line[i-1] = i;
    }

    vector<int> ans;
    ans.reserve(queries.size());
    for(int q : queries)
    {
        if(line[0] == q)
        {
            ans.push_back(0);
            continue;
        }
        int index = 1, temp = line[0];
        while(line[index] != q)
        {
            swap(temp, line[index]);
            index++;
        }
        line[0] = line[index];
        line[index] = temp;
        ans.push_back(index);
    }
    return ans;
}

int main()
{
    vector<int> queries = {7,5,5,8,3};
    int m = 8;
    for(int a : processQueries(queries, m))
    {
        cout << a << ' ';
    }
    cout << endl;
}