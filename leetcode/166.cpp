#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if(numerator == 0)
        return "0";
    if (numerator == denominator)
        return "1";
    string ans;
    long long n = numerator, d = denominator;
    if (n < 0 || d < 0)
    {
        if(n > 0 || d > 0)
        {
            ans += '-';
        }
        n = abs(n);
        d = abs(d);
    }

    long long first_part = 0;
    vector<int> result;
    
    if (n > d)
    {
        first_part = n / d;
        n = n % d;
    }

    unordered_map<long long, int> loop;
    long long res, mod;
    while (true)
    {
        res = n / d;
        mod = n - d * res;
        result.push_back(res);
        if(mod == 0 || loop.count(mod) > 0)
        {
            break;
        }    
        else
        {
            n = mod * 10;     
            loop.emplace(mod, result.size());
            while (n < d)
            {
                n *= 10;
                result.push_back(0);
            }
        }
    }

    ans += to_string(first_part);
    if (result.size() > 1)
        ans += '.';
    if (mod == 0 || loop.find(mod) == loop.end())
    {
        for (int i = 1; i < result.size(); ++i)
            ans += (result[i] + '0');
    }
    else
    {
        int pos = loop.find(mod)->second;
        for (int i = 1; i < pos; ++i)
        {
            ans += (result[i] + '0');
        }
        ans += '(';
        for (int i = pos; i < result.size(); ++i)
        {
            ans += to_string(result[i]);
        }
        ans += ')';
    }

    return ans;
}

int main()
{
    cout << fractionToDecimal(22, 7) << endl;
    cout << fractionToDecimal(1, 3) << endl;
    cout << fractionToDecimal(255, 7) << endl;
    cout << fractionToDecimal(1000, 77) << endl;
    cout << fractionToDecimal(12, 4) << endl;
    cout << fractionToDecimal(11, 4) << endl;
    cout << fractionToDecimal(-50, 8) << endl;
    cout << fractionToDecimal(-1, -2147483648) << endl;
    cout << fractionToDecimal(-2147483648, 1) << endl;
}