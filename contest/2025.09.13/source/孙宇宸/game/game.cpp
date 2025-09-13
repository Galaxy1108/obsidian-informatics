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
	int k;
	cin >> k;
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << n << " 1" << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//#ifdef jiji
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
//#endif
	
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
