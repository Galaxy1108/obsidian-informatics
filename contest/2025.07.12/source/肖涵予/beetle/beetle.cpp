#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2005;
const ll mod = 1e9+7;
int n, k;
ll s[N], m[N][N], f[N], ans;
int read(void) {
	int x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) {
		x = x * 10 + ch - 48;
		ch = getchar();
	}
	return x;
}
ll fastPow(ll base, ll power) {
	ll res = 1;
	while (power) {
		if (power & 1) res = res * base % mod;
		base = base * base % mod;
		power >>= 1;
	}
	return res;
}
int main(void) {
	freopen("beetle.in", "r", stdin);
	freopen("beetle.out", "w", stdout);
	n = read(), k = read();
	for (int i = 1; i <= n; ++i)
		s[i] = read();
	for (int i = 1; i <= n; ++i) {
		f[i] = 1e18;
		m[i][i] = s[i];
		for (int j = i + 1; j <= n; ++j) {
			m[i][j] = max(m[i][j-1], s[j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		ll res = fastPow(23ll, (ll)n-i);
		for (int j = max(1, i-k+1); j <= i; ++j) {
			f[i] = min(f[i], f[j-1] + m[j][i]);
		}
		ans = (ans + f[i] * res % mod) % mod;
	}
	printf("%lld", ans);
	return 0;
}
