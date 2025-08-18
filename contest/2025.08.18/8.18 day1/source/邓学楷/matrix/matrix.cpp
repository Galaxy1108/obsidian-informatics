#include <cstdio>
#include <cstring>
typedef long long ll;

int n,m,k,mat[110][5];
ll dp[110][15][2];

ll max(ll x,ll y)
{
    return x>y?x:y;
}

int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    memset(dp,-0x3f,sizeof dp);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            scanf("%d",&mat[i][j]);
    dp[0][0][0]=dp[0][0][1]=0;
    for (int i=1;i<=n;i++)
        for (int j=0;j<=k;j++)
        {
            dp[i][j][0]=max(dp[i-1][j][0],dp[i-1][j][1]);
            if (j)
                dp[i][j][1]=max(dp[i-1][j][1],max(dp[i-1][j-1][0],dp[i-1][j-1][1]))+mat[i][1];
        }
    printf("%lld\n",max(dp[n][k][0],dp[n][k][1]));
    return 0;
}