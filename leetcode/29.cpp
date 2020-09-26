#include <iostream>
#include <algorithm>
using namespace std;
template <typename T, typename P>
auto min(T a, P b) -> decltype(a + b)
{
    return a < b ? a : b;
}
template <typename T, typename P>
auto max(T a, P b) -> decltype(a + b)
{
    return b < a ? a : b;
}
constexpr auto INT_MAX = 0x7fffffff;
constexpr int INT_MIN = 0x80000000;

int divide(int dividend, int divisor) {
    bool sign = dividend < 0 ^ divisor < 0;
    unsigned int dvd = dividend < 0 ? ~dividend + (unsigned int)1 : dividend;
    unsigned int dor = divisor < 0 ? ~divisor + (unsigned int)1 : divisor;
    unsigned int result = 0;
    for(int i = 31; i >= 0; --i)
    {
        if((dvd >> i) >= dor)
        {
            result += (unsigned int)1 << i;
            dvd -= dor << i;
        }
    }
    if(result == INT_MIN)
        return sign ? INT_MIN : INT_MAX;
    return sign ? -(int)result: (int)result;
} 

int main(int argc, char const *argv[])
{
    cout << divide(-2147483648, 1) << endl;
    return 0;
}
