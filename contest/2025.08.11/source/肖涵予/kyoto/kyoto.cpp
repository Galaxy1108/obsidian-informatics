#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
int n, m, a[N], b[N];
ll dp[N][N];
int main(void) {
	freopen("kyoto.in", "r", stdin);
	freopen("kyoto.out", "w", stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= m; ++i)
		cin >> b[i];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (i == 1 && j == 1) dp[i][j] = 0;
			else if (i == 1) dp[i][j] = dp[i][j-1] + a[i];
			else if (j == 1) dp[i][j] = dp[i-1][j] + b[j];
			else dp[i][j] = min(dp[i][j-1] + a[i], dp[i-1][j] + b[j]);
	cout << dp[n][m];
	return 0;
}
