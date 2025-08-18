#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
long long f[10012][112],g[10012][112];
int n,m,a[10012];
inline void upd(long long&x,long long y)
{
    if (x>y) x = y;
}
int main()
{
    freopen("brush.in","r",stdin);
    freopen("brush.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    memset(f,0x3f3f3f3f,sizeof(f));
    memset(g,0x3f3f3f3f,sizeof(g));
    long long ans = 2e18;
    for (int i=2;i<=n;i++)
    {
        if (i<=m)
            for (int j=1;j<i;j++)
                upd(f[i][j],a[i]+a[i-j]);
        for (int j=1;j<m&&j<i;j++)
            upd(f[i][j],a[i]+g[i-j][m-j]);
        for (int j=1;j<m;j++)
        {
            g[i][j] = min(g[i][j-1],f[i][j]);
            if (i-j>n-m) 
                upd(ans,g[i][j]);
        }
    }
    printf("%lld",ans);
    return 0;
}