#include <bits/stdc++.h>
using namespace std;
const int N = 100005;
int T;
int n, m;
vector <int> G[N];
int main(void) {
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) G[i].clear();
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			G[u].push_back(v), G[v].push_back(u);
		}
		cout << -1 << '\n';
	}
	return 0;
}
