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
const int N = 1e6 + 7, T = 1e6, mod = 998244353;
int qpow(int x, int y = mod - 2) {
	int res = 1;
	for(; y; x = (ll) x * x % mod, y >>= 1) if(y & 1) res = (ll) res * x % mod;
	return res;
}

ll n, sq;

int id1[N], id2[N], tot;
ll w[N];
inline int getid(ll x) {
	return x <= sq ? id1[x] : id2[n / x];
}

// \sum_{d <= n} sum_{i | d} mu(d/i) = 1
// \sum_{d = 1}^{n} S(n / d) = 1
// S(n) = 1 - sum_{d=2}^{n} S(n / d) 
ll dp[N], S[N];
int qwq[N];
bool vis[N];

int main() { 
//	return system("fc gcd.out gcd6.out"), 0;
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0); 
	cin >> n, sq = sqrt(n);
	for(ll l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		if(r <= sq) id1[r] = ++tot;
		else id2[n / r] = ++tot;
		w[tot] = r;
	}
	
	int tst;
	cin >> tst;
	
	dp[tot] = 1;
	vis[1] = 1;
	while(tst--) {
		ll p, a;
		cin >> p >> a;
		L(i, 1, tot) {
			ll x = w[i];
			L(j, 1, a) {
				x /= p;
				if(!x) break;
				dp[getid(x)] += dp[i];
			}
		}
		L(o, 1, a) R(i, T / p, 1) if(vis[i]) vis[i * p] = 1;
	} 
	R(i, tot, 1) dp[i] += dp[i + 1];
	
	L(i, 1, T) {
		if(!vis[i]) qwq[i] += 1;
		for(int j = i * 2; j <= T; j += i) 
			qwq[j] -= qwq[i];
	}
	L(i, 1, T) qwq[i] += qwq[i - 1];
	
	// w <= n / x
	// xw <= n
	// x <= n / w
	
	L(i, 1, tot) {
		ll x = w[i];
		if(x <= T) {
			S[i] = qwq[x];
			continue;
		}
		S[i] = x - dp[lower_bound(w + 1, w + tot + 1, n / x) - w];
		for(ll l = 2, r; l <= x; l = r + 1) 
			r = x / (x / l), S[i] -= S[getid(x / l)] * (r - l + 1);
	}
	
	int ns = 0;
	for(ll l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		ll v = S[getid(r)] - S[getid(l - 1)], w = n / l;
		v = (v % mod + mod) % mod;
		(ns += (ll) v % mod * (w % mod) % mod * qpow((n - w) % mod) % mod) %= mod;
	}
	cout << (ns + 1) % mod << '\n';
	return 0;
} 