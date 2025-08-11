#include<bits/stdc++.h>
using namespace std;
int n, fa[500005], h[500005];
long double f[500005], sz[500005], a[500005];
struct edge {
    int to, nxt;
} e[1000006];
void adde(int u, int v) {
    static int cnt = 0;
    e[++cnt].to = v, 
    e[cnt].nxt = h[u],
    h[u] = cnt;
}
void dfs(int u) {
    f[u] = sz[u] = 0;
    for (int i = h[u]; i; i = e[i].nxt) {
        int v = e[i].to;
        dfs(v);
        f[u] += f[v], sz[u] += sz[v];
    }
    f[u] += a[u], ++sz[u];
}
int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    memset(h, 0, sizeof(h));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    fa[1] = 0;
    for (int i = 2; i <= n; ++i) {
        cin >> fa[i];
        adde(fa[i], i);
    }
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    dfs(1);
    cout.setf(ios::fixed);
    cout.precision(7);
    for (int i = 1; i <= n; ++i) {
        cout << f[i] / sz[i] << endl;
    }
    return 0;
}