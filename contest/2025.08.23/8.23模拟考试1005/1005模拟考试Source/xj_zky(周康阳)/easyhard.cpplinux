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
const int N = 3003;
int n, m, mod;
int dp1[N][N], dp2[N][N], s1[N], s2[N];
int main() {
	freopen("easyhard.in", "r", stdin);
	freopen("easyhard.out", "w", stdout);
	ios :: sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> mod, --n, --m;
	dp1[0][0] = 1;
	L(i, 0, m) {
		L(j, 0, n) if(dp1[i][j]) {
			(s1[i] += dp1[i][j]) %= mod;
			(dp1[i + 1][j] += (ll) 2 * dp1[i][j] % mod) %= mod;
			(dp1[i + 1][j + 1] += dp1[i][j]) %= mod;
			if(j > 0) (dp1[i + 1][j - 1] += dp1[i][j]) %= mod;
		}
	}
	
	dp2[0][0] = 1; 
	L(i, 0, m) {
		L(j, 0, n) if(dp2[i][j]) {
			(s2[i] += dp2[i][j]) %= mod;
			if(j > 0) (dp2[i + 1][j] += (ll) 2 * dp2[i][j] % mod) %= mod;
			(dp2[i + 1][j + 1] += dp2[i][j]) %= mod;
			if(j > 1) (dp2[i + 1][j - 1] += dp2[i][j]) %= mod;
		}
	}
	
	int ns = 0;
	L(i, 0, m) 
		(ns += (ll) s1[i] * s2[m - i] % mod) %= mod;
	
	ns = (ll) ns * 4 % mod;
	cout << ns << '\n';
	return 0;
}