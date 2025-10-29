#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int Mod = 998244353, N = 505;
ll jc[N], inv[N];
ll qpow(ll a, ll b){
	ll res = 1;
	while(b){
		if(b & 1) res *= a, res %= Mod;
		a *= a, a %= Mod;
		b >>= 1;
	}
	return res % Mod;
}
void init(){
	jc[0] = 1;
	for(int i = 1; i <= N - 1; i++)jc[i] = i * jc[i - 1], jc[i] %= Mod;
	inv[N - 1] = qpow(jc[N - 1], Mod - 2), inv[0] = 1;
	for(int i = N - 2; i >= 1; i--)inv[i] = inv[i + 1] * (i + 1) % Mod, inv[i] %= Mod;
}
ll C(int n, int m){
	return jc[n] * inv[m] % Mod * inv[n - m] % Mod; 
}
ll f[N][N];
int main(){
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	init();
	freopen("arena.in", "r", stdin);
	freopen("arena.out", "w", stdout);
	int n, x;
	cin >> n >> x;
//	cout << C(3, 2) << endl;
	for(int i = 2; i <= n; i++){
		for(int j = 1; j <= x; j++){
			if(i > j){
				f[i][j] = (qpow(j, i) - qpow(j - 1, i) + Mod) % Mod; 
			}
			else{
				for(int k = 1; k <= i; k++){
					f[i][j] += (qpow(i - 1, i - k) * f[k][j - i + 1] % Mod * C(i, k) % Mod) % Mod;
					f[i][j] %= Mod;
				}
			}
		}
	}
	ll ans = 0;
	for(int i = 1; i <= x; i++){
		ans = (ans + f[n][i]) % Mod;
//		cout << f[n][i] << " "; 
	}
	cout << ans << endl;
	return 0;
}
