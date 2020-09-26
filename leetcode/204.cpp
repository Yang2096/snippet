#include "pch.h"

int countPrimes(int n) {
    vector<bool> isPrime(n, true);
    vector<int> prime;

    isPrime[1] = false;
    for (int i = 2; i < n; ++i)
    {
        if(isPrime[i])
        {
            prime.push_back(i);
        }
        for(int a : prime)
        {
            if(a * i >= n)
                break;
            else
            {
                isPrime[a * i] = false;
                if(!(i%a))
                    break;
            }
        }
    }
    return prime.size();
}

int main()
{
    cout << countPrimes(11) << " 4" << endl;
}