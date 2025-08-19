#include<bits/stdc++.h>
using namespace std;
int w[8001], u[8001], t[8001], dp[8001], val[22] = {114514, 100, 100, 97, 96, 95, 90, 85, 80, 82, 78, 75, 70, 65, 55, 50, 15, 12, 10, 8, 5, 2};
int main(){
	freopen("sniper.in", "r", stdin);
	freopen("sniper.out", "w", stdout);
	int n, ans = 0;
	cin >> n;
	t[0] = -114514;
	for(int i = 1; i <= n; i++){
		cin >> w[i] >> u[i] >> t[i];
		for(int j = i - 1; j >= 0; j--){
			if(t[i] - t[j] > 1 && (t[i] - t[j] - 1) * 2 >= abs(u[i] - u[j]))dp[i] = max(dp[i], dp[j] + val[w[i]]);
			if(w[j] == 15)break;
		}
	}
	for(int i = n; i >= 1; i--){
		ans = max(ans, dp[i]);
		if(w[i] == 15)break;
	}
	cout << ans;
	return 0;
}
