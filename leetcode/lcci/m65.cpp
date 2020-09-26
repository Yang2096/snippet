#include"pch.h"
int add(int a, int b)
{
    int i = 0, ans = 0;
    bool s = false, step = false;
    while (i < 32)
    {
        s = ((a & (1 << i)) ^ (b & (1 << i)));
        if(step)
            s = !s;
        if (s)
        {
            ans |= (1 << i);
        }
        step = ((a & (1 << i)) && (b & (1 << i))) || (((a & (1 << i)) || (b & (1 << i))) && step);
        i++;
    }
    return ans;
}

int main()
{
    cout << add(-6, -7) << endl;
    cout << add(-6, 7) << endl;
    cout << add(6, -7) << endl;
    cout << add(6, 7) << endl;
}