#include<bits/stdc++.h>
using namespace std;
#define int long long
int f[1000001], g[10000001];
signed main(){
	freopen("gold.in", "r", stdin);
	freopen("gold.out", "w", stdout);
	int n, k, t, x, m, cnt = 0, ans = 0;
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		t = 1;
		x = i;
		while(x){
			t *= (x % 10);
			if(t == 0)break;
			x /= 10;
		}
		f[t]++;
	}
	sort(f + 1, f + n + 1, greater<int>());
	for(int i = 1; i <= k; i++){
		m = k / i;
		for(int j = 1; j <= m; j++)g[++cnt] = f[i] * f[j];
	}
	sort(g + 1, g + cnt + 1, greater<int>());
	for(int i = 1; i <= k; i++)ans = (ans + g[i]) % 1000000007;
	cout << ans;
	return 0;
}
