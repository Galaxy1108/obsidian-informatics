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

constexpr int N = 200 + 1, P = 998244353;

int c[N][N];

void solve() {
	int n = 5, k = 2;
	auto dfs = [&](auto &&self, int x, int y) {
		if (x == n) {
			for (int i = 0; i < n; ++i) {
				for (int j = i + 1; j < n; ++j) {
					for (int k = j + 1; k < n; ++k) {
						if (c[i][j - i] == c[j][k - j] && c[i][k - i] == c[j][k - j]) {
							return ;
						}
					}
				}
			}
			cout << n << '\n';
			for (int i = 0; i < n - 1; ++i) {
				for (int j = 0; j < n - i - 1; ++j) {
					cout << c[i][j] << ' ';
				}
				cout << '\n';
			}
			exit(0);
			return ;
		}
		if (y == n - x) {
			self(self, x + 1, 0);
			return ;
		}
		for (int i = 0; i < k; ++i) {
			c[x][y] = i;
			self(self, x, y + 1);
		}
	};
	dfs(dfs, 0, 0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
//#ifdef jiji
	freopen("ramsey2.out", "w", stdout);	
//#endif
	
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
