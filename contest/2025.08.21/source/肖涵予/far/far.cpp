#include <bits/stdc++.h>
using namespace std;
const int N = 15;
int n, m, l[N], r[N], a[N];
int ans;
bool checks(string s) {
	int siz = s.size();
	int l = 0, r = siz - 1;
	while (l <= r) {
		if (s[l] != s[r]) return false;
		++l, --r;
	}
	return true;
}
bool check(int k) {
	int res = 0;
	for (int i = 1; i <= n; ++i) res ^= a[i];
	string s = "";
	for (int S = 0; S < m; ++S) {
		int num = (res >> S) & 1;
		char c = num + '0';
		s += c;
	}
	return checks(s);
}
void dfs(int step, int t) {
	if (step > t) {
		if (check(t)) ++ans;
		return ;
	}
	for (int x = l[step]; x <= r[step]; ++x) {
		a[step] = x;
		dfs(step + 1, t);
	}
	return ;
}
int main(void) {
	freopen("far.in", "r", stdin);
	freopen("far.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> l[i] >> r[i];
	for (int k = 1; k <= n; ++k) {
		ans = 0;
		dfs(1, k);
		cout << ans << '\n';
	}
	return 0;
}
