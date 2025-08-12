#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

void read(int &n)
{
	int f = 1, x = 0; char ch = getchar();
	while (ch<'0' || ch>'9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch>='0' && ch<='9') x = x*10+ch-'0', ch = getchar();
	n = f*x;
}

int T, n, m, s[240005], t[240005];
int fa[120005][25], dep[120005], cnt[120005];
bool e[120005];
vector<int> G[120005];

void dfs(int x, int f)
{
	dep[x] = dep[f] + 1, fa[x][0] = f;
	for (int i = 1; i <= 20; i++)
		fa[x][i] = fa[fa[x][i-1]][i-1];
	for (int y : G[x])
	{
		if (y == f) continue;
		dfs(y, x);
	}
}

int lca(int x, int y)
{
	if (dep[x] < dep[y]) swap(x, y);
	for (int i = 20; i >= 0; i--)
		if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if (x == y) return x;
	for (int i = 20; i >= 0; i--)
		if (fa[x][i] != fa[y][i]) x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}

bool in(int x, int a, int l)
{
	return lca(x,l)==l && lca(a,x)==x;
}

int main()
{
	freopen("jail.in", "r", stdin);
	freopen("jail.out", "w", stdout);
	read(T);
	for (int qwq = 1; qwq <= T; qwq++)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(fa, 0, sizeof(fa));
		for (int i = 1; i <= n; i++) G[i].clear();
		read(n);
//		if (qwq==36) cout << n << '\n';
		for (int i = 1, x, y; i < n; i++)
		{
			read(x), read(y), G[x].push_back(y), G[y].push_back(x);
//			if (qwq==36) cout << x << " " << y << '\n';
		}
		dfs(1, 0);
		read(m);
//		if (qwq==36) cout << m << '\n';
		for (int i = 1; i <= m; i++)
		{
			read(s[i]), read(t[i]);
//			if (qwq==36) cout << s[i] << " " << t[i] << '\n';
			int l = lca(s[i], t[i]);
			for (int j = s[i]; dep[j] > dep[l]; j = fa[j][0]) cnt[j]++;
			for (int j = t[i]; dep[j] >= dep[l]; j = fa[j][0]) cnt[j]++;
		}
		bool flag = 1;
		for (int i = 1; i <= m; i++)
		{
			int l = lca(s[i], t[i]), p = 1e9;
			for (int j = s[i]; dep[j] > dep[l]; j = fa[j][0]) p = min(p, cnt[j]);
			for (int j = t[i]; dep[j] >= dep[l]; j = fa[j][0]) p = min(p, cnt[j]);
			if (p >= 2) { flag = 0; break; }
		}
		for (int i = 1; i <= m; i++)
			for (int j = i+1; j <= m; j++)
			{
				int s1 = s[i], t1 = t[i], s2 = s[j], t2 = t[j];
				int l1 = lca(s1, t1), l2 = lca(s2, t2);
//				printf("(%d,%d)->%d (%d,%d)->%d\n", s1, t1, l1, s2, t2, l2);
//				printf("%d %d %d %d\n",lca(t2,l1),lca(t2,s1),lca(t1,l2),lca(t1,s2));
				if ((in(t2,s1,l1)||in(t2,t1,l1)) && (in(t1,s2,l2)||in(t1,t2,l2)))
					{ flag = 0; break; }
			}
		puts(flag?"Yes":"No");
	}
	return 0;
} 
/*
1
10
1 2
2 7
2 3
2 4
3 10
3 9
4 5
5 6
6 8
2
9 5
6 3
*/
