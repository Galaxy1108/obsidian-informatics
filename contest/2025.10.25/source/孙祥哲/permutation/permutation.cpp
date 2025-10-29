#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll qpow(ll a, ll b)
{
    ll r = 1;
    while (b)
    {
        if (b & 1) r = r * a % mod;
        b >>= 1, a = a * a % mod;
    }
    return r;
}

int n, a[605], b[605], c[605], cur, p[605], f[605];
ll fact[1005];
map<vector<int>, int> mp;

int main()
{
    freopen("permutation.in", "r", stdin);
    freopen("permutation.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    if (n > 10)
    {
        fact[1] = 1;
        for (int i = 2; i <= 1000; i++) fact[i] = fact[i-1]*i%mod;
        cout << 1ll*fact[2*n]*qpow(fact[n+1], mod-2)%mod;
        return 0;
    }
    for (int i = 1; i <= 2*n; i++) { cin >> a[i]; if(a[i]!=-1) f[a[i]] = 1; }
    for (int i = 1; i <= 2*n; i++) if (!f[i]) b[++cur] = i, p[cur] = cur;
    do
    {
        int _ = 0;
        vector<int> v;
        // for (int i = 1; i <= cur; i++) cout << p[i] << "-"; cout << '\n';
        for (int i = 1; i <= 2*n; i++) c[i] = (a[i]!=-1?a[i]:b[p[++_]]);
        // for (int i = 1; i <= 2*n; i++) cout << b[i] << "-"; cout << '\n';
        for (int i = 1; i <= n; i++) v.push_back(min(c[2*i],c[2*i-1]));
        mp[v] = 1;
    } while (next_permutation(p+1, p+1+cur));
    cout << mp.size();
    return 0;
}