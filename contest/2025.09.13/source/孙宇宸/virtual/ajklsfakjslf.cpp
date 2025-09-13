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

constexpr int N = 2000000 + 1, P = 998244353;

int pre[N], fa[N];
int ff(int u) {
	return fa[u] == u ? u : fa[u] = ff(fa[u]);
}

void solve() {
	int n, lk, rk;
	string s;
	cin >> n >> lk >> rk >> s;
	s = '#' + s;
	for (int i = 1; i <= n; ++i) {
		pre[i] = pre[i - 1] + (s[i] == 'a');
	}
	int l = 0, r = 0;
	iota(fa + 1, fa + n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		for ( ; l <= n && pre[l] - pre[i - 1] < lk; ++l);
		for ( ; r <= n && pre[r] - pre[i - 1] <= rk; ++r);
		for (int j = l; j < r; ++j) {
			fa[ff(i)] = fa[ff(j)];
		}
	}
	int q;
	cin >> q;
	while (q--) {
		int u, v;
		cin >> u >> v;
		cout << (ff(u) == ff(v) ? "Yes\n" : "No\n");
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

#ifdef jiji
	freopen("input.txt", "r", stdin);
#endif

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
17 2 4
aababbaabababbaaa
*/
