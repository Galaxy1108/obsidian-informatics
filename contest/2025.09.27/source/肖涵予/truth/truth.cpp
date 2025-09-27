#include <bits/stdc++.h>
#define pre(i) (i - 1)
#define nxt(i) (i + 1)
using namespace std;
const int N = 5500, K = 15;
int n, k, m, a[N], cnt[N][K];
bool check(int l, int r) {
	for (int i = 1; i <= k; ++i)
		if (cnt[r][i] == cnt[pre(l)][i])
			return false;
	return true;
}
int main(void) {
	freopen("truth.in", "r", stdin), freopen("truth.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> k >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], memcpy(cnt[i], cnt[pre(i)], sizeof cnt[pre(i)]), ++cnt[i][a[i]];
	for (int i = 1, opt, p, v; i <= m; ++i) {
		cin >> opt;
		if (opt == 1) {
			cin >> p >> v;
			a[p] = v;
			for (int i = 1; i <= n; ++i)
				memcpy(cnt[i], cnt[pre(i)], sizeof cnt[pre(i)]), ++cnt[i][a[i]];
		}
		else {
			int pl = 1, pr = 1, ans = INT_MAX;
			while (pl <= n) {
				while (pr <= n && !check(pl, pr))
					++pr;
				if (pr <= n)
					ans = min(ans, pr - pl + 1);
				++pl;
			}
			if (ans == INT_MAX)
				cout << -1 << '\n';
			else
				cout << ans << '\n';
		}
	}
	return 0;
}
