#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 510,mod = 998244353;
ll f[N],invf[N];
ll dp[N][N];
int n,m;
int qpow(int a,int b)
{
    int ret=1;
    while(b)
    {
        if(b&1) ret = (1ll*ret*a) % mod;
        a = (1ll*a*a) % mod;
        b >>= 1;
    }
    return ret;
}
void init_f()
{
    f[0] = 1;
    for(int i=1;i<=n;i++)
    {
        f[i] = (1ll*f[i-1]*i) % mod;
    }
    invf[n] = qpow(f[n],mod-2);
    for(int i=n-1;i>=1;i--)
    {
        invf[i] = (1ll*(invf[i+1])*(i+1)) % mod;
    }
    invf[0] = 1;
}
ll C(int n,int m)
{
    return ((((1ll*f[n]*invf[m]) % mod) * invf[n-m]) % mod);
}
int main()
{
    freopen("arena.in","r",stdin);
    freopen("arena.out","w",stdout);
    cin >> n >> m;
    init_f();
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i-1;j++) 
        {
            dp[i][j] = (1ll*((mod + qpow(j,i) - qpow(j-1,i)) % mod)) * C(n,i) % mod;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            for(int k=0;k<=n-i and j+i+k-1<=m;k++)
            {
                dp[i+k][j+i+k-1] = (dp[i+k][j+i+k-1] + ((1ll*dp[i][j]*qpow(i+k-1,k) % mod) * C(n-i,k) % mod) % mod) % mod;
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=m;i++)
    {
        // cout << dp[n][i] << ' ';
        ans = (ans+dp[n][i]) % mod;
    }
    cout << ans;
}