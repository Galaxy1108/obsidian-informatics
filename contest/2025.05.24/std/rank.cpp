#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int maxn = 1e5 + 50;
const int mod = 1e9 + 7;

int a[maxn];
ll b[maxn];
ll fac[maxn];       
ll inv[maxn];       
ll inv_fac[maxn];   

ll get_inv(ll x)
{
    if (inv[x]) return inv[x];
    if (x == 1) return inv[x] = 1;
    return inv[x] = (mod - mod/x) * get_inv(mod % x) % mod;
}

void init()         
{
    for (int i = 1; i < maxn; ++i)
        get_inv(i);
    fac[0] = inv_fac[0] = 1;
    for (int i = 1; i < maxn; ++i)
    {
        fac[i] = fac[i-1] * i % mod;
        inv_fac[i] = inv_fac[i-1] * inv[i] % mod;
    }
}

ll C(int n, int m)  
{
    if (m < 0 || n < m) return 0;
    return fac[n] * inv_fac[m] % mod * inv_fac[n-m] % mod;
}

int main()
{
    freopen("rank.in", "r", stdin);
    freopen("rank.out", "w", stdout);
    init();
    int n, k, t;
    scanf("%d %d %d", &n, &k, &t);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    sort(b, b+n);
    for (int i = 0; i < n; ++i)
    {
        ll x = a[i];
        int m = upper_bound(b, b+n, x) - upper_bound(b, b+n, x/t);
        ll ans = C(n-m, k);
        m = upper_bound(b, b+n, x*t) - upper_bound(b, b+n, x);
        ans = (ans + C(n-m-1, k-1-m)) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}
