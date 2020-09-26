#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
using namespace std;

int minNumberOfFrogs(string croakOfFrogs)
{
    int n = croakOfFrogs.length();
    if(n < 5) 
        return 0;
    int ans = 0;
    auto dp = vector<int>(5, 0);
    for(int i = 0; i < n; ++i)
    {
        switch(croakOfFrogs[i])
        {
            case 'c':
            {
                dp[0]++;
                break;
            }
            case 'r':
            {
                dp[1]++;
                break;
            }
            case 'o':
            {
                dp[2]++;
                break;
            }
            case 'a':
            {
                dp[3]++;
                break;
            }
            case 'k':
            {
                dp[4]++;
                break;
            }
        }
        if(dp[1] > dp[0] || dp[2] > dp[1] || dp[3] > dp[2] || dp[4] > dp[3])
            return -1;
        ans = max(ans, dp[0]);
        if(dp[4] == 1)
        {
            for(int j = 0; j < 5; ++j)
                dp[j]--;
        }
    }
    if(dp[0] != 0) return -1;
    return ans;
}

int main()
{
    cout << minNumberOfFrogs("croakcroak") << endl;
    cout << minNumberOfFrogs("ccccrrrrooooaaaakkkk") << endl;

}