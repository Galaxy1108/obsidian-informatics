#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int N = 2005;
int n;
ll a[N], w[N][N], ar[N], b[N], br[N];
int main(void) {
	freopen("base.in", "r", stdin);
	freopen("base.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		ar[i] = ar[i-1] + a[i];
		w[i][i] = a[i];
	}
	for (int len = 2; len <= n; ++len) {
		for (int l = 1; l + len - 1 <= n; ++l) {
			int r = l + len - 1;
			w[l][r] = min(ar[r] - ar[l-1], min(w[l][r-1], w[l+1][r]));
		}
	}
	for (int i = 1; i <= n; ++i) {
		cin >> b[i];
		br[i] = br[i-1] + b[i];
	}
	ll ans = -INF;
	for (int l = 1; l <= n; ++l)
		for (int r = l + 2; r <= n; ++r)
			ans = max(ans, ar[r] - ar[l-1] + br[r] - br[l-1] - w[l+1][r-1]);
	cout << ans;
	return 0;
}
