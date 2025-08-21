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
const int N = 1 << 20, mod = 998244353, inv2 = (mod + 1) / 2;
int n, m;
ll l[N], r[N]; 
int ql[N], qr[N]; 
inline int calc(ll x) {
	int cur = 0;
	L(i, 0, m / 2 - 1) cur ^= ((x >> i & 1) ^ (x >> (m - i - 1) & 1)) << i;
	return cur;
} 

int ns[N], ipw[N]; 
int A[N], B[N];

int op[N], dp[N][2];
int F[N];

unordered_map < int, int > mp;
void slv(int t) {
	if(t >= m / 2) {
		L(i, 0, n - 1) {
			int wl = (l[i] & ((1LL << (t + 1)) - 1)) % mod;
			int wr = (r[i] & ((1LL << (t + 1)) - 1)) % mod;
			A[i] = (wr - wl + mod) % mod;
		}
		L(i, 0, n - 1) {
			int wl = (l[i] & ((1LL << t) - 1)) % mod;
			int wr = (r[i] & ((1LL << t) - 1)) % mod;
			B[i] = (wr - wl + mod) % mod;
		}
		L(i, 1, n - 1) A[i] = (ll) A[i] * A[i - 1] % mod;
		L(i, 1, n - 1) B[i] = (ll) B[i] * B[i - 1] % mod;
		L(i, 0, n - 1)  
			(ns[i + 1] += (ll) (A[i] - B[i] + mod) * ipw[m / 2] % mod) %= mod;
		return ;
	} 
	L(i, 0, n - 1) ql[i] ^= ql[i] & ((1LL << t) - 1);
	L(i, 0, n - 1) qr[i] ^= qr[i] & ((1LL << t) - 1);
	
	mp.clear();
	int mid = n / 2; 
	dp[0][0] = 1, dp[0][1] = 0, op[0] = 0;
	L(i, 0, mid - 1) {
		L(s, 0, (1 << i) - 1) {
			int f[2] = {dp[s][0], dp[s][1]};
			op[s + (1 << i)] = op[s] ^ ql[i], op[s] ^= qr[i]; 
			L(z, 0, 1) {
				int xs = s + (z << i);
				me(dp[xs], 0);
				ll w = (z ? l[i] : r[i]);
				if(z & 1) f[0] = mod - f[0], f[1] = mod - f[1];
				dp[xs][0] = (ll) (w & ((1LL << t) - 1)) % mod * f[0] % mod;
				dp[xs][1] = (ll) (w & ((1LL << t) - 1)) % mod * f[1] % mod; 
				if(w >> t & 1) 
					(dp[xs][1] += (ll) (1LL << t) % mod * f[0] % mod) %= mod, 
					(dp[xs][0] += (ll) (1LL << t) % mod * f[1] % mod) %= mod;
			}
		}
		L(s, 0, (1 << (i + 1)) - 1) {
			int o = op[s] >> t & 1;
			if(op[s] == (o << t)) 
				(ns[i + 1] += (ll) dp[s][o] * ipw[t] % mod) %= mod;
		}
	} 
	
	L(s, 0, (1 << mid) - 1) L(o, 0, 1) 
		(mp[op[s] ^ (o << t)] += dp[s][o]) %= mod;
	
	dp[0][0] = 1, dp[0][1] = 0, op[0] = 0;
	L(i, 0, n - mid - 1) {
		int xi = i + mid;
		L(s, 0, (1 << i) - 1) {
			int f[2] = {dp[s][0], dp[s][1]};
			op[s + (1 << i)] = op[s] ^ ql[xi], op[s] ^= qr[xi]; 
			L(z, 0, 1) {
				int xs = s + (z << i);
				me(dp[xs], 0);
				ll w = (z ? l[xi] : r[xi]);
				if(z & 1) f[0] = mod - f[0], f[1] = mod - f[1];
				dp[xs][0] = (ll) (w & ((1LL << t) - 1)) % mod * f[0] % mod;
				dp[xs][1] = (ll) (w & ((1LL << t) - 1)) % mod * f[1] % mod; 
				if(w >> t & 1) 
					(dp[xs][1] += (ll) (1LL << t) % mod * f[0] % mod) %= mod, 
					(dp[xs][0] += (ll) (1LL << t) % mod * f[1] % mod) %= mod;
			}
		}
		L(s, 0, (1 << (i + 1)) - 1) L(o, 0, 1) {
			int w = op[s] ^ (o << t);
			if(dp[s][o]) (ns[xi + 1] += 
				(ll) dp[s][o] * mp[w] % mod * ipw[t] % mod) %= mod;
		}
	} 
	
	// -------------------------------------------------------------------------
	
	mp.clear();
	me(F, 0), me(op, 0);
	F[0] = 1, op[0] = 0;
	L(i, 0, mid - 1) {
		L(s, 0, (1 << i) - 1) {
			op[s + (1 << i)] = op[s] ^ ql[i], op[s] ^= qr[i]; 
			F[s + (1 << i)] = (ll) (mod - F[s]) * (l[i] & ((1LL << t) - 1)) % mod;
			F[s] = (ll) F[s] * (r[i] & ((1LL << t) - 1)) % mod;
		}
		L(s, 0, (1 << (i + 1)) - 1) if(!op[s]) 
			(ns[i + 1] += mod - (ll) F[s] * ipw[t] % mod) %= mod;
	}
	L(s, 0, (1 << mid) - 1) if(F[s]) 
		(mp[op[s]] += F[s]) %= mod;
	
	me(F, 0), me(op, 0);
	F[0] = 1, op[0] = 0;
	L(i, 0, (n - mid) - 1) {
		int xi = i + mid;
		L(s, 0, (1 << i) - 1) {
			op[s + (1 << i)] = op[s] ^ ql[xi], op[s] ^= qr[xi]; 
			F[s + (1 << i)] = (ll) (mod - F[s]) * (l[xi] & ((1LL << t) - 1)) % mod;
			F[s] = (ll) F[s] * (r[xi] & ((1LL << t) - 1)) % mod;
		}
		L(s, 0, (1 << (i + 1)) - 1) if(mp.count(op[s])) 
			(ns[i + mid + 1] += mod - 
				(ll) F[s] * mp[op[s]] % mod * ipw[t] % mod) %= mod;
	}
}

int main() {
//	return system("fc ex_far5.out far.out"), 0;
	freopen("far.in", "r", stdin);
	freopen("far.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	L(i, 0, n - 1) {
		cin >> l[i] >> r[i], ++r[i];
		ql[i] = calc(l[i]), qr[i] = calc(r[i]); 
	}
	ipw[0] = 1;
	L(i, 1, m) ipw[i] = (ll) ipw[i - 1] * inv2 % mod;
	L(t, 0, m) { 
		slv(t);
	} 
	L(i, 1, n) 
		cout << ns[i] << '\n';
	return 0;
} 