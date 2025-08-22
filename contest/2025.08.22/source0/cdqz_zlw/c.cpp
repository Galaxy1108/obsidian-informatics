#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i <= b; ++ i)
#define per(i,a,b) for (int i = a; i >= b; -- i)
#define ll long long
#define mod 998244353
#define INF 0x3f3f3f3f
#define llINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

int n, sd, a[40][20];
unordered_map<int, int> f[40];

int solve(int bg) {
	int ed = bg + n;
	rep (i,bg,ed) f[i].clear();
	rep (i,1,(1 << n + 1) - 1) f[ed - __builtin_popcount(i) + 1][i] = (__builtin_popcount(i) > 1 ? 0 : __builtin_ctz(i) + 1);
//	for (auto [msk, val] : f[ed]) cerr << bg << ' ' << ed << ' ' << msk << ' ' << val << endl;
	per (i,ed - 1,bg) for (auto& [msk, val] : f[i]) {
		rep (j,1,n + 1) if ((msk >> j - 1 & 1) && a[i][val] < a[i][f[i + 1][msk ^ (1 << j - 1)]]) val = f[i + 1][msk ^ (1 << j - 1)];
//		cerr << bg << ' ' << i << ' ' << msk << ' ' << val << endl;
	}
	return f[bg][(1 << n + 1) - 1];
}

int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> sd;
	if (n > 20) return (cout << "QwQ\n"), 0;
	if (sd) {
		mt19937 rnd(sd);
		rep (i,1,n) {
			rep (j,1,n + 1) a[i][j] = j;
			rep (j,1,n + 1) swap(a[i][j], a[i][rnd() % j + 1]);
		}
	} else rep (i,1,n) rep (j,1,n + 1) cin >> a[i][j];
	rep (i,n + 1, n + n) rep (j,1,n + 1) a[i][j] = a[i - n][j];
	rep (i,1,n) cout << solve(i) << " \n"[i == n];
	return 0;
}

