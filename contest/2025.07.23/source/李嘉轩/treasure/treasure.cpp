#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int n, k, c[101], mp[114][514], ans = 0;
void dfs(int x, int y){
	if(x > n){
		int cnt;
		for(int i = 1; i <= n; i++){
			cnt = 0;
			for(int j = 0; j < min(i, k); j++)for(int l = 1; l <= k - j; l++)cnt += mp[i - j][l];
			if(cnt != c[i])return;
		}
		ans++;
		return;
	}
	if(y > k){
		dfs(x + 1, 1);
		return;
	}
	mp[x][y] = 0;
	dfs(x, y + 1);
	mp[x][y] = 1;
	dfs(x, y + 1);
}
signed main(){
	freopen("treasure.in", "r", stdin);
	freopen("treasure.out", "w", stdout);
	int t, a = 1, b = 0, x;
	cin >> n >> k;
	for(int i = 1; i <= n; i++)cin >> c[i];
	if(k == 1){
		cout << 1;
		return 0;
	}
	if(k > 2){
		dfs(1, 1);
		cout << ans;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		switch(c[i]){
			case 0:{
				b = 0;
				break;
			}
			case 1:{
				t = a;
				a = (a + b) % mod;
				b = t;
				break;
			}
			case 2:{
				t = b;
				b = (a + b) % mod;
				a = t;
				break;
			}
			case 3:{
				a = 0;
				break;
			}
		}
	}
	cout << (a + b) % mod;
	return 0;
}
