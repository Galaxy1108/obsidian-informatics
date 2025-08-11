#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000001], b[1000001], dp[1001][1001];
signed main(){
	freopen("kyoto.in", "r", stdin);
	freopen("kyoto.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++)cin >> a[i];
	for(int i = 1; i <= m; i++)cin >> b[i];
	memset(dp, 0x3f, sizeof(dp));
	dp[1][1] = 0;
	for(int i = 1; i <= n; i++)for(int j = 1; j <= m; j++)if(i > 1 || j > 1)dp[i][j] = min(dp[i - 1][j] + b[j], dp[i][j - 1] + a[i]);
	cout << dp[n][m];
	return 0;
}
