#include<iostream>
#include<vector>

using namespace std;
bool prime[1000001];
int p[80005];
bool is_prime(int a)
{
    int c = 0;
    for (int i = 0; i <= a; ++i)
        prime[i] = true;
    prime[1] = false;
    for (int i = 2; i <= a; ++i)
    {
        if(prime[i])
        {
            p[c++] = i;
        }
        for (int j = 0; j < c && i * p[j] <= a; ++j)
        {
            prime[i * p[j]] = false;
            if(!(i%p[j]))
                break;
        }
    }
    cout << c << endl;
}

int count(int n)
{
    int sum = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        if(prime[i] && prime[n-i])
        {
            sum++;
        }
    }
    return sum;
}
int main()
{
    is_prime(1000000);
    int n;
    while(true)
    {
        cin >> n;
        if(n == 0)
        {
            cout << "end" << endl;
            break;
        }
        cout << count(n) << endl;
    }
}