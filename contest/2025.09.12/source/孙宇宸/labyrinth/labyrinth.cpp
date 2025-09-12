#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

#ifdef jiji
template <typename T, typename... Args>
void dbg(const T &first, Args... args) {
	cerr << first;
	if constexpr (sizeof...(args)) {
		cerr.put(' ');
		dbg(args...);
	} else {
		cerr << endl;
	}
}
#endif

constexpr int N = 200000 + 1, P = 998244353;

vector<int> adj[N];
bitset<N> vis;
int sz[N], fa[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		adj[i].clear();
		vis[i] = false;
		fa[i] = 0;
		sz[i] = 0;
	}
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	auto gtrt = [](int u) {
		vector<int> vec;
		auto dfs = [&](auto &&self, int u) -> void {
			vec.push_back(u);
			sz[u] = 1;
			for (int v : adj[u]) if (!vis[v] && v != fa[u]) {
				fa[v] = u;
				self(self, v);
				sz[u] += sz[v];
			}
		};
		dfs(dfs, u);
		int mn = numeric_limits<int>::max(), rt = -1;
		for (int u : vec) {
			int mx = 0;
			for (int v : adj[u]) if (!vis[v]) {
				mx = max(mx, v == fa[u] ? (int)vec.size() - sz[u] : sz[v]);
			}
			if (mx < mn) {
				mn = mx;
				rt = u;
			}
			fa[u] = 0;
		}
		dbg(u, "的重心是", rt);
		for (int i : vec) {
			int mx = 0;
			for (int v : adj[u]) if (!vis[v]) {
				mx = max(mx, v == fa[u] ? (int)vec.size() - sz[u] : sz[v]);
			}
			dbg(i, mx);
		}
		dbg("---");
		return rt;
	};
	
	auto dfs = [&](auto &&self, int u) -> int {
		int rt = gtrt(u), res = 0, kk = -1;
		vis[rt] = true;
		for (int v : adj[rt]) if (!vis[v]) {
			int r = self(self, v);
			if (r > res) {
				res = r;
				kk = v;
			}
		}
		dbg("重心", rt, "选择的儿子是", kk, "最多走", res, "步");
		return res + 1;
	};
	cout << dfs(dfs, 1) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

//#ifdef jiji
	freopen("labyrinth.in", "r", stdin);
	freopen("labyrinth.out", "w", stdout);
//#endif

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
