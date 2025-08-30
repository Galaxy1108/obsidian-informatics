/*
羊羊丁真 : 村村的执杖 
*/
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i) 
#define R(i, j, k) for(int i = (j); i >= (k); --i) 
#define ll long long 
#define ull unsigned long long 
#define vi vector < int > 
#define sz(a) ((int) (a).size()) 
#define me(a, x) memset(a, x, sizeof(a)) 
using namespace std;
const int N = 1e5 + 7, M = 107, mod = 998244353; 
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
int cnt, f[N], g[N];
int dc[N], A[N], B[N];

int n, m; 
int DP[M][M];
ull F[M], G[M];
int T[M];
int pwa[N], pwb[N]; 

int main() {
	freopen("oracle.in", "r", stdin); 
	freopen("oracle.out", "w", stdout); 
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
//	n = 100, m = 1000;
	
	cnt = n * (n + 1) / 2;
	init(cnt);
	
	L(w, 0, cnt) {
		
		pwa[0] = pwb[0] = 1;
		L(i, 1, n) pwa[i] = (ll) pwa[i - 1] * w % mod;
		L(i, 1, n) pwb[i] = (ll) pwb[i - 1] * (w + 1) % mod;
		L(i, 0, n) T[i] = (ll) ifac[i] * pwa[i] % mod;
		
		me(DP, 0); 
		DP[0][0] = 1, g[0] = 1;
		L(i, 1, n) { 
			int md = n - i + 1;
			me(F, 0), me(G, 0);
			L(j, 0, md) { 
				int cur = (DP[i - 1][j] + (ll) DP[i - 1][j + 1] * (j + 1) % mod) * pwb[j] % mod;
				L(k, 0, md - j) 
					F[j + k] += (ll) cur * T[k];
				if(j % 18 == 0) {
					L(k, j, md) 
						F[k] %= mod;
				}
			} 
			L(k, 1, i - 1) {
				L(j, 0, md) 
					G[j] += (ll) DP[k][j] * g[i - k - 1];
				if(k % 18 == 0) {
					L(j, 0, md) 
						G[j] %= mod;
				} 
			}
			L(k, 0, md) 
				DP[i][k] = (F[k] % mod + mod - G[k] % mod) % mod; 
			DP[i][0] = 0;
			g[i] = DP[i][1];
		} 
		
		me(DP, 0); 
		DP[0][0] = 1;
		f[0] = g[0] = 1;
		L(i, 1, n) { 
			int md = n - i + 1;
			me(F, 0), me(G, 0);
			L(j, 0, md) { 
				int cur = (DP[i - 1][j] + (ll) DP[i - 1][j + 1] * (j + 1) % mod) * pwb[j] % mod;
				L(k, 0, md - j) 
					F[j + k] += (ll) cur * T[k];
				if(j % 20 == 0) {
					L(k, j, md) 
						F[k] %= mod;
				}
			} 
			L(k, 1, i - 1) {
				L(j, 0, md) 
					G[j] += (ll) DP[k][j] * g[i - k - 1];
				if(k % 20 == 0) {
					L(j, 0, md) 
						G[j] %= mod;
				} 
			}
			L(k, 0, md) 
				DP[i][k] = (F[k] % mod + mod - G[k] % mod) % mod; 
			f[i] = (DP[i][0] + DP[i][1]) % mod;
		} 
		
		dc[w] = f[n];
	}
	
	A[0] = 1;
	L(i, 0, cnt) {
		int W = (ll) ifac[i] * ifac[cnt - i] % mod * dc[i] % mod;
		if((cnt - i) & 1) W = mod - W;
		R(j, i, 0) (B[j + 1] += B[j]) %= mod, B[j] = (ll) B[j] * (mod - i) % mod;
		L(j, 0, i) (B[j] += (ll) A[j] * W % mod) %= mod; 
		R(j, i, 0) (A[j + 1] += A[j]) %= mod, A[j] = (ll) A[j] * (mod - i) % mod;
	}
	
//	ll s = 0;
//	L(i, 0, cnt) 
//		s += B[i];
//	cout << "S = " << s << '\n';
	
	cout << B[m] << '\n';
	return 0;
}