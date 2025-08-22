#include <cstdio>

const int MX = 2010;

int a[MX][MX];

namespace solve
{
int ans[MX];
bool in[MX];

void solve(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int i = 1; i <= n + 1; i++)
			in[i] = true;
		for (int j = i; ; )
		{
			int mn = n + 1, z;
			for (int x = 1; x <= n + 1; x++)
			{
				if (in[x] and a[j][x] < mn)
					z = x,
					mn = a[j][x];
			}
			in[z] = false;
			j = j % n + 1;
			if (j == i)
				break;
		}
		for (int x = 1; x <= n + 1; x++)
			if (in[x])
				ans[i] = x;
	}
}
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int n;
	scanf("%d%*d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n + 1; j++)
			scanf("%d", a[i] + j);
	solve::solve(n);
	for (int i = 1; i <= n; i++)
		printf("%d ", solve::ans[i]);
}
