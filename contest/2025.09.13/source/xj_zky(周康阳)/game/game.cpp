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
const int N = 1e6 + 7, mod = 998244353, lim = 1e6;
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

int n, k;
int f[N], ns[N], xns[N], phi[N];
void Main() {
	cin >> n;
	cout << (ns[n] + mod - 1) % mod << ' ' << ((ll) xns[n] * inv[n] % mod + mod - 1) % mod << '\n';
}
int main() {
//	return system("fc game.out game2.out"), 0;
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	init(N - 7);
	int t;
	cin >> k >> t;
	f[0] = 1;
	L(i, 1, lim) {
		f[i] = f[i - 1];
		if(i >= k + 1) (f[i] += f[i - k - 1]) %= mod;
	}
	L(i, 0, lim) {
		ns[i] = f[i];
		if(i >= k + 1) (ns[i] += (ll) k * f[i - k - 1] % mod) %= mod;
	}
	L(i, 1, lim) phi[i] = i;
	L(i, 1, lim) L(j, 2, lim / i) phi[i * j] -= phi[i];
	L(i, 1, lim) L(j, 1, lim / i) (xns[i * j] += (ll) ns[i] * phi[j] % mod) %= mod;
	while(t--) Main();
	return 0;
} 