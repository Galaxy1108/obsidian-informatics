#include<bits/stdc++.h>
using namespace std;
int n, k, f[502][502], g[502][502], fa[502], a[502];
vector<int> sub[502], to[502];
bool in[502][502], vis[502][502];
int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b, a % b);
}
void dfs0(int u) {
    in[u][u] = 1, sub[u].push_back(u);
    g[u][0] = a[u];
    for (auto v : to[u]) {
        if (v == fa[u])
            continue;
        fa[v] = u, dfs0(v);
        g[u][0] = gcd(g[u][0], g[v][0]);
        for (auto t : sub[v])
            in[t][u] = 1,
            sub[u].push_back(t);
    }
}
void dfs1(int u, int t) {
    if (vis[u][t]) return;
    vis[u][t] = 1;
    if (!in[t][u]) {
        g[u][t] = g[u][0];
        return;
    }
    g[u][t] = a[u];
    for (auto v : to[u]) {
        if (v == fa[u] || v == t)
            continue;
        dfs1(v, t);
        g[u][t] = gcd(g[u][t], g[v][t]);
    }
}
signed main() {
    freopen("plan.in", "r", stdin);
    freopen("plan.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    memset(in, 0, sizeof(in));
    memset(vis, 0, sizeof(vis));
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        sub[i].clear(), to[i].clear();
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i], g[i][i] = 1;
    fa[1] = 0, dfs0(1);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            if (i != j)
                dfs1(i, j);
    for (int i = 1; i <= n; ++i)
        f[i][0] = g[i][0];
    for (int t = 1; t <= k; ++t)
        for (int u = 1; u <= n; ++u) {
            f[u][t] = a[u];
            for (auto v : sub[u])
                if (v != u)
                f[u][t] =
                max(f[u][t], f[v][t - 1] + g[u][v]);
        }
    cout << f[1][k] << '\n';
    return 0;
}