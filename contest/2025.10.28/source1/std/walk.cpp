#include <bits/stdc++.h>
using namespace std;
    
const int maxn = 2e5 + 50;
    
int a[maxn];
long long dp[maxn][5];
    
int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", a + i);
    }
    for (int i = 1; i <= n; ++i)
    {
        dp[i][0] = dp[i-1][0] + a[i];
        dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
        dp[i][2] = min(dp[i][1], dp[i-1][2]);
        dp[i][3] = min(dp[i][2], dp[i-1][3]);
        dp[i][4] = min(dp[i][3], dp[i-1][4]) + a[i];
        if (a[i] == 0)
        {
            dp[i][1] += 2;
            dp[i][2] += (a[i] & 1) ^ 1 ;
            dp[i][3] += 2;
        }
        else
        {
            dp[i][1] += a[i] & 1;
            dp[i][2] += (a[i] & 1) ^ 1 ;
            dp[i][3] += a[i] & 1;
        }
    }
    
    long long ans = dp[n][0];
    for (int i = 1; i <= 4; ++i)
        ans = min(ans, dp[n][i]);
    printf("%lld\n", ans);
    return 0;
}