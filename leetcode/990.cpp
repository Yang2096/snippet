#include "pch.h"

int find(vector<int>& us, int a)
{
    return us[a] == a ? a : find(us, us[a]);
}

bool equationsPossible(vector<string>& equations) {
    vector<int> union_set(26, 0);
    for (int i = 0; i < 26; ++i)
        union_set[i] = i;
    for (auto &eq : equations)
    {
        if (eq[1] != '=')
            continue;
        int left = find(union_set, eq[0] - 'a');
        int right = find(union_set, eq[3] - 'a');
        union_set[left] = right;
    }

    for(auto&eq : equations)
    {
        if(eq[1] == '=')
            continue;
        int left = find(union_set, eq[0] - 'a');
        int right = find(union_set, eq[3] - 'a');

        if (left == right)
            return false;
    }
    return true;
}

int main()
{
    vector<string> eq = {"a==b", "b!=a"};
    cout << equationsPossible(eq) << " 0" << endl;
    eq = {"b==a", "a==b"};
    cout << equationsPossible(eq) << " 1" << endl;
    eq = {"a==b", "b!=c", "c==a"};
    cout << equationsPossible(eq) << " 0" << endl;
    eq = {"c==c", "f!=a", "f==b", "b==c"};
    cout << equationsPossible(eq) << " 1" << endl;
    eq = {"e==d", "e==a", "f!=d", "b!=c", "a==b"};
    cout << equationsPossible(eq) << " 1" << endl;
}