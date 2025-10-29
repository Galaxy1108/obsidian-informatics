#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p = 998244353;
int n, x, fac[605], f[505][505];
int qpow(int a, int b) {
    int ans = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1) ans = ans * a % p;
    return ans;
}
int C(int n, int m) {
    if (n < m || m < 0) return 0;
    return fac[n] * qpow(fac[m] *
    fac[n - m] % p, p - 2) % p;
}
signed main() {
    freopen("arena.in", "r", stdin);
    freopen("arena.out", "w", stdout);
    cin >> n >> x;
    fac[0] = 1;
    for (int i = 1; i <= 600; ++i)
        fac[i] = fac[i - 1] * i % p;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j)
            f[i][j] = (qpow(j, i) -
            qpow(j - 1, i) + p) % p;
        for (int j = i; j <= 500; ++j)
            for (int k = 1; k <= i; ++k)
                (f[i][j] += C(i, k) *
                qpow(i - 1, i - k) % p *
                f[k][j - i + 1] % p) %= p;
    }
    int ans = 0;
    for (int i = 1; i <= x; ++i)
        ans = (ans + f[n][i]) % p;
    cout << ans << '\n';
    return 0;
}