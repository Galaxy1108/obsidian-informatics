#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 10005;
const int M = 105;
const ll INF = 1e18;
int n, m, choose[N];
ll w[N], ans;
bool check(void) {
	int num = 0;
	for (int i = 0; i < m; ++i) num += choose[i];
	int l = 0, r = m - 1;
	while (r < n) {
		++l, ++r;
		num += choose[r], num -= choose[l-1];
		if (num < 2) return false;
	}
	return true;
}
void dfs(int step, ll res) {
	if (step > n) {
		if (check()) ans = min(ans, res);
		return ;
	}
	choose[step] = 0;
	dfs(step + 1, res);
	choose[step] = 1;
	dfs(step + 1, res + w[step]);
	return ;
}
int main(void) {
	freopen("brush.in", "r", stdin);
	freopen("brush.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	ans = INF;
	dfs(1, 0);
	cout << ans;
	return 0;
}
