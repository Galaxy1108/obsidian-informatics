#include<bits/stdc++.h>
using namespace std;
#define int long long
int d[1000001], p[1000001], c[1000001], s[1000001], f[1000001], dp[1000002];
signed main(){
	freopen("storage.in", "r", stdin);
	freopen("storage.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> d[i] >> p[i] >> c[i];
		s[i] = s[i - 1] + f[i - 1] * (d[i] - d[i - 1]);
		f[i] = f[i - 1] + p[i];
	}
	for(int i = n; i >= 1; i--){
		dp[i] = 0x7f7f7f7f7f7f7f7f;
		for(int j = i; j <= n; j++)dp[i] = min(dp[i], dp[j + 1] + s[j] - s[i] - (d[j] - d[i]) * f[i - 1] + c[j]);
	}
	cout << dp[1];
	return 0;
}
