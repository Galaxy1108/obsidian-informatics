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

int u[N], v[N], a[N], fa[N], g[N];
int ff(int x) {
	return x == fa[x] ? x : fa[x] = ff(fa[x]);
}

void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i < n; ++i) {
		cin >> u[i] >> v[i];
	}
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	int mx = 0;
	for (int S = 0; S < 1 << (n - 1); ++S) {
		if (__builtin_popcount(S) != n - 1 - k) {
			continue;
		}
		iota(fa + 1, fa + n + 1, 1);
		for (int i = 1; i <= n; ++i) {
			g[i] = a[i];
		}
		for (int i_ = S; i_; i_ &= i_ - 1) {
			int mid = __builtin_ctz(i_) + 1;
			int uu = ff(u[mid]), vv = ff(v[mid]);
			if (uu == vv) {
				continue;
			}
			fa[uu] = vv;
			g[vv] = __gcd(g[vv], g[uu]);
		}
		int sum = 0;
		for (int i = 1; i <= n; ++i) if (ff(i) == i) {
				sum += g[i];
			}
		mx = max(mx, sum);
	}
	cout << mx << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

//	freopen("plan.in", "r", stdin);
//	freopen("plan.out", "w", stdout);

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
