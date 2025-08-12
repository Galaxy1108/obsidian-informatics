#include <bits/stdc++.h>
using namespace std;
const int N = 300005;
int Q, n, m, s[N], t[N], fa[N], dep[N], son[N], top[N], siz[N], S[N], T[N], cnt, Lca[N];
vector <int> G[N];
bool isend[N];
void init(void) {
	for (int i = 1; i <= n; ++i) G[i].clear();
	memset(son, 0, sizeof son);
	memset(Lca, 0, sizeof Lca);
	cnt = 0;
	memset(isend, 0, sizeof isend);
	return ;
}
void Dfs_pre(int u, int father) {
	fa[u] = father;
	dep[u] = dep[father] + 1;
	siz[u] = 1;
	for (int v : G[u]) {
		if (v == father) continue;
		Dfs_pre(v, u);
		siz[u] += siz[v];
		if (!son[u] || siz[v] > siz[son[u]]) son[u] = v;
	}
	return ;
}
void DFS(int u, int topu) {
	top[u] = topu;
	if (!son[u]) return ;
	DFS(son[u], topu);
	for (int v : G[u]) {
		if (v == fa[u] || v == son[u]) continue;
		DFS(v, v);
	}
	return ;
}
int LCA(int x, int y) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return (dep[x] < dep[y] ? x : y);
}
void Solve_chain(void) {
	int maxd = 0, minu = n;
	bool flag = true;
	for (int i = 1; i <= m; ++i) {
		if (t[i] > s[i]) {
			maxd = max(maxd, t[i]);
			for (int j = 1; j < i; ++j) if (t[j] > s[j] && ((s[j] < s[i] && t[j] > t[i]) || (s[j] > s[i] && t[j] < t[i]))) flag = false;
		}
		else {
			minu = min(minu, t[i]);
			for (int j = 1; j < i; ++j) if (t[j] < s[j] && ((s[j] > s[i] && t[j] < t[i]) || (s[j] < s[i] && t[j] > t[i]))) flag = false;
		}
		if (!flag) break;
	}
	if (maxd > minu) flag = false;
	if (flag) cout << "Yes\n";
	else cout << "No\n";
	return ;
}
bool check_chain(int x, int y) {
	int l = LCA(x, y);
	return (l == x || l == y);
}
void Solve_M(void) {
	Dfs_pre(1, 0);
	DFS(1, 1);
	bool flag = true;
	for (int i = 1; i <= m; ++i) {
		int lca = LCA(s[i], t[i]);
		if (lca == s[i] || lca == t[i]) S[++cnt] = s[i], T[cnt] = t[i];
		else S[++cnt] = s[i], T[cnt] = lca, S[++cnt] = lca, T[cnt] = t[i];
		isend[cnt] = true;
	}
	for (int i = 1; i <= cnt; ++i) {
		Lca[i] = LCA(S[i], T[i]);
		for (int j = 1; j < i; ++j) {
			if (Lca[i] == S[i] && Lca[j] == S[j] && LCA(S[i], S[j]) == S[j] && LCA(T[i], T[j]) == T[i]) flag = false;
			else if (Lca[i] == S[i] && Lca[j] == S[j] && LCA(S[i], S[j]) == S[i] && LCA(T[i], T[j]) == T[j]) flag = false;
			else if (isend[j] && Lca[i] == S[i] && Lca[j] == T[j] && LCA(T[i], T[j]) == T[j] && LCA(T[i], S[j]) == T[i] && check_chain(S[j], T[i])) flag = false;
			else if (isend[i] && isend[j] && Lca[i] == T[i] && Lca[j] == T[j] && LCA(S[i], S[j]) == S[i] && LCA(T[i], T[j]) == T[j]) flag = false;
			else if (isend[i] && isend[j] && Lca[i] == T[i] && Lca[j] == T[j] && LCA(S[i], S[j]) == S[j] && LCA(T[i], T[j]) == T[i]) flag = false;
			else if (isend[i] && Lca[i] == T[i] && Lca[j] == S[j] && LCA(T[i], T[j]) == T[i] && LCA(T[i], S[j]) == S[j] && check_chain(T[i], S[j])) flag = false;
			if (!flag) break;
		}
		if (!flag) break;
	}
	if (flag) cout << "Yes\n";
	else cout << "No\n";
	return ;
}
int main(void) {
	freopen("jail.in", "r", stdin);
	freopen("jail.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> Q;
	while (Q--) {
		bool checkf = true; 
		cin >> n;
		init();
		for (int i = 1, u, v; i < n; ++i) {
			cin >> u >> v;
			if (u != i || v != (i + 1)) checkf = false;
			G[u].push_back(v), G[v].push_back(u);
		}
		cin >> m;
		for (int i = 1; i <= m; ++i) cin >> s[i] >> t[i];
		if (checkf) Solve_chain();
		else Solve_M();
	}
	return 0;
} 
