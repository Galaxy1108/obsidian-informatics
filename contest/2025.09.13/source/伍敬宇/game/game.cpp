#include <cstdio>
using namespace std;
const int MAXN = 1e6 + 12;
const int mod = 998244353;
int n=1e6,k;
int dp[MAXN],s[MAXN];
int g[MAXN];
int p[MAXN],mu[MAXN],b[MAXN],cnt;
int f[MAXN],res[MAXN];
long long rev[MAXN];
void init()
{
    b[1] = 1;
    mu[1] = 1;
    for (int i=2;i<=n;i++)
    {
        if (b[i]==0) p[++cnt] = i,mu[i] = -1;
        for (int j=1;j<=cnt&&i*p[j]<=n;j++)
        {
            b[i*p[j]] = 1;
            if (i%p[j]==0)
            {
                mu[i*p[j]] = 0;
                break;
            }
            else mu[i*p[j]] = -mu[i];
        }
    }
    rev[1] = 1;
    for (int i=2;i<=n;i++)
        rev[i] = rev[mod%i]*(mod-mod/i)%mod;
}
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    init();
    scanf("%d",&k);
    if (k==0) k = 1;
    for (int i=1;i<=n;i++)
    {
        dp[i] = 1;
        if (i-k-1>=0) dp[i] = (s[i-k-1]+1)%mod;
        s[i] = (s[i-1]+dp[i])%mod;
    }
    for (int i=k+1;i<=n;i++)
        g[i] = (1ll*(k+1)*dp[i-k]+s[i-k-1])%mod;
    for (int x=1;x<=n;x++)
    {
        for (int y=1;x*y<=n;y++)
        {
            f[x*y] += g[x]*mu[y];
            if (f[x*y]<0) f[x*y] += mod;
            if (f[x*y]>=mod) f[x*y] -= mod;
        }
    }
    for (int x=1;x<=n;x++)
        for (int y=1;y*x<=n;y++)
            res[x*y] = (res[x*y] + f[x]*rev[x])%mod;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int x;
        scanf("%d",&x);
        printf("%d %d\n",g[x],res[x]);
    }
    return 0;
}