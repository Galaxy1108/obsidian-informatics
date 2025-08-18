#include <cstdio>
#include <cstring>
using namespace std;
int n,m,k;
long long s1[112],s2[112];
long long f[112][112][12],g[112][112][12];
inline void upd(long long&x,long long y)
{
    if (y>x) x = y;
}
int main()
{
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        s1[i] = s1[i-1] + x;
        if (m==1) x = 0xc0c0c0c0;
        else scanf("%d",&x);
        s2[i] = s2[i-1] + x;
    }
    memset(f,0xc0c0c0c0,sizeof(f));
    memset(g,0xc0c0c0c0,sizeof(g));
    f[0][0][0] = g[0][0][0] = 0;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=n;j++)
        {
            for (int t=1;t<=k;t++)
            {
                for (int x=1;x<=i;x++)
                    upd(f[i][j][t],g[i-x][j][t-1] + s1[i] - s1[i-x]);
                for (int x=1;x<=j;x++)
                    upd(f[i][j][t],g[i][j-x][t-1] + s2[j] - s2[j-x]);
                if (i==j)
                    for (int x=1;x<=i;x++)
                        upd(f[i][j][t],g[i-x][j-x][t-1] + s1[i] - s1[i-x] + s2[j] - s2[j-x]);
            }
            for (int t=0;t<=k;t++)
            {
                upd(g[i][j][t],f[i][j][t]);
                if(i>0) upd(g[i][j][t],g[i-1][j][t]);
                if(j>0) upd(g[i][j][t],g[i][j-1][t]);
            }
        }
    printf("%lld",g[n][n][k]);
    return 0;
}