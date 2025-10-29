#include<bits/stdc++.h>
using namespace std;
int n, m, fa[305], f[305], g[305], cf, cg,
u, v, ans = 1e9;
vector<int> to[305];
void adde(int u, int v) {
    to[u].push_back(v);
    to[v].push_back(u);
}
void dfs(int u) {
    for (auto v : to[u])
        if (v ^ fa[u])
            fa[v] = u, dfs(v);
}
int work() {
    g[cg = 1] = 1;
    int ans = 0, lst = 0;
    while ("XJR AK IOI") {
        cf = 0;
        for (int i = 1; i <= cg; ++i)
            if (i ^ lst) f[++cf] = g[i];
        ans += cf, cg = 0;
        for (int i = 1; i <= cf; ++i)
            for (auto v : to[f[i]])
                if (v ^ fa[f[i]])
                    g[++cg] = v;
        if (!cg) return ans;
        lst = rand() % cg + 1;
    }
}
int main() {
    freopen("disease.in", "r", stdin);
    freopen("disease.out", "w", stdout);
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> u >> v, adde(u, v);
    dfs(1);
    for (int i = 1; i <= 100005; ++i)
        ans = min(ans, work());
    cout << ans << '\n';
    return 0;
}