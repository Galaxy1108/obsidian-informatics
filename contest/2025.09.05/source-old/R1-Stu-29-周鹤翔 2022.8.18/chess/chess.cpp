#include <bits/stdc++.h>
using namespace std; 
typedef long long ll; 
const ll  mod = 9999973; 
const int maxn = 105; 
int n, m; 
ll dp[maxn][maxn][maxn];
ll c(int x) {
	return x * (x - 1) / 2; 
}
void init() {
	cin >> n >> m; 
	dp[0][0][0] = 1; 
	return ; 
}
void work() {
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= m; ++j) {
			for(int k = 0; k <= m - j; ++k) {
				if(dp[i][j][k] != 0) {
					dp[i + 1][j][k] = (dp[i + 1][j][k] + dp[i][j][k]) % mod; 
					if(m - j - k >= 1) {
						dp[i + 1][j + 1][k] = (dp[i + 1][j + 1][k] + dp[i][j][k] * (m - j - k) % mod) % mod; 
					}
					if(j >= 1) {
						dp[i + 1][j - 1][k + 1] = (dp[i + 1][j - 1][k + 1] + dp[i][j][k] * j % mod) % mod; 
					} 
					if(m - j - k >= 1 && j >= 1) {
						dp[i + 1][j][k + 1] = (dp[i + 1][j][k + 1] + dp[i][j][k] * (m - j - k) % mod * j % mod) % mod; 
					}
					if(m - j - k >= 2) {
						dp[i + 1][j + 2][k] = (dp[i + 1][j + 2][k] + dp[i][j][k] * c(m - j - k) % mod) % mod; 
					}
					if(j >= 2) {
						dp[i + 1][j - 2][k + 2] = (dp[i + 1][j - 2][k + 2] + dp[i][j][k] * c(j) % mod) % mod; 
					}
				}
			}
		}
	}
	return ; 
}
ll ed() {
	ll ans = 0; 
	for(int i = 0; i <= m; ++i) {
		for(int j =0; j<= m - i; ++j) {
			ans = (ans + dp[n][i][j]) % mod; 
		}
	}
	return ans; 
}
int main() {
	freopen("chess.in" , "r", stdin );
	freopen("chess.out", "w", stdout); 
	init(); 
	work(); 
	cout << ed() << endl; 
	return 0; 
}
