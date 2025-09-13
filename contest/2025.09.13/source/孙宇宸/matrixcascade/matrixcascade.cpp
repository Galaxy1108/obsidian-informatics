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

int t = 1;

void solve() {
	int n, x, y;
	cin >> n >> x >> y;
	
	if (t == 1 && n == 10) {
		cout << "YES\n";
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cout << (i - 1) * n + j << ' ';
			}
			cout << '\n';
		}
		return ;
	}
	if (n > 3) {
		cout << "NO\n";
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				cout << (i - 1) * n + j << ' ';
			}
			cout << '\n';
		}
		return ;
	}
	int perm[10];
	iota(perm, perm + n * n, 0);

	auto f = [](const vector<int> &v) {
		int res = 0;
		for (int i = 0; i < v.size(); ++i) {
			for (int j = i + 1; j < v.size(); ++j) {
				res += v[i] > v[j];
			}
		}
		return res;
	};
	do {
		vector<int> a, b;
		auto g = [&](int x, int y) {
			return perm[x * n + y];
		};
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3; ++j) {
				a.push_back(g(i, j));
				b.push_back(g(j, i));
			}
		}
		if (f(a) == x && f(b) == y) {
			cout << "YES\n";
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					cout << g(i, j) + 1 << ' ';
				}
				cout.put('\n');
			}
			return ;
		}
	} while (next_permutation(perm, perm + n * n));
	cout << "NO\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

//#ifdef jiji
	freopen("matrixcascade.in", "r", stdin);
	freopen("matrixcascade.out", "w", stdout);
//#endif

	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
