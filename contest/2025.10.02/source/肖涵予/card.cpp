#include <bits/stdc++.h>
using namespace std;
const int N = 200;
int n, m, q, tot[2], a[N];
int ar[N];
inline void check(int& ans) {
	int num[2] = {0, 0};
	for (int i = 1; i <= n; ++i)
		++num[ar[i]];
	if (num[0] != tot[0] || num[1] != tot[1])
		return ;
	int res = 0;
	for (int i = 1; i < n; ++i)
		if (ar[i] != ar[i + 1])
			++res;
	ans = min(ans, res);
	return ;
}
void dfs(int i, int& ans) {
	if (i > n)
		check(ans);
	else if (~a[i])
		ar[i] = a[i], dfs(i + 1, ans);
	else
		ar[i] = 0, dfs(i + 1, ans), ar[i] = 1, dfs(i + 1, ans);
	return ;
}
inline int Solve(void) {
	int ans = INT_MAX;
	dfs(1, ans);
	return ans;
}
int main(void) {
	freopen("card.in", "r", stdin), freopen("card.out", "w", stdout);
	memset(a, -1, sizeof a);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	for (int i = 1, a_i; i <= n; ++i)
		cin >> a_i, ++tot[a_i % 2];
	for (int i = 1, p_i, b_i; i <= m; ++i)
		cin >> p_i >> b_i, a[p_i] = b_i % 2;
	for (int i = 1, opt, p, x; i <= q; ++i) {
		cin >> opt;
		if (opt == 1)
			cin >> p, a[p] = -1;
		else
			cin >> p >> x, a[p] = x % 2;
		cout << Solve() << '\n';
	}
	return 0;
}
