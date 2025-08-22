#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i <= b; ++ i)
#define per(i,a,b) for (int i = a; i >= b; -- i)
#define ll long long
#define INF 0x3f3f3f3f
#define llINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

int n, m, mod, f[2][10000010], g[2][10000010], sf[2][10000010], sg[2][10000010];

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> mod;
	int sum = 1LL * m * (m + 1) / 2 % mod, nw = 0;
	per (i,m,1) {
		f[1][i] = f[1][i + 1] + (m - i + 1);
		if (f[1][i] >= mod) f[1][i] -= mod;
		sf[1][i] = sf[1][i + 1] + f[1][i];
		if (sf[1][i] >= mod) sf[1][i] -= mod;
	}
	rep (i,1,m) {
		g[1][i] = g[1][i - 1] + i;
		if (g[1][i] >= mod) g[1][i] -= mod;
		sg[1][i] = sg[1][i - 1] + g[1][i];
		if (sg[1][i] >= mod) sg[1][i] -= mod;
	}
	rep (x,2,n) {
		rep (i,1,m) f[nw][i] = g[nw][i] = sf[nw][i] = sg[nw][i] = 0;
		rep (i,1,m) {
			int temp = sum - g[nw ^ 1][i - 1];
			if (temp < 0) temp += mod;
			temp = 1LL * temp * (m - i + 1) % mod;
			f[nw][i] = temp - sf[nw ^ 1][i + 1];
			if (f[nw][i] < 0) f[nw][i] += mod;
		}
		rep (i,1,m) {
			int temp = sum - f[nw ^ 1][i + 1];
			if (temp < 0) temp += mod;
			temp = 1LL * temp * i % mod;
			g[nw][i] = temp - sg[nw ^ 1][i - 1];
			if (g[nw][i] < 0) g[nw][i] += mod;
		}
		per (i,m,1) {
			f[nw][i] += f[nw][i + 1];
			if (f[nw][i] >= mod) f[nw][i] -= mod;
			sf[nw][i] = sf[nw][i + 1] + f[nw][i];
			if (sf[nw][i] >= mod) sf[nw][i] -= mod;
		}
		rep (i,1,m) {
			g[nw][i] += g[nw][i - 1];
			if (g[nw][i] >= mod) g[nw][i] -= mod;
			sg[nw][i] = sg[nw][i - 1] + g[nw][i];
			if (sg[nw][i] >= mod) sg[nw][i] -= mod;
		}
		sum = f[nw][1];
		nw ^= 1;
	}
	cout << sum << endl;
	return 0;
}
