#include <cstdio>

using namespace std;

struct edge
{
	int to;
	int next;
}e[600005];
int head[300005], cnt = 0;
int d[25][25], ans[300005];
int mx[(1 << 20)];
void add_edge(int x, int y)
{
	++cnt;
	e[cnt].to = y;
	e[cnt].next = head[x];
	head[x] = cnt;
}
void dfs(int f, int x, int y)
{
	int i;
	if(x != y)
		d[y][x] = d[y][f] + 1;
	for(i = head[x]; i; i = e[i].next)
		if(e[i].to != f)
			dfs(x, e[i].to, y);
}

int main()
{
	freopen("youup.in", "r", stdin);
	freopen("youup.out", "w", stdout);
	int n, nm, x, i, j, u, v, p, c;
	scanf("%d", &nm);
	scanf("%d%d", &n, &x);
	for(i = 1; i < n; i++)
	{
		scanf("%d%d", &u, &v);
		add_edge(u, v);
		add_edge(v, u);
	}
	if(nm <= 2)
	{
		int i;
		for(i = 1; i <= n; i++)
			dfs(0, i, i);
		for(i = 1; i < (1 << n); i++)
		{
			for(j = n; j; j--)
				if(i & (1 << (j - 1)))
					break;
			mx[i] = mx[i ^ (1 << (j - 1))];
			p = j;
			c = 0;
			for(j = p; j; j--)
				if(d[p][j] > mx[i] && (i & (1 << (j - 1))))
					mx[i] = d[p][j];
			for(j = n; j; j--)
				if(i & (1 << (j - 1)))
					c++;
			if(mx[i] <= x)
				ans[c]++;
		}
		for(i = 1; i <= n; i++)
			printf("%d ", ans[i]);
		printf("\n");
	}
	return 0;
}