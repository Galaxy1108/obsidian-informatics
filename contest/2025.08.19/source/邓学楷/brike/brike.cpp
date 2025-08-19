#include <cstdio>
#include <cstring>

int n,m,a[60][60],dp[60][60][510],sum,maxn;

int max(int x,int y)
{
    return x>y?x:y;
}

int main()
{
    freopen("brike.in","r",stdin);
    freopen("brike.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=(n-i+1);j++)
            scanf("%d",&a[i][j]);
    memset(dp,-0x7f,sizeof dp);
    dp[n+1][0][0]=0;
    for (int i=n;i>=1;i--)
    {
        for (int j=0;j<=(n-i+1);j++)
        {
            sum+=a[j][i];
            for (int k=j;k<=m;k++)
                for (int l=max(0,j-1);l<=n-i;l++)
                    dp[i][j][k]=max(dp[i][j][k],dp[i+1][l][k-j]+sum);
        }
        sum=0;
    }
    for (int i=1;i<=n;i++)
        for (int j=1;j<=(n-i+1);j++)
            maxn=max(maxn,dp[i][j][m]);
    printf("%d\n",maxn);
    return 0;
}