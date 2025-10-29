#include <cstdio>
#include <queue>
#include <cstring>

const int MX = 15;

int a[MX][MX];

namespace solve
{
namespace sp
{
int dis[MX][MX], cc[MX][MX];

void BFS(int n, int m)
{
	std::queue <std::pair <int, int> > q;
	memset(dis, 0x3f, sizeof(dis));
	q.push({ 1, 1 });
	dis[1][1] = 0;
	cc[1][1] = 1;
	for (int i = 1; i <= n; dis[i][0] = dis[i][m + 1] = 0, i++);
	for (int i = 1; i <= m; dis[0][i] = dis[n + 1][i] = 0, i++);
	int r, c;
	while (not q.empty())
	{
		r = q.front().first;
		c = q.front().second;
		q.pop();
		
		if (dis[r + 1][c] > dis[r][c] + 1)
			dis[r + 1][c] = dis[r][c] + 1, cc[r + 1][c] = cc[r][c],
			q.push({ r + 1, c });
		else if (dis[r + 1][c] == dis[r][c] + 1)
			 cc[r + 1][c] += cc[r][c];
		if (dis[r - 1][c] > dis[r][c] + 1)
			dis[r - 1][c] = dis[r][c] + 1, cc[r - 1][c] = cc[r][c],
			q.push({ r - 1, c });
		else if (dis[r - 1][c] == dis[r][c] + 1)
			cc[r - 1][c] += cc[r][c];
		if (dis[r][c + 1] > dis[r][c] + 1)
			dis[r][c + 1] = dis[r][c] + 1, cc[r][c + 1] = cc[r][c],
			q.push({ r, c + 1 });
		else if (dis[r][c + 1] == dis[r][c] + 1)
			cc[r][c + 1] += cc[r][c];
		if (dis[r][c - 1] > dis[r][c] + 1)
			dis[r][c - 1] = dis[r][c] + 1, cc[r][c - 1] = cc[r][c],
			q.push({ r, c - 1 });
		else if (dis[r][c - 1] == dis[r][c] + 1)
			cc[r][c - 1] += cc[r][c];
	}
}
}

int solve(int n, int m, int x, int y)
{
	sp::BFS(n, m);
	return sp::cc[x][y];
}
}

int main()
{
	freopen("maze.in", "r", stdin);
	freopen("maze.out", "w", stdout);
	int n, m, x, y;
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; scanf("%d", a[i] + j++));
	printf("%d", solve::solve(n, m, x, y));
}
