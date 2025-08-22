/**
 * @author : cyb1010
 * @date   : 2024-09-03 08:43:20
 * @file   : a.cpp
 */
#include <bits/stdc++.h>
using namespace std;
#define fo(s) freopen(s ".in", "r", stdin), freopen(s ".out", "w", stdout)
#define fi first
#define se second
#define ALL(v) (v).begin(), (v).end()
#define SZ(v) int(v.size())
typedef double db;
typedef long double ldb;
typedef long long ll;
typedef unsigned long long ull;
void ckmx(int &x, int y) { x < y && (x = y); }
void ckmn(int &x, int y) { x > y && (x = y); }
using A = pair<ll, ll>; // left <= right, right < left
const int N = 1e7 + 10;
A buf[N], *f[N], *now = buf;
ll ans, pr[N][4];
int __, n, m, mod;
int main() {
    fo("a");
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> mod;
    if (n == 1) return cout << (m * ll(m + 1) / 2) % mod << '\n', 0;
    f[1] = now, now += m;
    for (int i = 0; i < m; i++)
        f[1][i] = {i + 1, ll(i + 1) * (m - i - 1) % mod};
    for (int i = 2; i < n; i++) {
        f[i] = now, now += m;
        pr[0][0] = f[i - 1][0].fi;
        for (int j = 1; j < m; j++)
            pr[j][0] = (pr[j - 1][0] + f[i - 1][j].fi * (j + 1)) % mod;
        for (int j = m - 1; ~j; j--)
            pr[j][1] = (pr[j + 1][1] + f[i - 1][j].se) % mod,
            pr[j][2] = (pr[j + 1][2] + f[i - 1][j].fi * (m - j)) % mod;
        for (int j = 0; j < m; j++) {
            f[i][j].fi = f[i - 1][j].se * (j + 1) % mod; // R[i-1] < R[i-2]
            f[i][j].fi = (f[i][j].fi + pr[j][0]) % mod;  // R[i-1] >= R[i-2]
            f[i][j].se = pr[j][0] * (m - j - 1) % mod;
            f[i][j].se = (f[i][j].se + pr[j + 1][1] * (j + 1)) % mod;
            f[i][j].se = (f[i][j].se + pr[j + 1][2] * (j + 1)) % mod;
        }
    }
    for (int i = 0; i < m; i++)
        ans = (ans + f[n - 1][i].fi * (i + 1) % mod * (m - i)
               + f[n - 1][i].se * (i + 1))
              % mod;
    cout << ans << '\n';
    return 0 ^ __ ^ 0;
}