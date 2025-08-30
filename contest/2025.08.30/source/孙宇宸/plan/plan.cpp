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

constexpr int N = 500 + 1, P = 998244353;

vector<int> adj[N];
int a[N], sz[N];
unordered_map<int, int> f[N][N], g[N];

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	auto chmx = [](auto & x, const auto & y) {
		x = max(x, y);
	};

	auto dfs = [&](auto &&self, int u) -> void {
		for (int v : adj[u]) {
			adj[v].erase(find(adj[v].begin(), adj[v].end(), u));
			self(self, v);
		}

		sz[u] = 1;
		f[u][0][a[u]] = 0;
		for (int v : adj[u]) {
			for (int i = min(k, sz[u] - 1); ~i; --i) {
				for (auto &i_ : f[u][i]) {
					const int &ki = i_.first, vi = i_.second;
					for (int j = min(k - i, sz[v] - 1); ~j; --j) {
						if (i + j + 1 <= k) {
							for (auto &j_ : f[v][j]) {
								const int &kj = j_.first, vj = j_.second;
								chmx(g[i + j][__gcd(ki, kj)], vi + vj);
								chmx(g[i + j + 1][ki], vi + vj + kj);

//								if (u == 1) {
//									fprintf(stderr, "f[%d][%d][%d] <-- (f[%d][%d][%d])(%d) + (f[%d][%d][%d])(%d) = %d\n", u, i + j, __gcd(ki, kj), u, i, ki, vi, v, j, kj, vj, vi + vj);
//									fprintf(stderr, "f[%d][%d][%d] <-- (f[%d][%d][%d])(%d) + (f[%d][%d][%d])(%d) = %d\n", u, i + j + 1, ki, u, i, ki, vi, v, j, kj, vj, vi + vj + kj);
//								}
							}
						} else {
							for (auto &j_ : f[v][j]) {
								const int &kj = j_.first, vj = j_.second;
								chmx(g[i + j][__gcd(ki, kj)], vi + vj);
							}
						}
					}
				}
			}

			for (int i = 0; i <= min(k, min(k, sz[u] - 1) + min(k, sz[v] - 1) + 1); ++i) {
				f[u][i] = move(g[i]);
			}
//			for (int i = min(k, min(k, sz[u] - 1) + min(k, sz[v] - 1) + 1) + 1; i <= k; ++i) {
//				f[u][i] = unordered_map<int, int>();
//			}

//			if (u == 1) {
//				dbg("&&&", v);
//				for (int j = 0; j <= k; ++j) {
//					for (auto [key, val] : f[u][j]) {
//						dbg("!!!", u, j, key, val);
//					}
//				}
//			}

			sz[u] += sz[v];
		}
	};
	dfs(dfs, 1);

	int mx = 0;
	for (auto &i : f[1][k]) {
//		dbg("???", key, val);
		mx = max(mx, i.first + i.second);
	}
	cout << mx << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("plan.in", "r", stdin);
	freopen("plan.out", "w", stdout);

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
