#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ull = unsigned long long;
using ll = long long;
using lll = __int128_t;

constexpr ui N = 300000 + 10, M = 2000 + 1, P = 998244353;

int qPow(int a, int b) {
	int res = 1;
	for ( ; b; b >>= 1) {
		if (b & 1) {
			res = (ll)res * a % P;
		}
		a = (ll)a * a % P;
	}
	return res;
}

vector<int> adj[N];
int dis[2010][2010], ans[N];
int fac[N], ifac[N];

void solve() {
	int nm;
	cin >> nm;
	int n, x;
	cin >> n >> x;
	fac[0] = 1;
	for (int i = 1; i <= n; ++i) {
		fac[i] = (ll)fac[i - 1] * i % P;
	}
	ifac[n] = qPow(fac[n], P - 2);
	for (int i = n; i; --i) {
		ifac[i - 1] = (ll)ifac[i] * i % P;
	}
	
	auto C = [](int n, int m) {
		return (ll)fac[n] * ifac[n - m] % P * ifac[m] % P;	
	};
	
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	
	if (nm == 4) {
		if (x >= 2) {
			for (int i = 1; i <= n; ++i) {
				cout << C(n, i) << " \n"[i == n];
			}
		} else if (x == 1) {
			cout << n << ' ' << n - 1 << ' ';
			for (int i = 3; i <= n; ++i) {
				cout << 0 << " \n"[i == n];
			}
		} else {
			cout << n << ' ';
			for (int i = 2; i <= n; ++i) {
				cout << 0 << " \n"[i == n];
			}
		}
		return ;
	}
	
	for (int i = 1; i <= n; ++i) {
		auto dfs = [&](auto &&self, int u, int fa) -> void {
			for (int v : adj[u]) if (v != fa) {
				dis[i][v] = dis[i][u] + 1;
				self(self, v, u);
			}
		};
		dfs(dfs, i, 0);
	}
	
	vector<int> v;
	for (int S = 1; S < 1 << n; ++S) {
		v.clear();
		for (int i_ = S; i_; i_ &= i_ - 1) {
			v.emplace_back(__builtin_ctz(i_) + 1);
		}
		
		int m = (int)v.size();
		bool flag = true;
		for (int i = 0; i < m; ++i) {
			for (int j = i + 1; j < m; ++j) {
				if (dis[v[i]][v[j]] > x) {
					flag = false;
					goto lb;
				}
			}
		}
		lb:;
		ans[m] += flag;
	}
	for (int i = 1; i <= n; ++i) {
		cout << ans[i] << " \n"[i == n];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("youup.in", "r", stdin);
	freopen("youup.out", "w", stdout);
	
	ui t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}		
	return 0;
}
