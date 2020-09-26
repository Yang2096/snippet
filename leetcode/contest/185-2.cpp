#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<string>
using namespace std;
    
vector<vector<string>> displayTable(vector<vector<string>>& orders) {
    map<string, int> food;
    vector<string> food_name;
    map<int, vector<int>> table_order;
    
    for(auto & order : orders)
    {
        int food_number;
        auto f = food.find(order[2]);
        if(f == food.end())
        {
            food_number = food_name.size();
            food_name.emplace_back(order[2]);
            food.emplace(order[2], food_number);
        }
        else
        {
            food_number = f->second;
        }

        auto f1 = table_order.find(std::stoi(order[1]));
        if(f1 == table_order.end())
        {
            f1 = table_order.emplace(stoi(order[1]), vector<int>(food.size(), 0)).first;
        }

        while (f1->second.size() < food.size())
        {
            f1->second.push_back(0);
        }

        f1->second[food_number]++;
    }

    vector<vector<string>> ans;
    ans.push_back({"Table"});
    for(auto & name : food)
    {
        ans[0].emplace_back(name.first);
    }
    for(auto & p : table_order)
    {
        vector<string> line;
        line.emplace_back(std::to_string(p.first));
        for(auto & m : food)
        {
            if(m.second >= p.second.size())
            {
                line.emplace_back("0");
            }
            else
            {
                line.emplace_back(std::to_string(p.second[m.second]));
            }
        }
        ans.emplace_back(move(line));
    }
    return ans;
}

int main()
{
    vector<vector<string>> orders = { {"David", "3", "Ceviche"},
                                      {"Corina", "10", "Beef Burrito"},
                                      {"David", "3", "Fried Chicken"},
                                      {"Carla", "5", "Water"},
                                      {"Carla", "5", "Ceviche"},
                                      {"Rous", "3", "Ceviche"} };
    for (auto &line : displayTable(orders))
    {
        for(auto &s : line)
        {
            cout << s << ',';
        }
        cout << endl;
    }
}