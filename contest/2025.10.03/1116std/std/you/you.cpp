#include <bits/stdc++.h>

using namespace std;

constexpr int N = 1e6 + 5, K = 2e6 + 5, p = 1e9 + 7;

int n, m, k;
struct node {
    int opt, x, y;
} g[K];
int mul[N], f[N], h[N], c[N];

inline int qpow(int x, int y) {
    int sum = 1;
    while (y) {
        if (y & 1) sum = 1ll * sum * x % p;
        x = 1ll * x * x % p;
        y >>= 1;
    }
    return sum;
}
inline int inv(int x) { return qpow(x, p - 2) % p; }

int main() {
    freopen("you.in", "r", stdin);
    freopen("you.out", "w", stdout);
    ios::sync_with_stdio(false);
    int Case;
    // cin >> Case;
    cin >> n >> m >> k;
    fill(h + 1, h + n + 1, 1);
    fill(c + 1, c + m + 1, 1);
    for (int i = 1; i <= k; ++i) {
        int opt, l, r, x;
        cin >> opt >> l >> r >> x;
        if (opt == 1)
            h[l] = 1ll * h[l] * x % p, h[r + 1] = 1ll * h[r + 1] * inv(x) % p;
        else
            c[l] = 1ll * c[l] * x % p, c[r + 1] = 1ll * c[r + 1] * inv(x) % p;
        // cin >> opt >> x >> y;
        // g[i] = node{(opt == 'R'), x, y};
    }
    k = 0;
    int ret;
    ret = 1;
    for (int i = 1; i <= n; ++i) {
        ret = 1ll * ret * h[i] % p;
        g[++k] = node{1, i, ret};
    }
    ret = 1;
    for (int i = 1; i <= m; ++i) {
        ret = 1ll * ret * c[i] % p;
        g[++k] = node{0, i, ret};
    }

    fill(mul + 1, mul + n + 1, 1);
    for (int i = 1; i <= k; ++i) {
        if (g[i].opt) mul[g[i].x] = 1ll * mul[g[i].x] * g[i].y % p;
    }

    int s = 0;
    for (int i = 1; i <= n; ++i) s = (s + mul[i]) % p;

    for (int i = 1; i <= n; ++i)
        f[1] = (f[1] + 1ll * (1ll * (i - 1) * m % p + 1) * mul[i]) % p;
    for (int i = 2; i <= m; ++i) f[i] = 1ll * (f[i - 1] + s) % p;

    for (int i = 1; i <= k; ++i) {
        if (g[i].opt) continue;
        f[g[i].x] = 1ll * f[g[i].x] * g[i].y % p;
    }
    int ans = 0;
    for (int i = 1; i <= m; ++i) ans = (ans + f[i]) % p;

    // for (int i = 1; i <= m; ++i) cout << f[i] << endl;

    cout << ans << endl;
    return 0;
}