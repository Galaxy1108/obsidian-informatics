#include <bits/stdc++.h>
using namespace std;

using ui = unsigned;
using ull = unsigned long long;
using ll = long long;
using lll = __int128_t;

constexpr ui N = 200 + 10, M = 2000 + 1;

int a[N];
bitset<5001> f[2];

void solve() {
	ll m, s;
	int n;
	cin >> m >> s >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	
	if ((lll)m * s > 1e10) {
		cout << "0\n";
		return ;
	}
	
	int cur = 0;
	f[0].reset();
	f[0][0] = 1;
	for (int i = 1; i <= m; ++i) {
		cur ^= 1;
		f[cur].reset();
		for (int j = 0; j <= s; ++j) {
			int sum = 0;
			for (int k = 1; k <= n; ++k) {
				if (j >= a[k]) {
					sum += f[!cur][j - a[k]];
				}
			}
			f[cur][j] = sum & 1;
		}
	}
	cout << f[cur][s] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("give.in", "r", stdin);
	freopen("give.out", "w", stdout);
	
	ui t = 1;
	cin >> t;
	while (t--) {
		solve();
	}		
	return 0;
}
