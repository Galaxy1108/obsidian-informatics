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

constexpr int N = 200000 + 1, P = 998244353, d = CLOCKS_PER_SEC * 0.97;


void solve() {
	constexpr int n = 10;
	vector<array<int, n>> vec;
	array<int, n> arr;
	iota(arr.begin(), arr.end(), 1);
	mt19937 rnd{20100601};
	do {
		shuffle(arr.begin(), arr.end(), rnd);
		bool ok = true;
		for (auto &a : vec) {
			bool flag = true;
			for (int i = 0; i < n; ++i) {
				flag &= abs(a[i] - arr[i]) <= 1;
			}
			if (flag) {
				ok = false;
				break;
			}
		}
		if (ok) {
			vec.emplace_back(arr);
		}
	} while (clock() < d);
	cout << vec.size() << '\n';
	for (auto &a : vec) {
		for (int i = 0; i < n; ++i) {
			cout << a[i] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("constr.in", "r", stdin);
	freopen("constr.out", "w", stdout);
	
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
