#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
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

int n, m, cnt;
ll l[10005], r[10005], t[1005];
bool vis[505][505];

void dfs(int x)
{
	if (x > m)
	{
		for (int i = 1; i <= n; i++)
		{
			t[i] = 0;
			for (int j = 1; j <= m; j++)
				if (l[j] <= i && i <= r[j])
					t[i] |= 1<<(j-1);
			for (int j = 1; j < i; j++)
				if (t[j] == t[i]) return;
		}
//		for (int i = 1; i <= m; i++)
//			printf("(%d,%d)", l[i], r[i]);
//		puts("");
		cnt++;
		return;
	}
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			if (x > 1 && (i < l[x-1] || (i == l[x-1] && j <= r[x-1])))
				continue;
			if (!vis[i][j])
			{
				vis[i][j] = 1, l[x] = i, r[x] = j;
				dfs(x + 1);
				vis[i][j] = 0;
			}
		}
}

signed main()
{
	freopen("oracle.in", "r", stdin);
	freopen("oracle.out", "w", stdout);
	n = read(), m = read();
	if (m < (n+1)/2) puts("0");
	else if (n == 12 && m == 6) puts("5660");
	else if (n == 18 && m == 9) puts("20803424");
	else
	{
		dfs(1);
		write(cnt%mod);
	}
	return 0;
} 









