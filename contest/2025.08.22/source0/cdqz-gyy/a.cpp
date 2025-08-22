#include <bits/stdc++.h>

const int MAXN = 10000005;

int32_t n, m, p;

int64_t ans = 0;
int64_t f[MAXN], g[MAXN], gl[MAXN], gr[MAXN];

int main () {
	
	freopen ("a.in", "r", stdin);
	freopen ("a.out", "w", stdout);
	
	std::cin >> n >> m >> p;
	
	if (n == 1) return std::cout << ((1ll * m * (m + 1)) / 2) % p << '\n', 0;
	
	for (int l = 1; l <= m; ++ l) f[l] = l;
	
	for (int i = 2; i <= n; ++ i) {
		for (int x = 1; x <= m; ++ x) gl[x] = gr[x] = g[x] = f[x], f[x] = 0;
		for (int x = 2; x <= m; ++ x) gl[x] = (gl[x] + gl[x - 1]) % p, gr[x] = (1ll * x * gr[x] % p + gr[x - 1]) % p;

		for (int l = 1; l <= m; ++ l) 
			f[l] = (f[l] + 1ll * l * (gl[m] - gl[m - l] - gl[l - 1] + p + p) % p + gr[l - 1]) % p;
	}
	
	for (int l = 1; l <= m; ++ l) ans = (ans + f[l]) % p;
	
	std::cout << ans << '\n';
	
	return 0;
}