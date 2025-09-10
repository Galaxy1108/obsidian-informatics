#include <bits/stdc++.h>
using namespace std;
const int mod = 9999973;
long long dp[2][110][110];
int C[110][110];
void init(int t)
{
    for(int i=0;i<=100;i++)
    {
        for(int j=0;j<=100;j++)
        {
            dp[t][i][j] = 0;
        }
    }
}
int initC(int n)
{
    C[0][0] = 1;
    for(int i=1;i<=n;i++)
    {
        C[i][0] = C[i][i] = 1;
        for(int j=1;j<i;j++)
        {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
}
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int t = 0;
    dp[0][0][0] = 1;
    initC(100);
    for(int i=1;i<=n;i++)
    {
        t ^= 1;
        init(t);
        for(int j=0;j<=m;j++) // 1
        {
            for(int k=0;k<=m;k++) // 2
            {
                // 0
                dp[t][j][k] = (dp[t][j][k] + dp[t^1][j][k]) % mod;
                // 1
                if(j) dp[t][j-1][k+1] = (dp[t][j-1][k+1] + (dp[t^1][j][k] * C[j][1])) % mod;
                dp[t][j+1][k] = (dp[t][j+1][k] + (dp[t^1][j][k] * C[m-j-k][1])) % mod;
                // 2
                if(j >= 2) dp[t][j-2][k+2] = (dp[t][j-2][k+2] + (dp[t^1][j][k] * C[j][2])) % mod;
                dp[t][j][k+1] = (dp[t][j][k+1] + (dp[t^1][j][k] * C[j][1] * C[m-j-k][1])) % mod;
                dp[t][j+2][k] = (dp[t][j+2][k] + (dp[t^1][j][k] * C[m-j-k][2])) % mod;
            }
        }
    }
    long long ans = 0;
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=m;j++)
        {
            ans = (ans + dp[t][i][j]) % mod;
        }
    }
    cout << ans;
    return 0;
}