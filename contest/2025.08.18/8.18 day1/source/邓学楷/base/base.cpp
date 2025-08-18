#include <cstdio>
typedef long long ll;

int n,a[2][2010];
ll x[2010],y[2010],s[2010],sum[2][2010],ans=-0x7f7f7f7f7f7f7f7f;

ll max(ll p,ll q)
{
    return p>q?p:q;
}

int main()
{
    freopen("base.in","r",stdin);
    freopen("base.out","w",stdout);
    scanf("%d",&n);
    for (int i=0;i<2;i++)
        for (int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            sum[i][j]=sum[i][j-1]+a[i][j];
            s[j]+=a[i][j];
        }
    for (int i=1;i<=n;i++)
        x[i]=max(x[i-1]+s[i],s[i]);
    for (int i=n;i>=1;i--)
        y[i]=max(y[i+1]+s[i],s[i]);
    for (int i=1;i<=n;i++)
        for (int j=n;j>i+1;j--)
            ans=max(ans,x[i]+y[j]+sum[1][j-1]-sum[1][i]);
    printf("%lld\n",ans);
    return 0;
}
