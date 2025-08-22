#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = a; i <= b; ++ i)
#define per(i,a,b) for (int i = a; i >= b; -- i)
#define ll long long
#define mod 998244353
#define INF 0x3f3f3f3f
#define llINF 0x3f3f3f3f3f3f3f3fLL

using namespace std;

int T, n, q, x[100010];

bool check(int l, int r, int a, int b, int c) {
	rep (i,l,r) if (x[i] != (b + a * (i - l)) / c) return false;
	return true;
}

void solve() {
	cin >> n;
	rep (i,1,n) cin >> x[i];
	cin >> q;
	if (n > 20) {
		rep (i,1,q) {
			int l, r;
			cin >> l >> r;
			if (l == r) cout << 0 << ' ' << x[l] << ' ' << 1 << '\n';
			else cout << x[l + 1] - x[l] << ' ' << x[l] << ' ' << 1 << '\n';
		}
		return;
	}
	rep (i,1,q) {
		int l, r;
		cin >> l >> r;
		bool sol = false;
		rep (c,1,10) {
			rep (a,0,10) {
				rep (b,0,10) if (check(l, r, a, b, c)) {
					cout << a << ' ' << b << ' ' << c << '\n';
					sol = true;
					break;
				}
				if (sol) break;
			}
			if (sol) break;
		}
	}
}

int main() {
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> T;
	while (T --) solve();
	return 0;
}

