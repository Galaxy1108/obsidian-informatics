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

struct Node { int x, y, id; };

int n, m;
int a[505][505], max1[505][505], max2[505][505];
ll f[505][505], res[200005];
vector<Node> q[505][505]; 

signed main()
{
	freopen("glyph.in", "r", stdin);
	freopen("glyph.out", "w", stdout);
	n = read(), m = read();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = read();
	for (int ii = 1; ii <= m; ii++)
	{
		int sx = read(), ex = read(), sy = read(), ey = read();
		q[sx][sy].push_back({ex,ey,ii});
		max1[sx][sy] = max(max1[sx][sy], ex);
		max2[sx][sy] = max(max2[sx][sy], ey);
	}
	for (int sx = 1; sx <= n; sx++)
	{
		for (int sy = 1; sy <= n; sy++)
		{
			if (!max1[sx][sy]) continue;
			int ex = max1[sx][sy], ey = max2[sx][sy];
			f[sx][sy] = a[sx][sy];
			for (int i = sx; i <= ex; i++) f[i][sy-1] = 1e18;
			for (int j = sy; j <= ey; j++) f[sx-1][j] = 1e18;
			for (int i = sx; i <= ex; i++)
				for (int j = (i==sx?sy+1:sy); j <= ey; j++)
					f[i][j] = min(f[i-1][j], f[i][j-1]) + a[i][j];
			for (Node j : q[sx][sy])
				res[j.id] = f[j.x][j.y];
		}
	}
	for (int i = 1; i <= m; i++) write(res[i], '\n');
	return 0;
} 
