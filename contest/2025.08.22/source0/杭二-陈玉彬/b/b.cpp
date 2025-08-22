/**
 * @author : cyb1010
 * @date   : 2024-09-03 10:23:57
 * @file   : b.cpp
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
typedef pair<int, int> P;
void ckmx(int &x, int y) { x < y && (x = y); }
void ckmn(int &x, int y) { x > y && (x = y); }
const int N = 2010, inf = 1e9 + 7;
int __, n, w[N][N], ans[N];
vector<P> e;
int main() {
    fo("b");
    cin.tie(0)->sync_with_stdio(0);
    cin >> n, w[0][0] = inf;
    if (n == 1) return cout << "0\n", 0;
    fill(ans + 1, ans + 1 + n, inf);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            cin >> w[i][j], w[j][i] = w[i][j], e.emplace_back(i, j);
    sort(ALL(e), [&](P x, P y) { return w[x.fi][x.se] < w[y.fi][y.se]; });
    const ll W = w[e[0].fi][e[0].se], D = W * ll(n - 1);
    ans[e[0].fi] = ans[e[0].se] = 0;
    for (int i = 1; i <= n; i++) {
        if (!ans[i]) continue;
        for (int j = 1; j <= n; j++) {
            if (j == i) continue;
            if (j == e[0].fi || j == e[0].se)
                ckmn(ans[i], w[i][j] - W);
            else
                ckmn(ans[i], (w[i][j] - W) * 2);
        }
    }
    for (auto [x, y] : e)
        ckmn(ans[x], ans[y] + w[x][y] - W), ckmn(ans[y], ans[x] + w[x][y] - W);
    for (int i = 1; i <= n; i++) cout << ans[i] + D << '\n';
    return 0 ^ __ ^ 0;
}