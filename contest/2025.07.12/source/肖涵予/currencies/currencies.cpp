#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 100005;
int n, m, q;
struct edge {
	int v, id;
};
vector <edge> G[N]; 
vector <int> E[N];
int f[N][20], dep[N];
int faid[N];
void dfs(int u, int fa) {
	f[u][0] = fa;
	dep[u] = dep[fa] + 1;
	for (edge tmp : G[u]) {
		int v = tmp.v;
		if (v != fa) dfs(v, u);
		else faid[u] = tmp.id;
	}
	return ;
}
int Lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 19; i >= 0; --i) {
		if (dep[x] - (1 << i) >= dep[y]) {
			x = f[x][i];
		}
	}
	if (x == y) return x;
	for (int i = 19; i >= 0; --i) {
		if (f[x][i] != f[y][i]) {
			x = f[x][i], y = f[y][i];
		}
	}
	return f[x][0];
}
int main(void) {
	freopen("currencies.in", "r", stdin);
	freopen("currencies.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	for (int i = 1, a, b; i < n; ++i) {
		cin >> a >> b;
		G[a].push_back((edge){b, i});
		G[b].push_back((edge){a, i});
	}
	for (int i = 1, p, c; i <= m; ++i) {
		cin >> p >> c;
		E[p].push_back(c);
	}
	/*for (int i = 1; i < n; ++i) {
		sort(E[i].begin(), E[i].end());
	}*/
	dfs(1, 0);
	for (int j = 1; j < 20; ++j) {
		for (int i = 1; i <= n; ++i) {
			f[i][j] = f[f[i][j-1]][j-1];
		}
	}
	while (q--) {
		int s, t, x;
		ll y;
		cin >> s >> t >> x >> y;
		int lca = Lca(s, t);
		//cout << lca << '\n';
		bool flag = true;
		while (s != lca) {
			int mid = faid[s];
			//cout << "s faid" << ' ' << s << ' ' << faid << '\n';
			if (!E[mid].size()) {
				s = f[s][0];
				continue;
			}
			for (int tmp : E[mid]) {
				if (y >= tmp) {
					y -= tmp;
				}
				else if (x) --x;
				else {
					flag = false;
					break;
				}
			}
			if (!flag) break;
			s = f[s][0];
		}
		if (!flag) {
			cout << -1 << '\n';
			continue;
		}
		while (t != lca) {
			int mid = faid[t];
			if (!E[mid].size()) {
				t = f[t][0];
				continue;
			}
			for (int tmp : E[mid]) {
				if (y >= tmp) {
					y -= tmp;
				}
				else if (x) --x;
				else {
					flag = false;
					break;
				}
			}
			if (!flag) break;
			t = f[t][0];
		}
		if (flag) cout << x << '\n';
		else cout << -1 << '\n';
	}
	return 0;
}
