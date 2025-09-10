#include <cstdio>
using namespace std;
const int mod = 9999973;
const int MAXN = 100 + 12;
int n,m;
int f[MAXN][MAXN][MAXN],ans;
inline void upd(int &x,int y)
{
    x += y;
    if (x>=mod) x -= mod;
}
int main()
{
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    scanf("%d%d",&n,&m);
    f[0][m][0] = 1;
    for (int i=1;i<=n;i++)
    {
        for (int c0=0;c0<=m;c0++)
            for (int c1=0;c1+c0<=m;c1++)
            {
                upd(f[i][c0][c1],f[i-1][c0][c1]);
                if (c0>=1) upd(f[i][c0-1][c1+1],1ll*f[i-1][c0][c1]*c0%mod);
                if (c1>=1) upd(f[i][c0][c1-1],1ll*f[i-1][c0][c1]*c1%mod);
                if (c0>=2) upd(f[i][c0-2][c1+2],1ll*f[i-1][c0][c1]*(1ll*c0*(c0-1)/2%mod)%mod);
                if (c1>=2) upd(f[i][c0][c1-2],1ll*f[i-1][c0][c1]*(1ll*c1*(c1-1)/2%mod)%mod);
                if (c0>=1&&c1>=1) upd(f[i][c0-1][c1],1ll*f[i-1][c0][c1]*c0%mod*c1%mod);
            }
    }
    for (int c0=0;c0<=m;c0++)
        for (int c1=0;c1+c0<=m;c1++)
            upd(ans,f[n][c0][c1]);
    printf("%d",ans);
    return 0;
}