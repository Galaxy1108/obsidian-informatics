#include <cstdio>
using namespace std;
const int MAXN = 1e7 + 12;
long long mod,rev2;
int f[MAXN][2],g[MAXN][2];
int n,m;
int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%d%d%lld",&n,&m,&mod);
    rev2 = (mod+1)/2;
    f[1][0] = 1,f[m][1] = 1;
    for (int i=1;i<=n;i++)
    {
        f[0][1] = f[0][0] = f[m+1][1] = f[m+1][0] = 0;
        long long sum = 0,sum1 = 0,sum2 = 0;
        for (int j=1;j<=m;j++)
        {
            sum = (sum + f[j][0] + f[j][1])%mod;
        }
        sum = sum*rev2%mod;
        for (int j=1;j<=m;j++)
        {
            g[j][0] = (m-j+1)*sum%mod;
            g[j][1] = j*sum%mod;
        }
        sum = 0,sum1 = 0,sum2 = 0;
        for (int j=1;j<=m;j++)
        {
            sum = (sum2*j%mod + sum1 + mod)%mod;
            g[j][1] = (g[j][1] - sum + mod)%mod;
            sum1 = (sum1 + mod - 1ll*j*f[j][1]%mod)%mod;
            sum2 = (sum2 + f[j][1])%mod;
        }
        sum = 0,sum1 = 0,sum2 = 0;
        for (int j=m;j>=1;j--)
        {
            sum = (sum1 + sum2*j%mod + mod)%mod;
            g[j][0] = (g[j][0] - sum + mod)%mod;
            sum1 = (sum1 + 1ll*j*f[j][0]%mod)%mod;
            sum2 = (sum2 - f[j][0] + mod)%mod;
        }
        sum = 0;
        for (int j=1;j<=m;j++)
        {
            sum = (sum + f[j-1][1])%mod;
            g[j][0] = (g[j][0] - sum*(m-j+1)%mod + mod)%mod;
        }
        sum = 0;
        for (int j=m;j>=1;j--)
        {
            sum = (sum + f[j+1][0])%mod;
            g[j][1] = (g[j][1] - sum*j%mod + mod)%mod;
        }
        for (int j=1;j<=m;j++)
        {
            f[j][0] = g[j][0],f[j][1] = g[j][1];
            //printf("%d %d %d %d\n",i,j,f[j][0],f[j][1]);
            g[j][0] = g[j][1] = 0;
        }
    }
    long long ans = 0;
    for (int j=1;j<=m;j++)
        ans = (ans + f[j][1] + f[j][0])%mod;
    printf("%lld",ans*rev2%mod);
    return 0;
}