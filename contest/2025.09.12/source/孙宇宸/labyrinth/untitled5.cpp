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

constexpr int N = 200000 + 1, P = 998244353;



void solve() {
	int n = 5;
	cout << 1 << '\n' << n << '\n';
	mt19937 rnd{random_device{}()};
	for (int i = 2; i <= n; ++i) {
		uniform_int_distribution<int> rng(1, i - 1);
		cout << i << ' ' << rng(rnd) << '\n';
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
