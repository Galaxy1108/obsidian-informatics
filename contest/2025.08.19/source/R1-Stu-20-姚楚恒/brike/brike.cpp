#include<bits/stdc++.h>
using namespace std;
int n, m, a[60][60], dp[60][60][510], ans;
int main()
{
	freopen("brike.in", "r", stdin);
	freopen("brike.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n - i + 1; j++) scanf("%d", &a[i][j]);
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n - i + 1; j++)
		{
			for(int k = 0; k <= m; k++)
			{
				for(int l = 0; l <= k; l++) dp[i][j][k] = max(max(dp[i][j][k], dp[i - 1][j][l] + dp[i - 1][j + 1][k - l]), dp[i - 1][j][l] + dp[i - 1][j + 1][k - l - 1] + a[i][j]);
			}
		}
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n - i + 1; j++) ans = max(ans, dp[i][j][m]);
	printf("%d", ans);
	return 0;
}
