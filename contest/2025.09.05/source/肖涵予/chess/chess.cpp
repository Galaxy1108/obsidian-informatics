#include <bits/stdc++.h>
#define tol 1ll
using namespace std;
constexpr int Mod = 9999973;
constexpr int N = 105;
int n, m, mul[N];
int f[N][N][N], ans;
inline void add(int& x, int y) {
	x += y;
	if (x >= Mod)
		x -= Mod;
	return ;
}
int main(void) {
	freopen("chess.in", "r", stdin);
	freopen("chess.out", "w", stdout);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; ++i)
		mul[i] = i * (i - 1) / 2;
	add(f[1][m][0], 1), add(f[1][m-1][1], m);
	if (m > 1)
		add(f[1][m-2][2], mul[m]);
	for (int i = 1, to = 2; i < n; ++i, ++to)
		for (int j = 0; j <= m; ++j)
			for (int k = 0; k <= m - j; ++k) {
				add(f[to][j][k], f[i][j][k]);
				if (j)
					add(f[to][j-1][k+1], tol * f[i][j][k] * j % Mod);
				if (k)
					add(f[to][j][k-1], tol * f[i][j][k] * k % Mod);
				if (j > 1)	
					add(f[to][j-2][k+2], tol * f[i][j][k] * mul[j] % Mod);
				if (k > 1)
					add(f[to][j][k-2], tol * f[i][j][k] * mul[k] % Mod);
				if (j && k)
					add(f[to][j-1][k], tol * f[i][j][k] * j * k % Mod);
			}
	for (int j = 0; j <= m; ++j)
		for (int k = 0; k <= m - j; ++k)
			add(ans, f[n][j][k]);
	printf("%d", ans);
	return 0;
}
