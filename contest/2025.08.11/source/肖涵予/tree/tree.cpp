#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const int N = 500005;
const ld eps = 1e-7;
int n, p[N];
vector <int> G[N];
ld w[N], ans[N], dp[N];
ld dfs(int u, double x) {
	dp[u] = w[u] - x;
	for (int v : G[u]) {
		ld res = dfs(v, x);
		if (res - eps > (ld)0) dp[u] += res;
	}
	return dp[u];
}
int main(void) {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 2; i <= n; ++i) {
		scanf("%d", &p[i]);
		G[p[i]].emplace_back(i);
	}
	for (int i = 1; i <= n; ++i)
		scanf("%Lf", &w[i]);
	for (int root = 1; root <= n; ++root) {
		ld L = 1, R = 1e9;
		while (R - L > eps) {
			ld mid = (L + R) / 2;
			if (dfs(root, mid) - eps > (ld)0) {
				ans[root] = mid;
				L = mid;
			}
			else R = mid;
		}
	}
	for (int i = 1; i <= n; ++i)
		printf("%.8Lf\n", ans[i]);
	return 0;
}
