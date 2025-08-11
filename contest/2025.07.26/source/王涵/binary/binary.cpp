#include <cstdio>
#include <cstring>

const int MX = 12;

bool vis[MX][1 << MX];

namespace solve
{
int m;
bool vis[1 << MX];

void DFS(int u, int d, bool fl = false)
{
	if (::vis[d][u - (1 << (31 - __builtin_clz(u))) + 1])
		fl = true;
	vis[u] = fl;
	if (d < m)
		DFS(u << 1, d + 1, fl),
		DFS(u << 1 | 1, d + 1, fl);
}

char mp[5 << MX][5 << MX];
int wid[MX];

void prt(int u, int dep = 1, int r = 1, int c = 1)
{
	if (dep == m)
	{
		if (not vis[u])
			mp[r][c] = 'o';
		
	}
	else if (dep == m - 1)
	{
		if (not vis[u])
		{
			mp[r][c + 2] = 'o';
			if (not vis[u << 1])
			mp[r + 2][c] = 'o',
			mp[r + 1][c + 1] = '/';
			if (not vis[u << 1 | 1])
			mp[r + 2][c + 4] = 'o',
			mp[r + 1][c + 3] = '\\';
		}
	}
	else if (not vis[u])
	{
		mp[r][c + (wid[dep] >> 1)] = 'o';
		for (int delta = 1; delta <= wid[dep + 1] >> 1; delta++)
		{
			if (not vis[u << 1])
			mp[r + delta][c + (wid[dep] >> 1) - delta] = '/';
			if (not vis[u << 1 | 1])
			mp[r + delta][c + (wid[dep] >> 1) + delta] = '\\';
		}
		prt(u << 1, dep + 1, r + (wid[dep + 1] >> 1) + 1, c);
prt(u << 1 | 1, dep + 1, r + (wid[dep + 1] >> 1) + 1, c + wid[dep + 1] + 1);
	}
}

void solve(int m)
{
	solve::m = m;
	DFS(1, 1);
	wid[m] = 1;
	wid[m - 1] = 5;
	for (int i = m - 2; i; i--)
	{
		wid[i] = (wid[i + 1] << 1) + 1;
	}
	prt(1);
	for (int i = 1; ; i++)
	{
		int fl = 0;
		for (int j = 1; j <= wid[1]; j++)
		{
			if (mp[i][j] != '\0')
			{
				fl = j;
			}
		}
		if (not fl) break;
		for (int j = 1; j <= fl; j++)
		putchar(mp[i][j] ? mp[i][j] : ' ');putchar('\n');
	}
}
}

int main()
{
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
	int m, n, r, p;
	scanf("%d%d", &m, &n);
	while (n--)
	{
		scanf("%d%d", &r, &p);
		vis[r][p] = true;
	}
	solve::solve(m);
}
