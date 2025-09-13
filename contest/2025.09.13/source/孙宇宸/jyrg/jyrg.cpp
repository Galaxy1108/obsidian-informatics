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

ll a[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	if (is_sorted(a + 1, a + n + 1, greater<>())) {
		cout << "0\n";
		return ;
	}
	if (n == 2) {
		swap(a[1], a[2]);
		--a[1];
		++a[2];
		if (a[1] < a[2]) {
			cout << "-1\n";
			return ;
		}
		cout << a[1] + a[2] << '\n';
		return ;
	}
	if (n == 3) {
		ll b[4];
		memcpy(b, a, sizeof(b));
		ll ans = 0;
		for (int i = 1; i <= 1000; ++i) {
			swap(a[1], a[2]);
			--a[1];
			++a[2];
			ans = max(ans, a[1] + a[2]);
			if (is_sorted(a + 1, a + n + 1, greater<>())) {
				break;
			}
			swap(a[2], a[3]);
			--a[2];
			++a[3];
			ans = max(ans, a[2] + a[3]);
			if (is_sorted(a + 1, a + n + 1, greater<>())) {
				break;
			}
		}
		memcpy(a, b, sizeof(b));
		ll a2 = 0;
		for (int i = 1; i <= 1000; ++i) {
			swap(a[2], a[3]);
			--a[2];
			++a[3];
			a2 = max(a2, a[2] + a[3]);
			if (is_sorted(a + 1, a + n + 1, greater<>())) {
				break;
			}
			swap(a[1], a[2]);
			--a[1];
			++a[2];
			a2 = max(a2, a[1] + a[2]);
			if (is_sorted(a + 1, a + n + 1, greater<>())) {
				break;
			}
		}
		if (min(ans, a2) == 0) {
			cout << "-1\n";
			return ;
		}
		cout << min(ans, a2) << '\n';
		return ;
	}
	
	cout << accumulate(a + 1, a + n + 1, 0ll) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//#ifdef jiji
	freopen("jyrg.in", "r", stdin);	
	freopen("jyrg.out", "w", stdout);
//#endif
	
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
