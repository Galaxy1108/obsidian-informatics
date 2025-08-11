#include<bits/stdc++.h>
using namespace std;
int n, a[601], p[1201], t[1201], ans = 0;
bool vis[601];
void dfs(int x){
	if(x > n){
		for(int i = 1; i <= n * 2; i++)t[i] = p[i];
		for(int qwq = 1; qwq <= n; qwq++){
			memset(vis, 0, sizeof(vis));
			for(int i = n * 2; i >= 1; i--){
				if(t[i] <= 0)continue;
				if(vis[t[i]])t[i]--;
				else vis[t[i]] = true;
			}
		}
		for(int i = 1; i <= n; i++)if(!t[a[i]])return;
		ans++;
		return;
	}
	for(int i = 1; i < n * 2; i++){
		if(p[i] > 0)continue;
		for(int j = i + 1; j <= n * 2; j++){
			if(p[j] > 0)continue;
			p[i] = p[j] = x;
			dfs(x + 1);
			p[i] = p[j] = 0;
		}
	}
}
int main(){
	freopen("ruin.in", "r", stdin);
	freopen("ruin.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	dfs(1);
	cout << ans;
	return 0;
}
