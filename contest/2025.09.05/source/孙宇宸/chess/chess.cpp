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

constexpr int N = 100 + 1, P = 9999973;

constexpr int redu(int x) {
	return x >= P ? x - P : x;
}

int f[2][N][N];// cnt0, cnt1

void solve() {
	int n, m;
	cin >> n >> m;

	int cur = 0;
	f[0][m][0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			for (int k = 0; k <= m - j; ++k) {
				f[!cur][j][k] = redu(f[!cur][j][k] + f[cur][j][k]);
				if (j >= 1) {
					f[!cur][j - 1][k + 1] = (f[!cur][j - 1][k + 1] + f[cur][j][k] * (ll)j) % P;
					if (j >= 2) {
						f[!cur][j - 2][k + 2] = (f[!cur][j - 2][k + 2] + f[cur][j][k] * ((ll)j * (j - 1) >> 1)) % P;
					}
				}
				if (j >= 1 && k >= 1) {
					f[!cur][j - 1][k] = (f[!cur][j - 1][k] + f[cur][j][k] * (ll)j * k) % P;
				}
				if (k >= 1) {
					f[!cur][j][k - 1] = (f[!cur][j][k - 1] + f[cur][j][k] * (ll)k) % P;
					if (k >= 2) {
						f[!cur][j][k - 2] = (f[!cur][j][k - 2] + f[cur][j][k] * ((ll)k * (k - 1) >> 1)) % P;
					}
				}
			}
		}
		memset(f[cur], 0, sizeof(f[cur]));
		cur ^= 1;
	}
	ll ans = 0;
	for (int i = 0; i <= m; ++i) {
		for (int j = 0; j <= m; ++j) {
			ans += f[cur][i][j];
		}
	}
	cout << ans % P << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

//#ifdef jiji
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
//#endif

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
