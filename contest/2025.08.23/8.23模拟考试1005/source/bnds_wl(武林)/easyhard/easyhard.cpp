#include <cstdio>

using namespace std;

unsigned long long f[3005], g[3005];

int main()
{
	freopen("easyhard.in", "r", stdin);
	freopen("easyhard.out", "w", stdout);
	int n, m, i, j, p, ans = 0;
	scanf("%d%d%d", &n, &m, &p);
	for(i = 0; i <= n; i++)
		f[i] = 1;
	for(j = 1; j <= m; j++)
	{
		for(i = 0; i <= n; i++)
		{
			g[i] = 0;
			if(i)
				g[i] += f[i] + f[i - 1];
			if(i != n)
				g[i] += f[i] + f[i + 1];
		}
		for(i = 0; i <= n; i++)
			f[i] = g[i] % p;
	}
	for(i = 0; i <= n; i++)
		ans = (ans + f[i]) % p;
	for(i = 0; i < n; i++)
		f[i] = 1;
	for(j = 1; j <= m; j++)
	{
		for(i = 0; i < n; i++)
		{
			g[i] = 0;
			if(i)
				g[i] += f[i] + f[i - 1];
			if(i != n - 1)
				g[i] += f[i] + f[i + 1];
		}
		for(i = 0; i < n; i++)
			f[i] = g[i] % p;
	}
	for(i = 0; i < n; i++)
		ans = (ans + p - f[i]) % p;
	printf("%d\n", ans);
	return 0;
}