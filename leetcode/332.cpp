#include "pch.h"
    map<string, int> _map;
    vector<string> reverse_map;
    vector<string> real_ans;
    int _port;

    bool dfs(vector<string> & ans, int index, vector<vector<int>> & mat)
    {
        ans.emplace_back(reverse_map[index]);
        if (ans.size() == _port)
        { 
            real_ans = ans;
            return true;
        }

        for (int i = 0; i < mat.size(); ++i)
        {
            if (mat[index][i] > 0)
            {
                mat[index][i] -= 1;
                if (dfs(ans, i, mat))
                    return true;
                mat[index][i] += 1;
            }
        }

        ans.pop_back();
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        _port = tickets.size() + 1;
        set<string> s;
        for(auto & ticket : tickets)
        {
            s.insert(ticket[0]);
            s.insert(ticket[1]);
        }

        _map.clear();
        reverse_map.clear();
        real_ans.clear();

        for(auto & ticket : s)
        {
            _map.emplace(ticket,  _map.size());
            reverse_map.emplace_back(ticket);
            cout << ticket << " -> " << _map[ticket] << endl;
        }
        
        int n = _map.size();
        vector<vector<int>> mat(n, vector<int>(n, 0));
        for(auto & ticket : tickets)
            mat[_map[ticket[0]]][_map[ticket[1]]]++;
        for(auto & line : mat)
        { 
            for (auto n : line)
                cout << n << ' ';
            cout << endl;
        }
        cout << endl;
        vector<string> ans;
        dfs(ans, _map["JFK"], mat);

        return real_ans;
    }

int main()
{
    vector<vector<string>> tickets ={ { "JFK", "SFO" }, { "JFK", "ATL" }, { "SFO", "ATL" }, { "ATL", "JFK" }, { "ATL", "SFO" } };
    for (auto & a : findItinerary(tickets))
        cout << a << ' ';
    cout << endl;

    tickets ={ { "EZE", "AXA" }, { "TIA", "ANU" }, { "ANU", "JFK" }, { "JFK", "ANU" }, { "ANU", "EZE" }, { "TIA", "ANU" }, { "AXA", "TIA" }, { "TIA", "JFK" }, { "ANU", "TIA" }, { "JFK", "TIA" } };
    for (auto & a : findItinerary(tickets))
        cout << a << ' ';
    cout << endl;

    tickets ={ { "AXA", "EZE" }, { "EZE", "AUA" }, { "ADL", "JFK" }, { "ADL", "TIA" }, { "AUA", "AXA" }, { "EZE", "TIA" }, { "EZE", "TIA" }, { "AXA", "EZE" }, { "EZE", "ADL" }, { "ANU", "EZE" }, { "TIA", "EZE" }, { "JFK", "ADL" }, { "AUA", "JFK" }, { "JFK", "EZE" }, { "EZE", "ANU" }, { "ADL", "AUA" }, { "ANU", "AXA" }, { "AXA", "ADL" }, { "AUA", "JFK" }, { "EZE", "ADL" }, { "ANU", "TIA" }, { "AUA", "JFK" }, { "TIA", "JFK" }, { "EZE", "AUA" }, { "AXA", "EZE" }, { "AUA", "ANU" }, { "ADL", "AXA" }, { "EZE", "ADL" }, { "AUA", "ANU" }, { "AXA", "EZE" }, { "TIA", "AUA" }, { "AXA", "EZE" }, { "AUA", "SYD" }, { "ADL", "JFK" }, { "EZE", "AUA" }, { "ADL", "ANU" }, { "AUA", "TIA" }, { "ADL", "EZE" }, { "TIA", "JFK" }, { "AXA", "ANU" }, { "JFK", "AXA" }, { "JFK", "ADL" }, { "ADL", "EZE" }, { "AXA", "TIA" }, { "JFK", "AUA" }, { "ADL", "EZE" }, { "JFK", "ADL" }, { "ADL", "AXA" }, { "TIA", "AUA" }, { "AXA", "JFK" }, { "ADL", "AUA" }, { "TIA", "JFK" }, { "JFK", "ADL" }, { "JFK", "ADL" }, { "ANU", "AXA" }, { "TIA", "AXA" }, { "EZE", "JFK" }, { "EZE", "AXA" }, { "ADL", "TIA" }, { "JFK", "AUA" }, { "TIA", "EZE" }, { "EZE", "ADL" }, { "JFK", "ANU" }, { "TIA", "AUA" }, { "EZE", "ADL" }, { "ADL", "JFK" }, { "ANU", "AXA" }, { "AUA", "AXA" }, { "ANU", "EZE" }, { "ADL", "AXA" }, { "ANU", "AXA" }, { "TIA", "ADL" }, { "JFK", "ADL" }, { "JFK", "TIA" }, { "AUA", "ADL" }, { "AUA", "TIA" }, { "TIA", "JFK" }, { "EZE", "JFK" }, { "AUA", "ADL" }, { "ADL", "AUA" }, { "EZE", "ANU" }, { "ADL", "ANU" }, { "AUA", "AXA" }, { "AXA", "TIA" }, { "AXA", "TIA" }, { "ADL", "AXA" }, { "EZE", "AXA" }, { "AXA", "JFK" }, { "JFK", "AUA" }, { "ANU", "ADL" }, { "AXA", "TIA" }, { "ANU", "AUA" }, { "JFK", "EZE" }, { "AXA", "ADL" }, { "TIA", "EZE" }, { "JFK", "AXA" }, { "AXA", "ADL" }, { "EZE", "AUA" }, { "AXA", "ANU" }, { "ADL", "EZE" }, { "AUA", "EZE" } };
    for (auto & a : findItinerary(tickets))
        cout << a << ' ';
    cout << endl;

    tickets ={ { "CBR", "JFK" }, { "TIA", "EZE" }, { "AUA", "TIA" }, { "JFK", "EZE" }, { "BNE", "CBR" }, { "JFK", "CBR" }, { "CBR", "AUA" }, { "EZE", "HBA" }, { "AXA", "ANU" }, { "BNE", "EZE" }, { "AXA", "EZE" }, { "AUA", "ADL" }, { "OOL", "JFK" }, { "BNE", "AXA" }, { "OOL", "EZE" }, { "EZE", "ADL" }, { "TIA", "BNE" }, { "EZE", "TIA" }, { "JFK", "AUA" }, { "AUA", "EZE" }, { "ANU", "ADL" }, { "TIA", "BNE" }, { "EZE", "OOL" }, { "ANU", "BNE" }, { "EZE", "ANU" }, { "ANU", "AUA" }, { "BNE", "ANU" }, { "CNS", "JFK" }, { "TIA", "ADL" }, { "ADL", "AXA" }, { "JFK", "OOL" }, { "AUA", "ADL" }, { "ADL", "TIA" }, { "ADL", "ANU" }, { "ADL", "JFK" }, { "BNE", "EZE" }, { "ANU", "BNE" }, { "JFK", "BNE" }, { "EZE", "AUA" }, { "EZE", "AXA" }, { "AUA", "TIA" }, { "ADL", "CNS" }, { "AXA", "AUA" } };
    for (auto & a : findItinerary(tickets))
        cout << a << ' ';
    cout << endl;

}