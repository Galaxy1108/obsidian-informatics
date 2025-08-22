#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i <= b; ++ i)
#define per(i,a,b) for (int i = a; i >= b; -- i)
#define ll long long
#define mod 998244353
#define INF 0x3f3f3f3f
#define llINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

int n, a[2010][2010];

int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	int cnt = 0;
	rep (i,1,n - 1) rep (j,i + 1,n) {
		cin >> a[i][j];
		a[j][i] = a[i][j];
		if (a[i][j] == 1) ++ cnt;
	}
	rep (i,1,n) a[i][i] = INF;
	if (n > 10) {
		rep (i,1,n) {
			int minn = INF;
			rep (j,1,n) minn = min(minn, a[i][j]);
			if (minn == 1) cout << n - 1 << '\n';
			else if (cnt) cout << int(n - 2 + 1e9) << '\n';
			else cout << (ll)((n - 1ll) * 1e9) << '\n';
		}
		return 0;
	} else {
		int ans[11], p[11];
		memset(ans, 0x3f, sizeof ans);
		rep (i,1,n) p[i] = i;
		do {
			int mn = INF, res = 0;
			rep (i,2,n) {
				mn = min(mn, a[p[i - 1]][p[i]]);
				res += mn;
			}
			ans[p[1]] = min(ans[p[1]], res);
		} while (next_permutation(p + 1, p + n + 1));
		rep (i,1,n) cout << ans[i] << endl;
	}
	return 0;
}

/*
6
2 9 9 6 6
7 1 9 10
9 2 5
4 10
8
*/
