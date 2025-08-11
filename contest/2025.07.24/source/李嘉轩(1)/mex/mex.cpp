//好爽的推式子题
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int a[5001], dp[5001][5001];
signed main(){
	freopen("mex.in", "r", stdin);
	freopen("mex.out", "w", stdout);
	int n, m, ans = 0, f = 1, lst = -1;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(a[i])lst = i;
		else f = (f * m) % mod;
	}
	if(++m >= n || lst == -1){
		cout << f;
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i])dp[i][j] = dp[i - 1][j - 1];
			else dp[i][j] = (dp[i - 1][j] * j + dp[i - 1][j - 1] * (m - j)) % mod;
		}
	}
	for(int i = 1; i <= m; i++)ans = (ans + dp[n][i]) % mod;
	cout << ans;
	return 0;
}
