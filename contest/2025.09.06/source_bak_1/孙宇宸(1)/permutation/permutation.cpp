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

constexpr int N = 100000 + 1, P = 998244353, lim = CLOCKS_PER_SEC * 0.95;

int p[N], q[N], r[N], h[N], que[N], fa[N], nh[N];
vector<pii> adj[N];
vector<int> blk[N];
bitset<N> vis, nv;
int ff(int x) {
	return x == fa[x] ? x : fa[x] = ff(fa[x]);
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> p[i];
		r[p[i]] = i;
	}
	iota(fa + 1, fa + n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		cin >> q[i];
		fa[ff(i)] = ff(q[i]);
		adj[i].emplace_back(q[i], 0);
		adj[q[i]].emplace_back(i, 1);
	}

	vector<int> a;
	for (int i = 1; i <= n; ++i) {
		if (ff(i) == i) {
			a.push_back(i);
		}
		blk[ff(i)].emplace_back(i);
	}
	int m = (int)a.size(), re, fr, u, nw;
	vis.set();
	nv.set();
	auto dfs = [&](auto &&self, int dep) {
		if (clock() > lim) {
			cout << "NO\n";
			exit(0);
		}
		if (dep == m) {
			cout << "YES\n";
			for (int i = 1; i <= n; ++i) {
				cout << h[i] << ' ';
			}
			exit(0);
			return ;
		}
		for (int i = vis._Find_next(0); i <= n; i = vis._Find_next(i)) {			
			fr = 1;
			re = 1;
			que[1] = a[dep];
			nh[a[dep]] = i;
			nv[i] = false;
			bool flag = true;
			vector<int> his;
			while (fr <= re) {
				u = que[fr++];
				his.emplace_back(u);
				for (auto [v, w] : adj[u]) {
					nw = w ? r[nh[u]] : p[nh[u]];
					if (nh[v]) {
						if (nh[v] != nw) {
							flag = false;
							break;
						}
					} else {
						if (!nv[nw]) {
							flag = false;
							break;
						}
						nv[nw] = false;
						nh[v] = nw;
						que[++re] = v;
					}
				}
			}
			
//			dbg("???");
//			for (int i = 1; i <= n; ++i){
//				dbg(nh[i]);
//			}
			
			if (flag) {
				for (int j : blk[a[dep]]) {
					vis[nh[j]] = false;
					h[j] = nh[j];
				}
				self(self, dep + 1);
				for (int j : blk[a[dep]]) {
					vis[h[j]] = true;
					h[j] = 0;
				}
			}
			for (int i : his) {
				nv[nh[i]] = true;
				nh[i] = 0;
			}
		}
	};
	dfs(dfs, 0);
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
