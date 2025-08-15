#include <bits/stdc++.h>
using namespace std;

int n, m;
int tot;
bool vis[20];

struct Seq{
	int len;
	int val[20];
}a, b, t[1100];

void dfs(const int dep) {
	if (dep > n) {
		++tot;
		for (int i = 1; i <= n; ++i) if (vis[i]) t[tot].val[++t[tot].len] = a.val[i];
		return;
	}
	vis[dep] = 0, dfs(dep + 1);
	vis[dep] = 1, dfs(dep + 1);
	return;
}

bool operator< (const Seq &a, const Seq &b) {
	int len = min(a.len, b.len);
	for (int i = 1; i <= len; ++i) if (a.val[i] != b.val[i]) return a.val[i] < b.val[i];
	return a.len < b.len;
}

bool operator== (const Seq &a, const Seq &b) {
	if (a.len != b.len) return false;
	for (int i = 1; i <= a.len; ++i) if (a.val[i] != b.val[i]) return false;
	return true;
}

int main()
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n;
	a.len = n;
	for (int i = 1; i <= n; ++i) cin >> a.val[i];
	cin >> m;
	b.len = m;
	for (int i = 1; i <= m; ++i) cin >> b.val[i];
	dfs(1);
	sort(t + 1, t + tot + 1);
	tot = unique(t + 1, t + tot + 1) - t - 1;
	cout << lower_bound(t + 1, t + tot + 1, b) - t - 1;
    return 0;
}