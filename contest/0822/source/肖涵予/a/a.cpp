#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, p;
int ans;
int qpow(int base, int power) {
	int res = 1;
	while (power) {
		if (power & 1) res = 1ll * res * base % p;
		base = 1ll * base * base % p;
		power >>= 1;
	}
	return res;
}
int main(void) {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &p);
	if (min(n, m) == 1) { // Sp 1
		if (n == 1) ans = 1ll * m * (m + 1) % p * (2 * m + 1) % p * qpow(6, p - 2) % p;
		else ans = 1;
		printf("%d", ans);
		return 0;
	}
	// 40% data
	int N = n + 6, M = m + 6;
	int f[N][M][M], sum[M][M];
	memset(f, 0, sizeof f), memset(sum, 0, sizeof sum);
	for (int j = 1; j <= m; ++j)
		for (int k = j; k <= m; ++k)
			f[1][j][k] = 1;
	for (int j = 1; j <= m; ++j)
		for (int k = m; k >= 1; --k)
			sum[j][k] = (0ll + sum[j-1][k] + sum[j][k+1] - sum[j-1][k+1] + f[1][j][k]) % p;
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= m; ++j)
			for (int k = j; k <= m; ++k)
				f[i][j][k] = sum[k][j];
		for (int j = 1; j <= m; ++j)
			for (int k = m; k >= 1; --k)
				sum[j][k] = (0ll + sum[j-1][k] + sum[j][k+1] - sum[j-1][k+1] + f[i][j][k]) % p;
	}
	for (int j = 1; j <= m; ++j)
		for (int k = j; k <= m; ++k)
			ans = (0ll + ans + f[n][j][k]) % p;
	printf("%d", ans);		
	return 0;
}
