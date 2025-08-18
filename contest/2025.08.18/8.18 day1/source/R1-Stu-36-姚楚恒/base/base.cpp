#include<bits/stdc++.h>
using namespace std;
int n, a[2010], b[2010], x[2010], dp[5], s[2010], cnt;
int main()
{
	freopen("base.in", "r", stdin);
	freopen("base.out", "w", stdout);
	scanf("%d", &n);
	dp[1] = -2e9, dp[2] = -2e9;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), x[i] = a[i], a[i] += a[i - 1];
	for(int i = 1; i <= n; i++) scanf("%d", &b[i]), x[i] += b[i], b[i] += b[i - 1];
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= cnt; j++) if(s[j] + 1 < i) dp[2] = max(dp[1] + x[i] + max(a[i - 1] - a[s[j]], b[i - 1] - b[s[j]]), dp[2]);
		if(x[i] > dp[1]) dp[1] = x[i], cnt = 1, s[1] = i;
		if(x[i] == dp[1]) s[++cnt] = i;
	}
	printf("%d", dp[2]);
	return 0;
}
