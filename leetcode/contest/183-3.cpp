#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;

int pick(vector<pair<int, char>> & data, char last)
{
    int max = (last - 'a' + 1) % 3;
    if(data[max].first > data[(max + 1) % 3].first)
        return max;
    else
        return (max + 1) % 3;
}

string longestDiverseString(int a, int b, int c) {
    vector<pair<int, char>> data;
    data.push_back(make_pair(a, 'a'));
    data.push_back(make_pair(b, 'b'));
    data.push_back(make_pair(c, 'c'));
    sort(data.begin(), data.end(), [](const pair<int, char> & a, const pair<int, char> & b)->bool{
        return a.first > b.first;
    });
    string ans;
    int hole = (data[0].first + 1) / 2;
    int s1 = data[1].first;
    int s2 = s1 + data[2].first;

    for(int i = 0; i <= hole; ++i)
    {
        if(data[0].first > 1)
        {
            ans += string(2, data[0].second);
            data[0].first -= 2;
        } 
        else if(data[0].first == 1)
        {
            ans += data[0].second;
            data[0].first -= 1;
        }
        if(data[1].first == 0 && data[2].first == 0)
            break;
        int j = i;
        while(j < s2)
        {
            if(j < s1 && data[1].first > 0)
            {
                ans += data[1].second;
                data[1].first--;
            } 
            else if(j >= s1 && data[2].first > 0)
            {
                ans += data[2].second;
                data[2].first--;
            }
            j += hole;
        }
    }
    
    return ans;    
}

int main()
{
    cout << longestDiverseString(0,8,11) << endl;
    cout << longestDiverseString(2,2,1) << endl;
    cout << longestDiverseString(7,1,0) << endl;
    cout << longestDiverseString(1,1,7) << endl;
    cout << longestDiverseString(7,7,7) << endl;
}