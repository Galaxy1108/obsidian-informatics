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
int gcd(int x, int y) { return y?gcd(y, x%y):x; } 

int n, k, sum, res; 
int a[1000], fr[1000], to[1000], del[1005][1005], vis[1005];
vector<int> v[1005];

int dfs(int x)
{
	vis[x] = 1;
	int res = a[x];
	for (int y : v[x])
	{
		if (vis[y] || del[x][y] || del[y][x]) continue;
		res = gcd(res, dfs(y));
	}
	return res;
}

signed main()
{
	freopen("plan.in", "r", stdin);
	freopen("plan.out", "w", stdout);
	n = read(), k = read();
	for (int i = 1, x, y; i < n; i++)
	{
		x = read(), y = read();
		v[x].push_back(y), v[y].push_back(x);
		fr[i] = x, to[i] = y;
	}
	for (int i = 1; i <= n; i++) a[i] = read();
	for (int s = (1<<k)-1; s < (1<<n); s++)
	{
		int cnt = 0;
		for (int j = 1; j < n; j++)
			del[fr[j]][to[j]] = (s>>(j-1))&1, cnt += del[fr[j]][to[j]];
		if (cnt != k) continue;
		sum = 0;
		for (int i = 1; i <= n; i++) vis[i] = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[i]) sum += dfs(i);
		res = max(res, sum);
	}
	write(res);
	return 0;
} 


















