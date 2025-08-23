#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int a[200001], pw[200001];
int solve(int n){
	int sum = 0, maxn = 0, ans = 0, cnt = 0;
	for(int i = 1; i <= n; i++)sum += a[i];
	for(int i = n; i >= 1; i--){
		if(sum - a[i] < max(maxn, a[i] + cnt)){
			ans = (ans + pw[i]) % mod;
			cnt++;
		}else{
			maxn = max(maxn, a[i] + cnt);
			sum -= a[i];
		}
	}
	return ans;
}
signed main(){
	freopen("imperishable.in", "r", stdin);
	freopen("imperishable.out", "w", stdout);
	int Num, n, q, x, y;
	cin >> Num >> n;
	pw[0] = 1;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		pw[i] = (pw[i - 1] << 1) % mod;
	}
	cout << solve(n) << "\n";
	cin >> q;
	while(q--){
		cin >> x >> y;
		a[x] = y;
		cout << solve(n) << "\n";
	}
	return 0;
}
