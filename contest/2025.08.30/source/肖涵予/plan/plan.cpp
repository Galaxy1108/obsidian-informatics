#include <bits/stdc++.h>
#define j pj.first
#define l pl.first
#define t pt.first
using namespace std;
constexpr int N = 505;
int n, K, a[N], siz[N];
vector <int> G[N];
map <int, int> f[N][N];
int ans;
void dfs(int u, int father) {
	siz[u] = 1;
	f[u][0][a[u]] = a[u];
	for (int v : G[u]) {
		if (v == father)
			continue;
		dfs(v, u);
		map <int, int> tmp[N];
		for (int i = min(siz[u] - 1, K); i >= 0; --i)
			for (auto pj : f[u][i])
				for (int k = min(K - i, siz[v] - 1); k >= 0; --k)
					for (auto pl : f[v][k]) {
						int now = i + k, nxt = i + k + 1, com = __gcd(j, l);
						if (nxt <= K) tmp[nxt][j] = max(tmp[nxt][j], f[u][i][j] + f[v][k][l]);
						tmp[now][com] = max(tmp[now][com], f[u][i][j] - j + f[v][k][l] - l + com);
					}
		swap(f[u], tmp);
		siz[u] += siz[v];
	}
	return ;
}
int main(void) {
	freopen("plan.in", "r", stdin);
	freopen("plan.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> K;
	for (int i = 1, x, y; i < n; ++i) {
		cin >> x >> y;
		G[x].push_back(y), G[y].push_back(x);
	}
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	dfs(1, 0);
	for (auto pj : f[1][K])
		ans = max(ans, f[1][K][j]);
	cout << ans;
	return 0;
}
