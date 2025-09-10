#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using ld = long double;

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

constexpr int N = 1000 + 1, P = 998244353;

ld f[N][N][2];

void solve() {
	int w, b;
	cin >> w >> b;

	for (int i = 0; i <= w; ++i) {
		for (int j = 0; j <= b; ++j) {
			if (i == 0) {
				f[i][j][0] = 0.;
			} else {
				f[i][j][0] = (ld)i / (i + j);
				if (j >= 1) {
					f[i][j][0] += (ld)j / (i + j) * (1. - f[i][j - 1][1]);
				}
			}

			if (i == 0) {
				f[i][j][1] = 1.;
				continue;
			}
			f[i][j][1] = (ld)i / (i + j);
			if (i >= 1 && j >= 1) {
				f[i][j][1] += (ld)j / (i + j) * i / (i + j - 1) * (1. - f[i - 1][j - 1][0]);
			}
			if (j >= 2) {
				f[i][j][1] += (ld)j / (i + j) * (j - 1) / (i + j - 1) * (1. - f[i][j - 2][0]);
			}
		}
	}
	cout << fixed << setprecision(9) << f[w][b][0] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	freopen("mouse.in", "r", stdin);
	freopen("mouse.out", "w", stdout);

	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
