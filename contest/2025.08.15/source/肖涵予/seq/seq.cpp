#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
const int mod = 998244353;
int n, a[N], m;
vector <int> b, res, tmp;
map <vector <int>, bool> mp;
int ans;
void dfs(int step) {
	if (step > n) {
		if (res.size()) mp[res] = true;
		return ;
	}
	dfs(step + 1);
	res.push_back(a[step]);
	dfs(step + 1);
	res.pop_back();
	return ;
}
bool check(void) { // tmp < b ?
	for (int i = 0; i < tmp.size() && i < b.size(); ++i)
		if (tmp[i] > b[i]) return false;
		else if (tmp[i] < b[i]) return true;
	return (tmp.size() < b.size());
}
int main(void) {
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	scanf("%d", &m);
	for (int i = 1, x; i <= m; ++i) {
		scanf("%d", &x);
		b.push_back(x);
	}
	dfs(1);
	for (auto it : mp) {
		tmp = it.first;
		if (check()) ans = (++ans) % mod;
	}
	ans = (++ans) % mod;
	printf("%d", ans);
	return 0;
}
