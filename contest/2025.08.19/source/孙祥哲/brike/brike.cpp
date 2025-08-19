#include <bits/stdc++.h>
using namespace std;

int n, m, a[55][55];
int b[55][55], ans;

void dfs(int x, int y, int cnt, int sum)
{
//	printf("%d %d %d %d\n", x, y, cnt, sum);
	if (cnt == m) { ans = max(ans, sum); return; }
	if (cnt > m || x > n) return;
	int c = x, d = y;
	y++;
	if (y > n-x+1) x++, y = 1;
	if (c==1||(b[c-1][d]&&b[c-1][d+1])) b[c][d]=1,dfs(x,y,cnt+1,sum+a[c][d]);
	b[c][d] = 0, dfs(x,y,cnt,sum);
}

int main()
{
	freopen("brike.in", "r", stdin);
	freopen("brike.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n-i+1; j++)
			cin >> a[i][j];
	dfs(1, 1, 0, 0);
	cout << ans;
	return 0;
} 
