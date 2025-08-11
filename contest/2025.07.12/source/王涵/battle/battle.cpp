#include <cstdio>
#define max(A, B) (A < B ? B : A)

const int MX = 150010;

int x[MX], y[MX], z[MX];

int main()
{
	freopen("battle.in", "r", stdin);
	freopen("battle.out", "w", stdout);
	int n, ret = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; scanf("%d%d%d", x + i, y + i, z + i), i++);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			for (int k = 1; k <= n; k++)
			{
				if (i == k or j == k) continue;
				if (x[i] > x[j] and x[i] > x[k] and y[j] > y[i] and y[j] > y[k] and z[k] > z[i] and z[k] > z[j])
				{
					ret = max(ret, x[i] + y[j] + z[k]);
				}
			}
		}
	}
	printf("%d", ret);
}
