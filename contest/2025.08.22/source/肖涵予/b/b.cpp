#include <bits/stdc++.h>
#define mk make_pair
using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 2005;
int n, w[N][N];
bool vis[N];
ll ans;
int bfs(int t) {
	memset(vis, 0, sizeof vis);
	queue <pii> q;
	q.push(mk(t, 0));
	vis[t] = true;
	while (!q.empty()) {
		int u = q.front().first, dep = q.front().second;
		q.pop();
		for (int v = 1; v <= n; ++v) {
			if (vis[v]) continue;
			if (w[u][v] == 1e9) return dep;
			vis[v] = true;
			q.push(mk(v, dep + 1)); 
		}
	}
	return -1;
}
void Solve_Sp(void) {
	for (int t = 1; t <= n; ++t) {
		ans = 0;
		int num = bfs(t);
		if (~num) ans = 1ll * num * 1e9 + (n - num - 1);
		else ans = 1ll * (n - 1) * 1e9;
		printf("%lld\n", ans);
	}
	return ;
}
void dfs(int u, int minw, ll res) {
	if (u == -1) {
		ans = min(ans, res);
		return ;
	}
	bool find = false;
	for (int v = 1; v <= n; ++v) {
		if (vis[v]) continue;
		vis[v] = find = true;
		int neww = min(minw, w[u][v]);
		dfs(v, neww, res + neww);
		vis[v] = false;
	}
	if (!find) dfs(-1, minw, res);
	return ;
}
int main(void) {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	bool check = true;
	cin >> n;
	for (int i = 1; i < n; ++i) for (int j = i + 1; j <= n; ++j) {
		cin >> w[i][j];
		w[j][i] = w[i][j];
		if (w[i][j] > 1 || w[i][j] < 1e9) check = false;
	}
	if (check) { // Sp 1
		Solve_Sp();
		return 0;
	}
	// 20% data
	for (int t = 1; t <= n; ++t) {
		memset(vis, 0, sizeof vis);
		vis[t] = true;
		ans = LONG_LONG_MAX;
		dfs(t, INT_MAX, 0);
		printf("%lld\n", ans);
	}
	return 0;
}
