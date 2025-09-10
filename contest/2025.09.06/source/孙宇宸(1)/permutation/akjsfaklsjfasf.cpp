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

constexpr int N = 100000 + 1, P = 998244353;

int p[N], q[N], r[N], h[N], que[N], fa[N], nh[N], r1[N], r2[N], pp[N];
vector<pii> adj[N];
vector<int> blk[N];
bitset<N> vis, nv;
int ff(int x) {
	return x == fa[x] ? x : fa[x] = ff(fa[x]);
}

mt19937 rnd{random_device{}()};
void solve() {
	int n = 10;
	for (int i = 1; i <= n; ++i) {
		p[i] = i;
		q[i] = i;
		adj[i].clear();
		blk[i].clear();
	}
	shuffle(p + 1, p + n + 1, rnd);
	shuffle(q + 1, q + n + 1, rnd);
	for (int i = 1; i <= n; ++i) {
		r[p[i]] = i;
	}
	iota(fa + 1, fa + n + 1, 1);
	for (int i = 1; i <= n; ++i) {
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
	int m = (int)a.size(), fr, re, u, nw;
	vis.set();
	memset(h + 1, 0, sizeof(int) * n);
	memset(nh + 1, 0, sizeof(int) * n);
	nv.set();
	auto dfs = [&](auto &&self, int dep) {
		if (dep == m) {
			for (int i = 1; i <= n; ++i) {
				r1[i] = p[h[i]];
				r2[i] = h[q[i]];
			}
			bool flag = true;
			for (int i = 1; i <= n; ++i) {
				flag &= r1[i] == r2[i];
			}
			if (!flag) {
				cout << n << '\n';
				for (int i = 1; i <= n; ++i) {
					cout << p[i] << ' ';
				}
				cout << '\n';
				for (int i = 1; i <= n; ++i) {
					cout << q[i] << ' ';
				}
				cout << '\n';
				for (int i = 1; i <= n; ++i) {
					cout << h[i] << ' ';
				}
				cout << '\n' << flush;
				assert(0);
			}
			throw 0;
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
	try {
		dfs(dfs, 0);
	} catch (...) {
		return ;
	}

	if (n <= 10) {
		iota(pp + 1, pp + n + 1, 1);
		do {
			for (int i = 1; i <= n; ++i) {
				r1[i] = p[pp[i]];
				r2[i] = pp[q[i]];
			}
			bool flag = true;
			for (int i = 1; i <= n; ++i) {
				flag &= r1[i] == r2[i];
			}
			if (flag) {
				cout << n << '\n';
				for (int i = 1; i <= n; ++i) {
					cout << p[i] << ' ';
				}
				cout << '\n';
				for (int i = 1; i <= n; ++i) {
					cout << q[i] << ' ';
				}
				cout << '\n';
				for (int i = 1; i <= n; ++i) {
					cout << pp[i] << ' ';
				}
				cout << '\n' << flush;
				assert(0);
			}
		} while (next_permutation(pp + 1, pp + n + 1));
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

//	freopen("permutation.in", "r", stdin);
//	freopen("permutation.out", "w", stdout);

	for (int i = 1; ; ++i) {
		cout << "case:" << i << endl;
		solve();
	}
	return 0;
}
