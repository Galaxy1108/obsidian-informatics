#include<bits/stdc++.h>
using namespace std;
int n;
long long x[1000010], p[1000010], c[1000010], xp[1000010], dp[1000010];
int main()
{
	freopen("storage.in", "r", stdin);
	freopen("storage.out", "w", stdout);
	scanf("%d", &n);
	memset(dp, 0x3f, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= n; i++) scanf("%lld%lld%lld", &x[i], &p[i], &c[i]), xp[i] = x[i] * p[i] + xp[i - 1], p[i] += p[i - 1];
	for(int i = 1; i <= n; i++) for(int j = 0; j < i; j++) dp[i] = min(dp[i], dp[j] + x[i] * (p[i - 1] - p[j]) - (xp[i - 1] - xp[j]) + c[i]);
	printf("%lld", dp[n]);
	return 0;
}
