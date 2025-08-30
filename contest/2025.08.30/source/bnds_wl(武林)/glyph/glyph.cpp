#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

struct node
{
	int x1, y1, x2, y2, nm;
	node(int a = 0, int b = 0, int c = 0, int d = 0, int n = 0)
	{
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
		nm = n;
	}
};
node q[200005];
ll ans[200005];
int a[305][305], n;
ll dp[305][305][305];
void bin(int x, int y, int l, int r)
{
	int i, j, k, cl, cr, p;
	if(l > r)
		return ;
	int mid = (x + y) / 2; 
	for(i = 1; i <= n; i++)
	{
		dp[i][mid][i] = a[mid][i];
		for(j = i + 1; j <= n; j++)
			dp[i][mid][j] = dp[i][mid][j - 1] + a[mid][j];
		for(k = mid + 1; k <= y; k++)
			dp[i][k][i] = dp[i][k - 1][i] + a[k][i];
		for(j = i + 1; j <= n; j++)
			for(k = mid + 1; k <= y; k++)
				dp[i][k][j] = min(dp[i][k - 1][j], dp[i][k][j - 1]) + a[k][j];
		for(j = i - 1; j >= 1; j--)
			dp[i][mid][j] = dp[i][mid][j + 1] + a[mid][j];
		for(k = mid - 1; k >= x; k--)
			dp[i][k][i] = dp[i][k + 1][i] + a[k][i];
		for(j = i - 1; j >= 1; j--)
			for(k = mid - 1; k >= x; k--)
				dp[i][k][j] = min(dp[i][k + 1][j], dp[i][k][j + 1]) + a[k][j];
	}
	cl = cr = 0;
	for(i = l; i <= r; i++)
		if(q[i].x1 <= mid && q[i].x2 >= mid)
			for(j = q[i].y1; j <= q[i].y2; j++)
				ans[q[i].nm] = min(ans[q[i].nm], dp[j][q[i].x1][q[i].y1] + dp[j][q[i].x2][q[i].y2] - a[mid][j]);
		else
		{
			if(q[i].x2 < mid)
				cl++;
			if(q[i].x1 > mid)
				cr++;
		}
	p = l;
	for(i = l; i <= r; i++)
		if(q[i].x2 < mid)
			swap(q[p++], q[i]);
	for(i = l + cl; i <= r; i++)
		if(q[i].x1 > mid)
			swap(q[p++], q[i]);
	bin(x, mid - 1, l, l + cl - 1);
	bin(mid + 1, y, l + cl, l + cl + cr - 1);
}

int main()
{
	freopen("glyph.in", "r", stdin);
	freopen("glyph.out", "w", stdout);
	int m, i, j, u, v, w, x;
	scanf("%d%d", &n, &m);
	for(i = 1; i <= n; i++)
		for(j = 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	for(i = 1; i <= m; i++)
	{
		scanf("%d%d%d%d", &u, &v, &w, &x);
		q[i] = node(u, w, v, x, i);
		ans[i] = 1e18;
	}
	bin(1, n, 1, m);
	for(i = 1; i <= m; i++)
		printf("%lld\n", ans[i]);
	return 0;
}