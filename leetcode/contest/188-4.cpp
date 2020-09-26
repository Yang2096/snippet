#include "pch.h"

int ans, n, m;

void search(vector<vector<int>> &apple, int a, int b, int k)
{
    if (k == 1)
    {
        if (apple[a][b] >= 1)
            ans = (ans + 1) % 1000000007;
    }
    else
    {
        for (int i = a + 1; i < n; ++i)
        {
            if (apple[a][b] - apple[i][b] >= 1)
            {
                search(apple, i, b, k - 1);
            }
        }

        for (int i = b + 1; i < m; ++i)
        {
            if (apple[a][b] - apple[a][i] >= 1)
            {
                search(apple, a, i, k - 1);
            }
        }
    }
}

int ways(vector<string> &pizza, int k)
{
    ans = 0;
    n = pizza.size();
    m = pizza[0].length();
    vector<vector<int>> apple(n, vector<int>(m, 0));
    apple[n - 1][m - 1] = ((pizza[n - 1][m - 1] == 'A') ? 1 : 0);
    for (int i = m - 2; i >= 0; --i)
    {
        apple[n - 1][i] = apple[n - 1][i + 1] + ((pizza[n - 1][i] == 'A') ? 1 : 0);
    }
    for (int i = n - 2; i >= 0; --i)
    {
        int temp = 0;
        for (int j = m - 1; j >= 0; --j)
        {
            temp += ((pizza[i][j] == 'A') ? 1 : 0);
            apple[i][j] = temp + apple[i + 1][j];
        }
    }
    search(apple, 0, 0, k - 1);
    return ans;

    using ll = long long;
    vector<vector<vector<ll>>> dp(k, vector<vector<ll>>(n, vector<ll>(m, 0)));

    dp[0][0][0] = 1;
    for(int l = 1; l < k; ++l)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if(dp[l-1][i][j] == 0)
                    continue;
                for(int x = i + 1; x < n; ++x)
                    if (apple[i][j] - apple[x][j] >= 1 && apple[x][j] >= 1)
                    {
                        dp[l][x][j] += dp[l-1][i][j];
                        dp[l][x][j] %= 1000000007;
                    }

                for (int x = j + 1; x < m; ++x)
                    if (apple[i][j] - apple[i][x] >= 1 && apple[i][x] >= 1)
                    {
                        dp[l][i][x] += dp[l-1][i][j];
                        dp[l][i][x] %= 1000000007;
                    }
            }
        }
    }

    ll ans = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            ans += dp[k-1][i][j];
        }
    }

    return ans;
}

