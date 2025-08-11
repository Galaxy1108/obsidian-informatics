//一看题面,有环,还有排序,鉴定为史
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, a[7], b[7][11], c[7], p[21], ans = 0x7f7f7f7f7f7f7f7f;
int calc(int n){
	sort(p + 1, p + n + 1);
	p[++n] = 2000000;
	int ans = 0;
	for(int i = 1; i <= n; i++)ans += (p[i] - p[i - 1]) * (p[i] - p[i - 1]);
	return ans;
} 
void dfs(int x){
	int cnt, w;
	if(x > n){
		w = 0;
		for(int i = 1; i <= n; i++){
			cnt = 0;
			for(int j = c[i]; j <= a[i]; j++)p[++cnt] = b[i][j];
			for(int j = 1; j < c[i % n + 1]; j++)p[++cnt] = b[i % n + 1][j];
			w += calc(cnt);
		}
		if(w < ans)ans = w;
		return;
	}
	for(int i = 1; i <= a[x]; i++){
		c[x] = i;
		dfs(x + 1);
	}
}
signed main(){
	freopen("ring.in", "r", stdin);
	freopen("ring.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		for(int j = 1; j <= a[i]; j++)cin >> b[i][j];
	}
	dfs(1);
	cout << ans;
	return 0;
}
