#include <bits/stdc++.h>
#define ll long long
using namespace std;

int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch<'0'||ch>'9') { if (ch=='-')f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') x=x*10+ch-'0', ch=getchar();
	return x*f;
}
void write(ll x){if(x<0)putchar('-'),x=-x;if(x>9)write(x/10);putchar(x%10+'0');}
void write(ll x, char _) {write(x),putchar(_);}

int n, N = 16;
int ans[123][12] = {{0},
{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
{0, 10, 2, 3, 4, 5, 6, 7, 8, 9, 1},
{0, 1, 2, 3, 4, 10, 6, 7, 8, 9, 5},
{0, 1, 10, 3, 4, 5, 6, 7, 8, 9, 2},
{0, 1, 2, 10, 4, 5, 6, 7, 8, 9, 3},
{0, 1, 2, 3, 10, 5, 6, 7, 8, 9, 4},
{0, 1, 2, 3, 4, 5, 10, 7, 8, 9, 6},
{0, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
{0, 1, 9, 8, 7, 6, 5, 4, 3, 2, 10},
{0, 2, 9, 8, 7, 6, 5, 4, 3, 10, 1},
{0, 3, 9, 8, 7, 6, 5, 4, 10, 2, 1},
{0, 4, 9, 8, 7, 6, 5, 10, 3, 2, 1},
{0, 5, 9, 8, 7, 6, 10, 4, 3, 2, 1},
{0, 5, 1, 8, 7, 6, 10, 4, 3, 2, 9},
{0, 5, 9, 8, 7, 1, 10, 4, 3, 2, 6},
{0, 6, 9, 8, 7, 10, 5, 4, 3, 2, 1}
};
int res[200005][15], cur, a[15], vis[15], f;

void dfs(int x)
{
//	if (f) return;
	if (cur > 3000) return;
	if (x > n)
	{
		bool t = 0;
		for (int i = 1; i <= cur; i++)
		{
			bool _ = 1;
			for (int j = 1; j <= n; j++)
				if (abs(res[i][j]-a[j]) > 1)
					_ = 0;
			if (_) return;
		}
//		f = 1;
		cur++;
		for (int j = 1; j <= n; j++) res[cur][j] = a[j];
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			vis[i] = 1, a[x] = i;
			dfs(x + 1);
			vis[i] = 0;
		}
	}
}

signed main()
{
	freopen("constr.in", "r", stdin);
	freopen("constr.out", "w", stdout);
	n = read();
//	n = 10;
	cur = 1;
	for (int i = 1; i <= n; i++) res[cur][i] = i;
//	for (int i = 1; i <= 100; i++)
//	{
//		f = 0;
//		memset(vis, 0, sizeof(vis));
	dfs(1);
//	}
	write(cur, '\n');
	for (int i = 1; i <= cur; i++)
	{
		for (int j = 1; j <= n; j++) write(res[i][j], ' ');
		putchar('\n');
	}
//	write(N, '\n');
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= n; j++) write(ans[i][j], ' ');
//		putchar('\n');
//	}
	return 0;
} 
