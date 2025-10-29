#include <cstdio>
using namespace std;
const int mod = 998244353;
const int MAXN = 512;
long long C[MAXN][MAXN],pw[MAXN][MAXN];
void init()
{
    for (int i=0;i<=500;i++)
    {
        C[i][0] = C[i][i] = 1;
        for (int j=1;j<i;j++)
            C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
    }
    for (int i=0;i<=500;i++)
    {
        pw[i][0] = 1;
        for (int j=1;j<=500;j++)
            pw[i][j] = pw[i][j-1]*i%mod;
    }
}
long long f[MAXN][MAXN];
int n,x;
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    init();
    scanf("%d%d",&n,&x);
    for (int i=0;i<=x;i++) f[0][i] = 1;
    for (int i=2;i<=n;i++)
        for (int j=1;j<=x;j++)
        {
            if (j<=i-1) f[i][j] = pw[j][i];
            else 
            {
                for (int t=0;t<=i;t++)
                    f[i][j] = (f[i][j] + f[i-t][j-(i-1)]*C[i][t]%mod*pw[i-1][t])%mod;
            }
            //printf("%d %d %lld\n",i,j,f[i][j]);
        }
    printf("%lld",f[n][x]);
    return 0;
}