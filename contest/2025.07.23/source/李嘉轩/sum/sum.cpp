#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k, mod, ans = 0, a[101][101], b[101], c[101];
void dfs(int x, int y){
	if(x > n){
		int p = 1;
		memset(b, 0x7f, sizeof(b));
		memset(c, 0x7f, sizeof(c));
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				b[i] = min(b[i], a[i][j]);
				c[j] = min(c[j], a[i][j]);
			}
		}
		for(int i = 1; i <= n; i++)for(int j = 1; j <= m; j++)p = (p * min(b[i], c[j])) % mod;
		ans = (ans + p) % mod;
		return;
	}
	if(y > m){
		dfs(x + 1, 1);
		return;
	}
	for(int i = 1; i <= k; i++){
		a[x][y] = i;
		dfs(x, y + 1);
	}
}
signed main(){
	freopen("sum.in", "r", stdin);
	freopen("sum.out", "w", stdout);
	cin >> n >> m >> k >> mod;
	dfs(1, 1);
	cout << ans;
	return 0;
}
