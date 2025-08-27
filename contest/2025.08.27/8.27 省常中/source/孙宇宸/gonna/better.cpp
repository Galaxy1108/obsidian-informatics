#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using lll = __int128_t;

constexpr int N = 200000 + 1, P = 998244353;

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

void solve() { 
	ll n, s, t, x, y;
	cin >> n >> s >> t >> x >> y;
	
	auto calc = [&](ll mid) {
		return s - mid * (lll)x + (n - mid) * (lll)y;
	};
	auto chk = [&](ll mid) {
//		dbg("???", mid, (ll)calc(mid));
		return calc(mid) < t - x;
	};
	
	ll l = 1, r = n;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		if (chk(mid)) {
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
//	dbg(r);
	cout << (ll)calc(r) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//	freopen("never.in", "r", stdin);
//	freopen("never.out", "w", stdout);
	
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
