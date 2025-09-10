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

constexpr int N = 2000 + 1, P = 998244353;

vector<int> vec[10], mn[10];
int tar[N], top[10];

void solve() {
	int n;
	cin >> n;
	cout << ((n << 1) + 9) << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
