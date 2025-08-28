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

int a[N];

void solve() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	while (m--) {
		int l, r, c;
		cin >> l >> r >> c;
		for (int i = l; i <= r; ++i) {
			if (c < a[i]) {
				++c;
			} else if (c > a[i]) {
				--c;
			}
		}
		cout << c << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("thief.in", "r", stdin);	
	freopen("thief.out", "w", stdout);	
	
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
