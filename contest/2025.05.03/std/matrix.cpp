#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7FFFFFFF;
int a[80][80];
int dp[80][80][80][80];


int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            for (int c = 0; c < m; ++c)
                for (int l = 0; l < k; ++l)
                    dp[i][j][c][l] = -INF;
    dp[1][0][0][0] = 0;
    for (int i = 1; i <= n; ++i)
    {
        for (int l = 0; l < k; ++l)
        {
            for (int c = 0; c <= m/2; ++c)
                dp[i][0][0][l] = max(dp[i][0][0][l], dp[i-1][m][c][l]);
        }
        for (int j = 1; j <= m; ++j)
        {
            for (int c = 0; c <= m/2; ++c)
                for (int l = 0; l < k; ++l)
                {
                    int x = (l + a[i][j]) % k;
                    if (c > 0)
                        dp[i][j][c][x] = max(dp[i][j-1][c-1][l]+a[i][j], dp[i][j][c][x]);
                    dp[i][j][c][l] = max(dp[i][j-1][c][l], dp[i][j][c][l]);
                }
        }
    }

    int ans = 0;
    for (int i = 0; i <= m/2; ++i)
        ans = max(dp[n][m][i][0], ans);
    printf("%d\n", ans);
    return 0;
}