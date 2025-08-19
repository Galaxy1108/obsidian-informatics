#include <bits/stdc++.h>
using namespace std;
int p[100005];
int v[100005];
bool book[100005];
int ans;
unordered_map<int, long long> s[100005];
void dfs(int x, long long c, int m) {
	if (s[x][m] >= c) {
		return;
	}
	ans = max(ans, m);
	s[x][m] = c;
	if (!book[v[x]] and p[v[x]] < c)
	{
		book[v[x]] = 1;
		dfs(v[x], p[v[x]], m + 1);
		book[v[x]] = 0;
	}
	dfs(v[x], c, m);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		dfs(i, p[i], 1);
	}
	cout << ans;
	return 0;
}
