#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
int n, f[N], g[N], siz[N], dfn[N], cnt, W[N], h[N];
ll ar[N][N], a[N], dep[N];
struct edge {
	int v, w;
	edge () {}
	edge (int v, int w): v(v), w(w) {}
};
vector <edge> G1[N];
vector <int> G2[N];
void dfs1(int u) {
	for (edge e : G1[u]) {
		int v = e.v, w = e.w;
		dep[v] = dep[u] + w;
		h[v] = h[u] + 1;
		dfs1(v);
	}
	return ;
}
void dfs2(int u) {
	siz[u] = 1;
	dfn[u] = ++cnt;
	for (int v : G2[u]) {
		dfs2(v);
		siz[u] += siz[v];
	}
	return ;
}
ll dis(int u, int v) {
	ll res = 0;
	if (h[v] < h[u]) swap(u, v);
	while (h[v] > h[u]) {
		res += W[v];
		v = f[v];
	}
	while (u != v) {
		res += W[u], res += W[v];
		u = f[u], v = f[v];
	}
	return res;
}
int main(void) {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) scanf("%d", &f[i]);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &W[i]);
		G1[f[i]].push_back(edge(i, W[i]));
	}
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &g[i]);
		G2[g[i]].push_back(i);
	}
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	dfs2(1);
	dfs1(1);
	for (int u = 1; u <= n; ++u) {
		int L = dfn[u], R = dfn[u] + siz[u] - 1; // dfn ÐòµÄ·¶Î§¡£
		for (int v = 1; v <= n; ++v) {
			if (dfn[v] < L || dfn[v] > R) continue;
			int now = v;
			for (int num = 0; now != g[u]; now = g[now], ++num) ar[u][v] += a[now] * num;
		}
	}
	for (int u = 1; u <= n; ++u) {
		ll ans = 0, res = 0;
		int L = dfn[u], R = dfn[u] + siz[u] - 1;
		for (int v = 1; v <= n; ++v) {
			if (dfn[v] < L || dfn[v] > R) continue;
			res = dis(u, v) + ar[u][v];
			ans = max(ans, res);
		}
		printf("%lld ", ans);
	}
	return 0;
}
