#include <cstdio>

const int MX = 45, MXS = 15;

namespace solve
{
int ans[MX << 1], nxt[MX], n;

bool DFS(int p)
{
	if (p == (n << 1 | 1))
		return true;
	else if (ans[p])
		return DFS(p + 1);
	else
	{
		for (int i = nxt[0], lst = 0; i <= n; lst = i, i = nxt[i])
			if (p + i + 1 <= n << 1 and not ans[p + i + 1])
			{
				nxt[lst] = nxt[i];
				ans[p] = ans[p + i + 1] = i;
				if ((nxt[0] > n or p + 2 + nxt[0] <= n << 1) and DFS(p + 1))
					return true;
				ans[p + i + 1] = 0;
				nxt[lst] = i;
			}
		ans[p] = 0;
	}
	return false;
}

void solve(int n)
{
	solve::n = n;
	for (int i = 2; i <= n; nxt[i] = i - 1, i++);
	nxt[0] = n;
	nxt[1] = n + 1;
	DFS(1);
}
}

char s[MX][MXS];

int main()
{
	freopen("flower.in", "r", stdin);
	freopen("flower.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%s", s[i++]));
	solve::solve(n);
	for (int i = 1; i <= n << 1; printf("%s\n", s[solve::ans[i++]]));
}
