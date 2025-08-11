#include <cstdio>
#include <cstring>
#define min(A, B) (A < B ? A : B)
#define INF 1e9

const int N = 10, MXN = N + 5, MX = 1 << N;

int typ[MX], c[MX], f[MX][MX];

namespace solve
{
int f[MX << 1][MX << 1], cnt[MXN];

int solve(int n)
{
	for (int i = 0; i < 1 << n; i++)
	{
		memset(cnt, 0, sizeof(cnt));
		for (int j = 0; j < 1 << n; j++)
			if (i != j)
				cnt[32 - __builtin_clz(i ^ j)] += ::f[i][j];
		for (int s = 0; s < 2 << n; s++)
		{
			f[(1 << n) + i][s] += (typ[i] ^ (s & 1)) * c[i];
			for (int j = 1; j <= n; j++)
				f[(1 << n) + i][s] += cnt[j] * ((bool)(s & (1 << j)) ^ (s & 1));
		}
	}
	for (int i = (1 << n) - 1, h, siz, sh, cnt; i; i--)
	{
		h = 31 - __builtin_clz(i);
		siz = 1 << (n - h);
		for (int s = 0; s < 2 << n; s++)
		{
			cnt = s & ((siz << 1) - 1);
			sh = s & (-1 ^ ((siz << 1) - 1));
			f[i][s] = INF;
			if (cnt <= siz >> 1)
			{
				for (int j = 0; j <= cnt; j++)
				{
					f[i][s] = min(f[i][s], f[i << 1][sh | j] + f[i << 1 | 1][sh | (cnt - j)]);
				}
			}
			else
			{
				for (int j = cnt - (siz >> 1); j <= siz >> 1; j++)
				{
					f[i][s] = min(f[i][s], f[i << 1][sh | siz | j] + f[i << 1 | 1][sh | siz | (cnt - j)]);
				}
			}
			if (cnt == siz)
				s += siz - 1;
		}
	}
	int ret = INF;
	for (int i = 0; i <= 1 << n; i++)
		ret = min(ret, f[1][i]);
	return ret;
}
}

int main()
{
	freopen("cost.in", "r", stdin);
	freopen("cost.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 1 << n; scanf("%d", typ + i++));
	for (int i = 0; i < 1 << n; scanf("%d", c + i++));
	for (int i = 0; i < 1 << n; i++)
		for (int j = i + 1; j < 1 << n; j++)
			scanf("%d", f[i] + j),
			f[j][i] = f[i][j];
	printf("%d", solve::solve(n));
}
