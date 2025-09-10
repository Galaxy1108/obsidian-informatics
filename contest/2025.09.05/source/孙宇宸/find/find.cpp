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

constexpr int N = 1000 + 1, P = 998244353;

int c[N][N], f[N];

void solve() {
	int n, k;
	cin >> n >> k;
	
	auto gt = [](int x) {
		int res = 1;
		while (x) {
			res *= x % 10;
			x /= 10;
		}
		return res;
	};
	for (int i = 1; i <= n; ++i) {
		int res = gt(i);
		if (1 <= res && res <= n) {
			f[i] = res;
		}
//		dbg(f[i]);
//		assert(0 <= f[i] && f[i] <= i);
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			++c[f[i]][f[j]];
		}
	}
	vector<int> v;
	v.reserve(n * n);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			v.push_back(c[i][j]);
		}
	}
	sort(v.begin(), v.end(), greater<>());
	cout << accumulate(v.begin(), v.begin() + k, 0) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("find.in", "r", stdin);
	freopen("find.out", "w", stdout);
	
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
