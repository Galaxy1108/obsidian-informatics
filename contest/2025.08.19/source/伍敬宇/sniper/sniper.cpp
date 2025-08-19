#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int val[23] = {0,100,100,97,96,95,90,85,80,82,78,75,70,65,55,50,15,12,10,8,5,2};
long long a[25000+12][23];
long long f[25000+12][23][2],ans,bs;
int n;
inline void upd(long long&x,long long y)
{
    if (x<y) x = y;
}
int main()
{
    freopen("sniper.in","r",stdin);
    freopen("sniper.out","w",stdout);
    val[15] += 1e6;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int w,u,t;
        scanf("%d%d%d",&w,&u,&t);
        t++;
        a[t][u] = max(1ll*val[w],a[t][u]);
        if (w==15) bs -= 1e6;
    }
    memset(f,0xc0c0c0c0,sizeof(f));
    for (int j=0;j<=20;j++)
        f[0][j][0] = 0;
    for (int i=1;i<=25004;i++)
    {
        for (int j=0;j<=20;j++)
        {
            if (j>=1) upd(f[i][j][0],f[i-1][j-1][0]),upd(f[i][j][1],f[i-1][j-1][0]+a[i][j]);
            if (j>=2) upd(f[i][j][0],f[i-1][j-2][0]),upd(f[i][j][1],f[i-1][j-2][0]+a[i][j]);
            upd(f[i][j][0],f[i-1][j][0]);
            upd(f[i][j][0],f[i-1][j][1]);
            upd(f[i][j][1],f[i-1][j][0]+a[i][j]);
            if (j+1<=20) upd(f[i][j][0],f[i-1][j+1][0]),upd(f[i][j][1],f[i-1][j+1][0]+a[i][j]);
            if (j+2<=20) upd(f[i][j][0],f[i-1][j+2][0]),upd(f[i][j][1],f[i-1][j+2][0]+a[i][j]);
            upd(ans,f[i][j][0]),upd(ans,f[i][j][1]);
        }
    }
    printf("%lld",ans+bs);
    return 0;
}