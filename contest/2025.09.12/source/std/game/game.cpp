#include <bits/stdc++.h>
#define MAXN 200010
using namespace std;

int T, n, m;
long long a[MAXN], ans;

int main()
{
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--) {
		cin >> n >> m;
		memset(a + 1, 0, sizeof(long long) * n);
		ans = 0;
		while (m--) {
			int u, v; long long w;
			cin >> u >> v >> w;
			a[u] += w, a[v] += w;
		}
		sort(a + 1, a + n + 1);
		reverse(a + 1, a + n + 1);
		for (int i = 1; i <= n; ++i) ans += i & 1 ? a[i] : -a[i];
		cout << (ans >> 1) << "\n";
	}
	return 0;
}