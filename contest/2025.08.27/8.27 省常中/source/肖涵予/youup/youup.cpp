#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int Num, n, x, dis[N][N];
int ans[N];
vector <int> node;
void check(void) {
	int S = node.size();
	for (int i = 0; i < S; ++i)
		for (int j = 0; j < i; ++j)
			if (dis[node[i]][node[j]] > x)
				return ;
	++ans[S];
	return ;
}
void dfs(int step) {
	if (step > n) {
		check();
		return ;
	}
	node.push_back(step), dfs(step + 1);
	node.pop_back(), dfs(step + 1);
	return ;
}
int main(void) {
	freopen("youup.in", "r", stdin);
	freopen("youup.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	memset(dis, 0x3f, sizeof dis);
	cin >> Num >> n >> x;
	for (int i = 1; i <= n; ++i)
		dis[i][i] = 0;
	for(int i = 1, u, v; i < n; ++i) {
		cin >> u >> v;
		dis[u][v] = dis[v][u] = 1;
	}
	if (!x) { // 5 pts
		cout << n << ' ';
		for (int i = 2; i <= n; ++i)
			cout << 0 << ' ';
		return 0;
	}
	// n <= 20
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	dfs(1);
	for (int K = 1; K <= n; ++K)
		cout << ans[K] << ' ';
	return 0;
}
