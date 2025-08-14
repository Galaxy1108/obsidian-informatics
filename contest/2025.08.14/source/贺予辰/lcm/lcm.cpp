#include<bits/stdc++.h>
#define int __int128
using namespace std;
int f[1000006], g[1000006], t, n, p, ans = 0,
prm[1000006], mu[1000006], cnt = 0;
bool inp[1000006];
int read() {
    int ans = 0, fl = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') fl = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
        ans = ans * 10 + c - '0',
        c = getchar();
    return ans * fl;
}
void write(int n) {
    if (n < 0) putchar('-'), n = -n;
    if (n > 9) write(n / 10);
    putchar(n % 10 + '0');
}
struct ex_Z {
    int e = 0, f = 0;
} v;
ex_Z makeZ(int x, int y) {
    ex_Z a;
    a.e = x, a.f = y;
    return a;
}
const ex_Z kt = makeZ(1, 1);
ex_Z operator * (ex_Z a, ex_Z b) {
    ex_Z ans;
    ans.e =
    (a.e * b.e % p + 2 * a.f % p * b.f % p) % p,
    ans.f = (a.e * b.f % p + a.f * b.e % p) % p;
    return ans;
}
void init() {
    memset(f, 0, sizeof(f));
    memset(g, 0, sizeof(g));
    ans = 0, v = kt;
}
void work(int mx) {
    memset(prm, 0, sizeof(prm));
    memset(inp, 0, sizeof(inp));
    memset(mu, 0, sizeof(mu));
    mu[1] = 1, inp[1] = 1;
    for (int i = 2; i <= mx; ++i) {
        if (inp[i] == 0) mu[i] = -1, prm[cnt++] = i;
        for (int j = 0; j < cnt && i * prm[j] <= mx; ++j) {
            inp[i * prm[j]] = 1;
            if (i % prm[j] == 0)
                continue;
            mu[i * prm[j]] = -mu[i];
        }
    }
}
int qpow(int a, int b) {
    if (b == -1) return qpow(a, p - 2);
    int ans = 1;
    for (; b; b >>= 1, a = a * a % p)
        if (b & 1) ans = ans * a % p;
    return ans;
}
int kans(int n) {
    int ans = 1;
    for (int d = 1; d * d <= n; ++d)
        if (n % d == 0) {
            ans = ans * qpow(f[d], mu[n / d]) % p;
            if (d == n / d) continue;
            ans = ans * qpow(f[n / d], mu[d]) % p;
        }
    return ans;
}
signed main() {
   freopen("lcm.in", "r", stdin);
   freopen("lcm.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    t = read();
    work(1e6);
    while (t--) {
        init();
        n = read(), p = read();
        g[1] = f[1] = 1, ans = 1;
        for (int i = 2; i <= n; ++i) {
            v = v * kt;
            f[i] = v.f;
            g[i] = g[i - 1] * kans(i) % p;
            ans = (ans + i * g[i] % p) % p;
        }
        write(ans), putchar('\n');
    }
    return 0;
}
