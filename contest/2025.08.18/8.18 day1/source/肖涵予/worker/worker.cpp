#include <bits/stdc++.h>
using namespace std;
const int N = 105, M = 12;
int n, pure[N];
int dp[N][M][M][M];
int main(void) {
	freopen("worker.in", "r", stdin);
	freopen("worker.out", "w", stdout);
	cin.tie(0) -> ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		pure[i] = c - 'A';
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0][0][0][0] = 0;
	for (int i = 0; i < n; ++i)
		for (int a = 0; a < 10; ++a)
			for (int b = 0; b < 10; ++b)
				for (int c = 0; c < 10; ++c) {
					if (a + b + c >= 10 || dp[i][a][b][c] == 0x3f3f3f3f) continue;
					int nxt = i, x = a, y = b, z = c, res = dp[i][a][b][c] + 1;
					while (x + y + z < 10 && nxt < n) {
						++nxt;
						if (pure[nxt] == 0) ++x;
						else if (pure[nxt] == 1) ++y;
						else ++z;
					}
					if (x) dp[nxt][0][y][z] = min(dp[nxt][0][y][z], res);
					if (y) dp[nxt][x][0][z] = min(dp[nxt][x][0][z], res);
					if (z) dp[nxt][x][y][0] = min(dp[nxt][x][y][0], res);
				}
	int ans = 0x3f3f3f3f;
	for (int a = 0; a < 10; ++a)
		for (int b = 0; b < 10; ++b)
			for (int c = 0; c < 10; ++c) {
				if (a + b + c >= 10 || dp[n][a][b][c] == 0x3f3f3f3f) continue;
				ans = min(ans, dp[n][a][b][c] + (a > 0) + (b > 0) + (c > 0));
			}
	cout << ans;
	return 0;
}
