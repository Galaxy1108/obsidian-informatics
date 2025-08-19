#include<bits/stdc++.h>
using namespace std;
int n;
long long cost;
double w, c, d, dp[5][5];
int main()
{
	freopen("money.in", "r", stdin);
	freopen("money.out", "w", stdout);
	scanf("%d%lld", &n, &cost);
	for(int i = 1; i <= n; i++)
	{
		scanf("%lf%lf%lf", &w, &c, &d);
		dp[i % 2][1] = max(dp[(i - 1) % 2][1], (dp[(i - 1) % 2][2] + w) * c);
		dp[i % 2][2] = max(dp[(i - 1) % 2][2], dp[(i - 1) % 2][1] * d - cost) + w;
	}
	printf("%.4lf", dp[n % 2][2]);
	return 0;
}
