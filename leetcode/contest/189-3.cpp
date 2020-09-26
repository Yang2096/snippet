#include "pch.h"
vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
{
    unordered_map<string, int> company_map;
    vector<int> ans;

    vector<pair<vector<bool>, int>> favorite;
    for (int i = 0; i < favoriteCompanies.size(); ++i)
    {
        vector<bool> check(501, false);
        for (auto &s : favoriteCompanies[i])
        {
            auto it = company_map.find(s);
            if (it == company_map.end())
            {
                check[company_map.size()] = true;
                company_map.emplace(s, company_map.size());
            }
            else
            {
                check[it->second] = true;
            }
        }
        favorite.emplace_back(move(check), i);
    }

    sort(favorite.begin(), favorite.end(), [&favoriteCompanies](const pair<vector<bool>, int> &a, const pair<vector<bool>, int> &b) -> bool {
        return favoriteCompanies[a.second].size() > favoriteCompanies[b.second].size();
    });
    for (auto &a : favorite)
        cout << a.second << ' ';
    cout << endl;
    auto compare = [](vector<bool> &a, vector<bool> &b) -> bool {
        for (int i = 0; i <= 500; ++i)
        {
            if (b[i] && !a[i])
                return false;
        }
        return true;
    };

    ans.push_back(favorite[0].second);
    for (int i = 1; i < favorite.size(); ++i)
    {
        int j = 0;
        for (; j < i; ++j)
        {
            if (compare(favorite[j].first, favorite[i].first))
                break;
        }
        if (j == i)
            ans.push_back(favorite[i].second);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<vector<string>> a = { {"arrtztkotazhufrsfczr", "knzgidixqgtnahamebxf", "zibvccaoayyihidztflj"},
                                 {"cffiqfviuwjowkppdajm", "owqvnrhuzwqohquamvsz"},
                                 {"knzgidixqgtnahamebxf", "owqvnrhuzwqohquamvsz", "qzeqyrgnbplsrgqnplnl"},
                                 {"arrtztkotazhufrsfczr", "cffiqfviuwjowkppdajm"},
                                 {"arrtztkotazhufrsfczr", "knzgidixqgtnahamebxf", "owqvnrhuzwqohquamvsz", "qzeqyrgnbplsrgqnplnl", "zibvccaoayyihidztflj"} };
    for(int v : peopleIndexes(a))
    {
        cout << v << ' ';
    }
    cout << endl;
}