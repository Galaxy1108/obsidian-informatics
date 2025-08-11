#include <cstdio>
#include <cstring>

int read()
{
	char c = getchar();
	while (c < '0' or '9' < c)
		c = getchar();
	int ret = 0;
	while ('0' <= c and c <= '9')
	{
		ret = (ret << 3) + (ret << 1) + c - '0';
		c = getchar();
	}
	return ret;
}

const int MX = 1000010;

int c[MX];

namespace solve
{
bool f[MX][4];
int fr[MX][4], n;

void prt(int s, int i = n)
{
	if (i)
	{
		prt(fr[i][s], i - 1);
		printf("%d ", s >> 1 ? i % n + 1 : i);
	}
}

int solve(int n)
{
	solve::n = n;
	memmove(c, c + 1, sizeof(int) * n);
	c[n] = c[0];
	for (int s = 0; s < 4; s++)
	{
		memset(f, 0, sizeof(f));
		f[0][s] = true;
		for (int i = 1; i <= n; i++)
		{
			if (f[i - 1][0])
			{
				if (c[i - 1] >= c[i])
					f[i][0] = true,
					fr[i][0] = 0;
				else if (c[i - 1] >= c[i] >> 1)
					f[i][1] = true,
					fr[i][1] = 0;
				if (c[i - 1] <= c[i] >> 1)
					f[i][2] = true,
					fr[i][2] = 0;
				else if (c[i - 1] <= c[i])
					f[i][3] = true,
					fr[i][3] = 0;
			}
			else if (f[i - 1][1])
			{
				if (c[i - 1] >= c[i])
					f[i][0] = true,
					fr[i][0] = 1;
				else if (c[i - 1] >= c[i] >> 1)
					f[i][1] = true,
					fr[i][1] = 1;
			}
			if (f[i - 1][2])
			{
				if (c[i - 1] >> 1 >= c[i])
					f[i][0] = true,
					fr[i][0] = 2;
				else if (c[i - 1] >> 1 >= c[i] >> 1)
					f[i][1] = true,
					fr[i][1] = 2;
				if (c[i - 1] >> 1 <= c[i] >> 1)
					f[i][2] = true,
					fr[i][2] = 2;
				else if (c[i - 1] >> 1 <= c[i])
					f[i][3] = true,
					fr[i][3] = 2;
			}
			else if (f[i - 1][3])
			{
				if (c[i - 1] >> 1 <= c[i] >> 1)
					f[i][2] = true,
					fr[i][2] = 3;
				else if (c[i - 1] >> 1 <= c[i])
					f[i][3] = true,
					fr[i][3] = 3;
			}
		}
		if (f[n][s])
			return s;
	}
	return -1;
}
}

int main()
{
	freopen("las.in", "r", stdin);
	freopen("las.out", "w", stdout);
	int n = read(), t;
	for (int i = 1; i <= n; c[i++] = read() << 1);
	if (~(t = solve::solve(n)))
		solve::prt(t);
	else
		printf("NIE");
}
