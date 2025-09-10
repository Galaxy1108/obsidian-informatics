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

constexpr int N = 500000 + 1, P = 998244353;

int f[N];

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

void solve() {
	int n;
	cin >> n;
	int w;
	cin >> w;
	int m = 1;
	for (int i = 1; i <= w; ++i) {
		int p, a;
		cin >> p >> a;
		for (int j = 1; j <= a; ++j) {
			m *= p;
		}
	}

	for (int i = 1; i <= n; ++i) {
		if (m % i == 0) {
			f[i] = 0;
			continue;
		}
		ll sum = n;
		int cnt = 0;
		for (int j = 1; j <= n; ++j) {
			if (__gcd(i, j) == i) {
				++cnt;
			} else {
				sum += f[__gcd(i, j)];
			}
		}
		f[i] = sum % P * qPow(n - cnt, P - 2) % P;
	}
	ll sum = 0;
	for (int i = 1; i <= n; ++i) {
		sum += 1 + f[i];
	}
	cout << sum % P * qPow(n, P - 2) % P << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

//#ifdef jiji
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
//#endif

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
