#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll dp[505][505];
ll f[505];
#define mod 998244353

ll fpow(ll a, ll b) {
    ll ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * a) % mod;
        }
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

ll cc(ll n, ll m) {
    return (f[m] * fpow(f[n] * f[m - n] % mod, mod - 2)) % mod;
}

int main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    int n, x;
    cin >> n >> x;
    for (int j = 1;j <= x;j++) {
        dp[1][j] = 1;
    }
    f[0] = 1;
    for (int i = 1;i <= n;i++) {
        f[i] = (f[i - 1] * i) % mod;
    }
    for (int i = 2;i <= n;i++) {
        for (int j = 1;j <= x;j++) {
            if (j < i) {
                continue;
            }
            for (int k = 1;k <= i;k++) {
                dp[i][j] = (dp[i][j] + ((dp[k][j - i + 1] * cc(k, i) % mod) * fpow(i - 1, i - k) % mod)) % mod;
            }
        }
    }
    ll res = 0;
    for (int j = 1;j <= x;j++) {
        res = (res + dp[n][j]) % mod;
    }
    cout << (fpow(x, n) - res + mod) % mod;
    return 0;
}
