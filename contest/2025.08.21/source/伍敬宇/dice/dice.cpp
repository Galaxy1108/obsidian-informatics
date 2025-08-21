#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 5000 + 12;
const int mod = 1e9 + 7;
int n,a[MAXN],rev[MAXN];
int S[MAXN][MAXN];
long long ans = 0;
inline long long pw(long long x,int k)
{
    long long res = 1;
    while (k)
    {
        if (k&1) res = res*x%mod;
        k>>=1;
        x = x*x%mod;
    }
    return res;
}
long long cal(int n,int k)
{
    long long res = 0,cur = 1;
    for (int t=0;t<=k;t++)
    {
        cur = cur*(n+1-t)%mod;
        res = (res + S[k][t]*cur%mod*rev[t+1]%mod)%mod;
    }
    return res;
}
int main()
{
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",a+i);
    sort(a+1,a+n+1);
    S[0][0] = 1;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=i;j++)
            S[i][j] = (S[i-1][j-1] + 1ll*S[i-1][j]*j)%mod;
    rev[1] = 1;
    for (int i=2;i<=n+3;i++)
        rev[i] = 1ll*(mod-mod/i)*rev[mod%i]%mod;
    long long cur = 1;
    for (int i=1;i<=n;i++) cur = cur*pw(a[i],mod-2)%mod;
    for (int i=1;i<=n;i++)
    {
        ans = (ans - cur*(cal(a[i],n-i+1)-cal(a[i-1],n-i+1)+mod)%mod + mod)%mod;
        cur = cur*a[i]%mod;
    }
    ans = (ans + a[n] + 1)%mod;
    printf("%lld",ans);
    return 0;
}