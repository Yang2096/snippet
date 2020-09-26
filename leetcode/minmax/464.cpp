#include "pch.h"

int n;
vector<unsigned char> state(1 << 21, 0);

bool dfs(int s, int target)
{
    for (int i = n - 1; i >= 0; --i)
    {
        if(s & (1 << i))
            continue;

        if(i + 1 >= target)
        {
            state[s] = 1;
            return true;
        }
        s |= 1 << i;
        bool temp;
        if (state[s] != 0)
            temp = state[s] == 1;
        else 
            temp = dfs(s, target - i - 1);
        s &= ~(1 << i);
        if(!temp)
        {
            state[s] = 1;
            return true;
        }
    }
    state[s] = 2;
    return false;
}

bool canIWin(int maxChoosableInteger, int desiredTotal) {
    if(maxChoosableInteger >= desiredTotal)
        return true;
    if (desiredTotal > ((1 + maxChoosableInteger) * maxChoosableInteger / 2))
        return false;

    n = maxChoosableInteger;
    fill(state.begin(), state.end(), 0);
    return dfs(0, desiredTotal);
}

int main()
{
    cout << canIWin(10, 11) << " 0" << endl;
    cout << canIWin(10, 15) << " 1" << endl;
    cout << canIWin(10, 17) << " 1" << endl;
    cout << canIWin(10, 18) << " 1" << endl;
}