int main()
{
    vector<string> pizza = { "..A.A.AAA...AAAAAA.AA..A..A.A......A.AAA.AAAAAA.AA",
                             "A.AA.A.....AA..AA.AA.A....AAA.A........AAAAA.A.AA.",
                             "A..AA.AAA..AAAAAAAA..AA...A..A...A..AAA...AAAA..AA",
                             "....A.A.AA.AA.AA...A.AA.AAA...A....AA.......A..AA.",
                             "AAA....AA.A.A.AAA...A..A....A..AAAA...A.A.A.AAAA..",
                             "....AA..A.AA..A.A...A.A..AAAA..AAAA.A.AA..AAA...AA",
                             "A..A.AA.AA.A.A.AA..A.A..A.A.AAA....AAAAA.A.AA..A.A",
                             ".AA.A...AAAAA.A..A....A...A.AAAA.AA..A.AA.AAAA.AA.",
                             "A.AA.AAAA.....AA..AAA..AAAAAAA...AA.A..A.AAAAA.A..",
                             "A.A...A.A...A..A...A.AAAA.A..A....A..AA.AAA.AA.AA.",
                             ".A.A.A....AAA..AAA...A.AA..AAAAAAA.....AA....A....",
                             "..AAAAAA..A..A...AA.A..A.AA......A.AA....A.A.AAAA.",
                             "...A.AA.AAA.AA....A..AAAA...A..AAA.AAAA.A.....AA.A",
                             "A.AAAAA..A...AAAAAAAA.AAA.....A.AAA.AA.A..A.A.A...",
                             "A.A.AA...A.A.AA...A.AA.AA....AA...AA.A..A.AA....AA",
                             "AA.A..A.AA..AAAAA...A..AAAAA.AA..AA.AA.A..AAAAA..A",
                             "...AA....AAAA.A...AA....AAAAA.A.AAAA.A.AA..AA..AAA",
                             "..AAAA..AA..A.AA.A.A.AA...A...AAAAAAA..A.AAA..AA.A",
                             "AA....AA....AA.A......AAA...A...A.AA.A.AA.A.A.AA.A",
                             "A.AAAA..AA..A..AAA.AAA.A....AAA.....A..A.AA.A.A...",
                             "..AA...AAAAA.A.A......AA...A..AAA.AA..A.A.A.AA..A.",
                             ".......AA..AA.AAA.A....A...A.AA..A.A..AAAAAAA.AA.A",
                             ".A.AAA.AA..A.A.A.A.A.AA...AAAA.A.A.AA..A...A.AAA..",
                             "A..AAAAA.A..A..A.A..AA..A...AAA.AA.A.A.AAA..A.AA..",
                             "A.AAA.A.AAAAA....AA..A.AAA.A..AA...AA..A.A.A.AA.AA",
                             ".A..AAAA.A.A.A.A.......AAAA.AA...AA..AAA..A...A.AA",
                             "A.A.A.A..A...AA..A.AAA..AAAAA.AA.A.A.A..AA.A.A....",
                             "A..A..A.A.AA.A....A...A......A.AA.AAA..A.AA...AA..",
                             ".....A..A...A.A...A..A.AA.A...AA..AAA...AA..A.AAA.",
                             "A...AA..A..AA.A.A.AAA..AA..AAA...AAA..AAA.AAAAA...",
                             "AA...AAA.AAA...AAAA..A...A..A...AA...A..AA.A...A..",
                             "A.AA..AAAA.AA.AAA.A.AA.A..AAAAA.A...A.A...A.AA....",
                             "A.......AA....AA..AAA.AAAAAAA.A.AA..A.A.AA....AA..",
                             ".A.A...AA..AA...AA.AAAA.....A..A..A.AA.A.AA...A.AA",
                             "..AA.AA.AA..A...AA.AA.AAAAAA.....A.AA..AA......A..",
                             "AAA..AA...A....A....AA.AA.AA.A.A.A..AA.AA..AAA.AAA",
                             "..AAA.AAA.A.AA.....AAA.A.AA.AAAAA..AA..AA.........",
                             ".AA..A......A.A.AAA.AAAA...A.AAAA...AAA.AAAA.....A",
                             "AAAAAAA.AA..A....AAAA.A..AA.A....AA.A...A.A....A..",
                             ".A.A.AA..A.AA.....A.A...A.A..A...AAA..A..AA..A.AAA",
                             "AAAA....A...A.AA..AAA..A.AAA..AA.........AA.AAA.A.",
                             "......AAAA..A.AAA.A..AAA...AAAAA...A.AA..A.A.AA.A.",
                             "AA......A.AAAAAAAA..A.AAA...A.A....A.AAA.AA.A.AAA.",
                             ".A.A....A.AAA..A..AA........A.AAAA.AAA.AA....A..AA",
                             ".AA.A...AA.AAA.A....A.A...A........A.AAA......A...",
                             "..AAA....A.A...A.AA..AAA.AAAAA....AAAAA..AA.AAAA..",
                             "..A.AAA.AA..A.AA.A...A.AA....AAA.A.....AAA...A...A",
                             ".AA.AA...A....A.AA.A..A..AAA.A.A.AA.......A.A...A.",
                             "...A...A.AA.A..AAAAA...AA..A.A..AAA.AA...AA...A.A.",
                             "..AAA..A.A..A..A..AA..AA...A..AA.AAAAA.A....A..A.A" };
    cout << ways(pizza, 8) << endl;
}