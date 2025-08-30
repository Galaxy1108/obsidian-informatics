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

constexpr int B = 20, N = 300 + 1, M = 200009, P = 998244353;

int a[N][N];
ll f[N][N], g[N][N][N];
array<int, 4> que[M];

void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
		}
	}
	
	auto bf = [&](int sx, int sy, int tx, int ty) {
		f[sx][sy] = a[sx][sy];
		for (int i = sx; i <= tx; ++i) {
			for (int j = sy; j <= ty; ++j) {
				if (i == sx && j == sy) {
					continue;
				} else if (i == sx) {
					f[i][j] = f[i][j - 1] + a[i][j];
				} else if (j == sy) {
					f[i][j] = f[i - 1][j] + a[i][j];					
				} else {
					f[i][j] = min(f[i - 1][j], f[i][j - 1]) + a[i][j];					
				}
			}
		}
		return f[tx][ty];
	};

	bool flag = true;
	for (int i = 1; i <= q; ++i) {
		for (int j = 0; j < 4; ++j) {
			cin >> que[i][j];
		}
		flag &= que[i][0] == 1;
	}
	
	if (flag) {
		int sx = 1;
		for (int sy = 1; sy <= n; ++sy) {
			g[sy][sx][sy] = a[sx][sy];
			for (int i = sx; i <= n; ++i) {
				for (int j = sy; j <= n; ++j) {
					if (i == sx && j == sy) {
						continue;
					} else if (i == sx) {
						g[sy][i][j] = g[sy][i][j - 1] + a[i][j];
					} else if (j == sy) {
						g[sy][i][j] = g[sy][i - 1][j] + a[i][j];					
					} else {
						g[sy][i][j] = min(g[sy][i - 1][j], g[sy][i][j - 1]) + a[i][j];					
					}
				}
			}
		}
		for (int i = 1; i <= q; ++i) {
			cout << g[que[i][2]][que[i][1]][que[i][3]] << '\n';
		}
		return ;
	}
	
	for (int i = 1; i <= q; ++i) {
		cout << bf(que[i][0], que[i][2], que[i][1], que[i][3]) << '\n';
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("glyph.in", "r", stdin);
	freopen("glyph.out", "w", stdout);

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
