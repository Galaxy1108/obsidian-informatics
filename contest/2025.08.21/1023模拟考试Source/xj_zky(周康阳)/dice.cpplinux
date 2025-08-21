#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define sz(a) ((int) (a).size())
#define vi vector < int > 
#define me(a, x) memset(a, x, sizeof(a))
#define ull unsigned long long
#define ld __float128
using namespace std;
const int N = 1e6 + 7, mod = 1e9 + 7;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}
int fac[N], ifac[N], inv[N];
void init(int x) {
	fac[0] = ifac[0] = inv[1] = 1;
	L(i, 2, x) inv[i] = (ll) (mod - mod / i) * inv[mod % i] % mod;
	L(i, 1, x) fac[i] = (ll) fac[i - 1] * i % mod, ifac[i] = (ll) ifac[i - 1] * inv[i] % mod;
} 
int C(int x, int y) {
	return x < y || y < 0 ? 0 : (ll) fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}

int n, a[N];
int pw[N], pre[N];
int w[N];

int eva(int x) {
	int s = 0, ret = 1;
	L(i, 0, n + 1) 
		s = (ll) s * (x - i + mod) % mod, 
		(s += (ll) ret * pre[i] % mod * w[i] % mod) %= mod, 
		ret = (ll) ret * (x - i + mod) % mod;
	return s;
}

int main() {
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n, init(n + 1);
	L(i, 1, n) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int ns = a[n] % mod;
	
	L(i, 0, n + 1) {
		w[i] = (ll) ifac[i] * ifac[n + 1 - i] % mod;
		if((n + 1 - i) & 1) w[i] = mod - w[i];
	}
	
	L(i, 1, n + 1) pw[i] = 1;
	L(i, 1, n + 1) pre[i] = i;
	int prd = 1;
	R(i, n, 1) {
		// calulate answer belongs to (a_{i-1},a_i] 
		prd = (ll) prd * qpow(a[i]) % mod;
		L(j, 1, n + 1) pw[j] = (ll) pw[j] * j % mod;
		L(j, 1, n + 1) pre[j] = (pw[j - 1] + pre[j - 1]) % mod;
		int tmp = (eva(a[i]) + mod - eva(a[i - 1])) % mod;
		(ns += (ll) (mod - tmp) * prd % mod) %= mod;
	}
	cout << ns << '\n';
	return 0;
} 