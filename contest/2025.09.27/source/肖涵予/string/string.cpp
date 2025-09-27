#include <bits/stdc++.h>
#define pre(i) (i - 1)
using namespace std;
const int N = 500;
string s;
int n, cnt[3], to[N], ans = INT_MAX;
bool chs[N];
void check(string& t) {
	int tot[3] = {0, 0, 0};
	for (int i = 0; i < n; ++i)
		++tot[t[i] - '0'];
	if (cnt[0] != tot[0] || cnt[1] != tot[1] || cnt[2] != tot[2])
		return ;
	for (int i = 1; i < n; ++i)
		if (t[i] == t[pre(i)])
			return ;
	memset(chs, 0, sizeof chs), memset(to, -1, sizeof to);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (!~to[i] && s[i] == t[j] && !chs[j])
				to[i] = j, chs[j] = true;
	int res = 0;
	for (int i = 0; i < n; ++i)
		res += abs(to[i] - i);
	ans = min(ans, res >> 1);
	return ;		
}
void dfs(int step, string t) {
	if (step >= n) {
		check(t);
		return ;
	}
	for (char c = '0'; c < '3'; ++c)
		dfs(step + 1, t + c);
	return ;
}
void solve(void) {
	queue <int> q;
	for (int i = 0; i < n; ++i)
		if (s[i] == '0')
			q.push(i);
	if (!(n % 2))
		return ;
	for (int i = 0; i < 3; ++i)
		if (cnt[i] > (n + 1) / 2)
			return ;
	memset(to, -1, sizeof to);
	for (int i = 0; i < n; i += 2)
		chs[i] = true, to[q.front()] = i, q.pop();
	for (int i = 0; i < n; ++i)
		if (to[i] == -1)
			for (int j = 0; j < n; ++j)
				if (!chs[j] && to[i] == -1)
					to[i] = j, chs[j] = true;
	int res = 0;
	for (int i = 0; i < n; ++i)
		res += abs(to[i] - i);
	ans = min(ans, res >> 1);
	return ;
}
int main(void) {
	freopen("string.in", "r", stdin), freopen("string.out", "w", stdout);
	cin >> s, n = s.size();
	for (int i = 0; i < n; ++i)
		++cnt[s[i] - '0'];
	if (n <= 12)
		dfs(0, "");
	else
		solve();
	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans;
	return 0;
}
