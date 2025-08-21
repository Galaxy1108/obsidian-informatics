#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int m, dp[41][1200001];
bool hw[1200001];
bool check(int x){
	int t;
	for(int i = 0; i < (m >> 1); i++){
		t = ((x & (1 << i)) | (x & (1 << (m - i - 1))));
		if(t == (t & (-t)) && t)return false;
	}
	return true;
}
signed main(){
	freopen("far.in", "r", stdin);
	freopen("far.out", "w", stdout);
	int n, l, r, ans;
	cin >> n >> m;
	if(m > 15){
		ans = 1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= (i == 1 ? ((m + 1) >> 1) : m); j++)ans = (ans << 1) % mod;
			cout << ans << "\n";
		}
		return 0;
	}
	dp[0][0] = 1;
	for(int i = 0; i < (1 << m); i++)hw[i] = check(i);
	for(int i = 1; i <= n; i++){
		cin >> l >> r;
		ans = 0;
		for(int j = 0; j < (1 << m); j++){
			for(int k = l; k <= r; k++)dp[i][j] = (dp[i][j] + dp[i - 1][j ^ k]) % mod;
			if(hw[j])ans = (ans + dp[i][j]) % mod;
		}
		cout << ans << "\n";
	}
	return 0;
}
