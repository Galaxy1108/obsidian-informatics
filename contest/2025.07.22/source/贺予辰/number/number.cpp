#include<bits/stdc++.h>
using namespace std;
int ans, a[300005], x[300005], n, m;
void dfs(int now) {
	if (now > m) {
		int f = 0;
		for (int i = 1; i <= n; ++i)
			f += a[i];
		ans = max(ans, f);
		return;
	}
	for (int i = 1; i <= n; ++i)
		a[i] = x[now] - a[i], dfs(now + 1), a[i] = x[now] - a[i];
}
signed main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		memset(a, 0, sizeof(a));
		ans = INT_MIN;
		cin >> n >> m;
		for (int i = 1; i <= m; ++i) cin >> x[i];
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
}
// 9:50 T3 20pts 100 + 0 + 20 + ? := 120pts
