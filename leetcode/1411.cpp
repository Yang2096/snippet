#include "pch.h"

int numOfWays(int n)
{
    long long abc = 6, aba = 6;
    long long temp1, temp2;
    while (--n)
    {
        temp1 = (2 * abc + 2 * aba) % 1000000007;
        temp2 = (2 * abc + 3 * aba) % 1000000007;
        abc = temp1;
        aba = temp2;
    }
    return (abc + aba) % 1000000007;
}

int main()
{
    cout << numOfWays(2) << " 54" << endl;
    cout << numOfWays(3) << " 246" << endl;
    cout << numOfWays(7) << " 106494" << endl;
    cout << numOfWays(5000) << " 30228214" << endl;
}