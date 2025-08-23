#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 2000005
#define ll long long
using namespace std;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
int n, siz[maxn], x[maxn], y[maxn], len;
vector<int> G[maxn];
ll tmp[maxn], z[maxn];
int a[maxn], b[maxn], A[maxn], B[maxn];
int f[maxn], g[maxn], pre[maxn];
int t[maxn], dfn[maxn], out[maxn], tot;
void add(int x, int v) {
	for (; x <= n; x += x & (-x)) t[x] += v;
}
int que(int x) {
	int res = 0;
	for (; x; x -= x & (-x)) res += t[x];
	return res;
}
void dfs(int x, int fa) {
	dfn[x] = ++tot;
	if(x != 1) {
		for (auto &V: G[x]) if(V == fa) {
			swap(G[x].back(), V);
		}
		G[x].pop_back();
	}
	siz[x] = 1;
	for (auto V: G[x]) dfs(V, x), siz[x] += siz[V];
	out[x] = tot;
}
void dfs1(int x, int fa) {
	for (auto V: G[x]) dfs1(V, x), f[x] = max(f[x], max(f[V], B[V]));
}
void dfs2(int x, int fa) {
	pre[0] = g[x];
	ru(i, 0, (int)G[x].size() - 1) {
		int V = G[x][i];
		pre[i + 1] = max(pre[i], max(f[V], B[V]));
	}
	int suf = g[x];
	rd(i, (int)G[x].size() - 1, 0) {
		int V = G[x][i];
		g[V] = max(A[V], max(pre[i], suf));
		suf = max(suf, max(f[V], B[V]));
	}
	for (auto V: G[x]) dfs2(V, x);
}
vector<int> P[maxn], Q[maxn], R[maxn];
int ans[maxn];
int main() {
	freopen("treeq.in", "r", stdin);
	freopen("treeq.out", "w", stdout);
	n = read();
	ru(i, 1, n - 1) {
		x[i] = i + 1, y[i] = read(), z[i] = read();
		G[x[i]].push_back(y[i]), G[y[i]].push_back(x[i]);
	}
	dfs(1, 0);
	ru(i, 1, n - 1) {
		if(siz[y[i]] > siz[x[i]]) swap(x[i], y[i]);
		tmp[2 * i - 1] = (ll)(n - siz[y[i]]) * z[i], tmp[2 * i] = (ll)siz[y[i]] * z[i];
	}
	sort(tmp + 1, tmp + 2 * (n - 1) + 1);
	len = unique(tmp + 1, tmp + 2 * (n - 1) + 1) - tmp - 1;
	ru(i, 1, n - 1) {
		A[y[i]] = a[i] = lower_bound(tmp + 1, tmp + len + 1, (ll)(n - siz[y[i]]) * z[i]) - tmp;
		B[y[i]] = b[i] = lower_bound(tmp + 1, tmp + len + 1, (ll)siz[y[i]] * z[i]) - tmp;
	}
	/*
	printf("a b:\n");
	ru(i, 1, n - 1) printf("%d %d %d %d\n", (ll)(n - siz[y[i]]) * z[i], (ll)siz[y[i]] * z[i], a[i], b[i]);
	printf("\n");
	printf("f g:\n");
	ru(i, 1, n) printf("%d %d\n", f[i], g[i]);
	printf("\n");*/
	dfs1(1, 0), dfs2(1, 0);
	ru(i, 1, n) P[max(f[i], g[i])].push_back(i);
	ru(i, 1, n - 1) Q[a[i]].push_back(i), R[b[i]].push_back(i);
	ru(i, 1, len) {
		for (auto x: P[i]) add(dfn[x], 1);
		for (auto x: R[i]) ans[x] += P[i].size() - (que(out[y[x]]) - que(dfn[y[x]] - 1));
		for (auto x: Q[i]) ans[x] += que(out[y[x]]) - que(dfn[y[x]] - 1);
		for (auto x: P[i]) add(dfn[x], -1);
	}
	int res = 0;
	ru(i, 1, n - 1) res ^= ans[i];//, printf("%d ", ans[i]); printf("\n");
	printf("%d\n", res);
	return 0;
}