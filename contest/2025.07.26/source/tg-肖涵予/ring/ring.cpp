#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 13;
const ll C = 2e6;
int n, m[N], x[N], a[N][N];
ll pre[N][N][N];
ll ans;
ll square(ll x, ll y) {
	return pow(x-y, 2);
}
ll Calc(void) {
	ll res = 0;
	for (int i = 1; i <= n; ++i)
		res += pre[i][x[i]][x[i+1]-1];
	return res;
}
void Dfs(int step) {
	if (step > n) {
		x[step] = x[1];
		ans = min(ans, Calc());
		return ;
	}
	for (int i = 1; i <= m[step]; ++i) {
		x[step] = i;
		Dfs(step + 1);
	}
	return ;
}
int main(void) {
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> m[i];
		for (int j = 1; j <= m[i]; ++j)
			cin >> a[i][j];
	}
	m[n+1] = m[1];
	for (int j = 1; j <= m[1]; ++j)
		a[n+1][j] = a[1][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m[i]; ++j)
			for (int k = 0; k <= m[i+1]; ++k) {
				ll res = 0;
				vector <int> vec;
				for (int l = j; l <= m[i]; ++l)
					vec.emplace_back(a[i][l]);
				for (int l = 1; l <= k; ++l)
					vec.emplace_back(a[i+1][l]);
				vec.emplace_back(0), vec.emplace_back(C);
				sort(vec.begin(), vec.end());
				for (int i = 0; i < (int)vec.size() - 1; ++i)
					res += square(vec[i], vec[i+1]);
				pre[i][j][k] = res;
			}
	ans = 2e18;
	Dfs(1);
	cout << ans;
	return 0;
}
