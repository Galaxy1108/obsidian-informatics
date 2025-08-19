#include<bits/stdc++.h>
#define ll long long
#define maxn 100010
#define mod 998244353
using namespace std;
ll inv[maxn], ans[maxn];
ll qpow(ll x, ll y) {
	ll bas = 1;
	while (y) {
		if (y % 2) bas = bas * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return bas;
}
ll po(ll x) {
	ll bas = 1, y = mod - 2;
	while (y) {
		if (y % 2) bas = bas * x % mod;
		x = x * x % mod;
		y /= 2;
	}
	return bas;
}
int main(int argc, char **argv)
{

	for (int i = 1; i <= 5100; i++) {
		inv[i] = po(i);
	}

	int n, k;
	scanf("%d%d", &n, &k);
	int res = n % (k + 1);
	for (int i = 0; i < k; i++) {
		ans[i] = 1;
	}
	for (int i = k; i < n; i++) {
		ans[i] = 0;
		if ((n - i) % (k + 1) == 1) continue;
		for (int j = i; j >= 0; j--) {
			if (j == 0) {
				ans[j] = ans[j] * (i - j) % mod * inv[i + 1] % mod;
				ans[j] %= mod;
			}
			else {
				ans[j] = ans[j] * (i - j) % mod * inv[i + 1] % mod + ans[j - 1] * (j) % mod * inv[i + 1] % mod;
				ans[j] %= mod;
			}
		}
	}
	for (int i = n - 1; i > 0; i--) printf("%lld ", ans[i]);
	printf("%lld\n", ans[0]);

	return 0;

}


