#include <cstdio>
#include <cstring>
#define min(x,y) ((x)<(y)?(x):(y))
typedef long long ll;

int n,q;
ll dp[310][310],a[310][310];

int main()
{
    int xa,ya,xb,yb;
    freopen("glyph.in","r",stdin);
    freopen("glyph.out","w",stdout);
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            scanf("%lld",&a[i][j]);
    while (q--)
    {
        scanf("%d%d%d%d",&xa,&xb,&ya,&yb);
        dp[xa][ya]=a[xa][ya];
        for (int i=xa+1;i<=xb;i++)
            dp[i][ya]=dp[i-1][ya]+a[i][ya];
        for (int i=ya+1;i<=yb;i++)
            dp[xa][i]=dp[xa][i-1]+a[xa][i];
        for (int i=xa+1;i<=xb;i++)
            for (int j=ya+1;j<=yb;j++)
                dp[i][j]=min(dp[i-1][j]+a[i][j],dp[i][j-1]+a[i][j]);
        printf("%lld\n",dp[xb][yb]);
    }
    return 0;
}