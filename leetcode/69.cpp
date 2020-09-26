#include <iostream>
using namespace std;

int mySqrt(int x) {
    long long left = 0, right = x;
    long long mid = (right - left) / 2 + left;
    while(left <= right)
    {
        long long temp = mid * mid;
        if(temp == x)
            return mid;
        else if(temp > x)
        {
            right = mid;
        }
        else 
        {
            if((mid + 1) * (mid + 1) > x)
            {
                return mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        mid = (right - left) / 2 + left;
    }
    return left;
}

int main()
{
    cout << mySqrt(2147395599)<< endl;
    for(int i = 1; i < 50; ++i)
        cout << i << " -> " << mySqrt(i) << endl;
}