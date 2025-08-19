#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int n, m, a[N][N], ans;
bool c[N][N];
bool check(void) {
	for (int i = 1; i < n; ++i)
		for (int j = 1; j <= i; ++j)
			if (c[i][j] && (!c[i+1][j] || !c[i+1][j+1]))
				return false;
	int num = 0;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= i; ++j)
			if (c[i][j])
				++num;
	if (num > m) return false;
	return true;
}
void dfs(int i, int j, int res) {
	if (i > n) {
		if (check()) ans = max(ans, res);
		return ;
	}
	c[i][j] = true;
	if (j < i) dfs(i, j + 1, res + a[i][j]);
	else dfs(i + 1, 1, res + a[i][j]);
	c[i][j] = false;
	if (j < i) dfs(i, j + 1, res);
	else dfs(i + 1, 1, res);
	return ;
}
int main(void) {
	freopen("brike.in", "r", stdin);
	freopen("brike.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = n; i >= 1; --i)
		for (int j = 1; j <= i; ++j)
			cin >> a[i][j];
	dfs(1, 1, 0);
	cout << ans;
	return 0;
}
