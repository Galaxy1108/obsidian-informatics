#include <cstdio>
#include <algorithm>
#include <cstring> 

using namespace std;
typedef long long ll;

int a[205], dp[65][250005];

int main()
{
	freopen("give.in", "r", stdin);
	freopen("give.out", "w", stdout);
	int n, i, t, mx, k, j, p;
	ll m, s;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%lld%lld%d", &m, &s, &n);
		mx = 0;
		for(i = 1; i <= n; i++)
		{
			scanf("%d", a + i);
			if(a[i] > mx)
				mx = a[i];
		}
		memset(dp, 0, sizeof(dp));
		for(i = 0; i <= 60; i++)
		{
			if((m >> i) & 1)
			{
				if(i != 0)
					for(j = 0; j < 2 * mx; j++)
						for(k = 1; k <= n && a[k] <= j; k++)
							dp[i][j] ^= dp[i - 1][((j - a[k]) << 1) | ((s >> (i - 1)) & 1)];
				else
					for(k = 1; k <= n; k++)
						dp[0][a[k]] = 1;
			}
			else if(i != 0)
				for(j = 0; j < 2 * mx; j++)
					dp[i][j] = dp[i - 1][(j << 1) | ((s >> (i - 1)) & 1)];
			else
				dp[0][0] = 1;
		}
		printf("%d\n", dp[60][0]);
	}
	return 0;
}