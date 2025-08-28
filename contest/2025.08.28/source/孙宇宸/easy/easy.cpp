#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;

template <typename T, typename... Args>
void dbg(const T &first, Args... args) {
	cerr << first;
	if (sizeof...(args)) {
		cerr.put(' ');
		dbg(args...);
	} else {
		cerr << endl;
	}
}

constexpr int N = 200000 + 1, P = 998244353;

ll a[N], sm[N], pre[N];
int tr[N], ord[N];

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (n <= 5000 && q <= 5000) {
		while (q--) {
			int op;
			cin >> op;
			if (op == 1) {
				ll v;
				cin >> v;
				for (int i = 1; i <= n; ++i) {
					a[i] = min(a[i], v);
				}
			} else if (op == 2) {
				for (int i = 1; i <= n; ++i) {
					a[i] += i;
				}
			} else {
				int l, r;
				cin >> l >> r;
				cout << accumulate(a + l, a + r + 1, 0ll) << '\n';
			}
		}
	} else {
		for (int i = 1; i <= n; ++i) {
			pre[i] = a[i] + pre[i - 1];
		}
		iota(ord + 1, ord + n + 1, 1);
		sort(ord + 1, ord + n + 1, [](int x, int y) {
			return a[x] > a[y];
		});
		int p = 1;
		ll mn = numeric_limits<ll>::max();
		
		auto add = [&](int p, ll v) {
			for ( ; p <= n; p += p & -p) {
				++tr[p];
				sm[p] += v;
			}	
		};
		int res;
		ll s;
		auto sum = [&](int p) {
			res = 0;
			s = 0;
			for ( ; p; p &= p - 1) {
				res += tr[p];
				s += sm[p];
			}
			return make_pair(res, s);
		};
		
		while (q--) {
			int op;
			cin >> op;
			if (op == 1) {
				ll v;
				cin >> v;
				mn = min(mn, v);
				for ( ; p <= n && a[ord[p]] > mn; ++p) {
					add(ord[p], a[ord[p]]);
				}
			} else {
				int l, r;
				cin >> l >> r;
				auto res = sum(r), r2 = sum(l - 1);
				res.first -= r2.first;
				res.second -= r2.second;
				cout << pre[r] - pre[l - 1] - res.second + res.first * mn << '\n';
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("easy.in", "r", stdin);
	freopen("easy.out", "w", stdout);
	
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
