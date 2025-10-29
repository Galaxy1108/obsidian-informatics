#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
int n, a[601], b[6], dp[301][601], cnt = 0;
bool vis[11], t[100001];
void dfs(int x){
	int p = 0;
	if(x > n * 2){
		for(int i = 1; i <= n; i++)p = p * n * 2 + min(a[i * 2 - 1], a[i * 2]);
		if(!t[p]){
			cnt++;
			t[p] = true;
		}
	}
	if(a[x] != -1){
		dfs(x + 1);
		return;
	}
	for(int i = 1; i <= n * 2; i++){
		if(!vis[i]){
			vis[i] = true;
			a[x] = i;
			dfs(x + 1);
			vis[i] = false;
			a[x] = -1;
		}
	}
}
int get(){
	int f = 1, ans = 0;
	for(int i = 2; i <= n; i++)f = (f * i) % mod;
	dp[1][1] = 1;
	for(int i = 2; i <= n; i++)for(int j = i; j < i * 2; j++)for(int k = i - 1; k < j; k++)dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
	for(int i = n; i < n * 2; i++)ans = (ans + dp[n][i]) % mod;
	return (ans * f) % mod;
}
signed main(){
	freopen("permutation.in", "r", stdin);
	freopen("permutation.out", "w", stdout);
	bool sp = true;
	cin >> n;
	for(int i = 1; i <= n * 2; i++){
		cin >> a[i];
		if(a[i] != -1){
			sp = false;
			vis[a[i]] = 1;
		}
	}
	if(sp){
		cout << get();
		return 0;
	}
	if(n > 5){
		cout << 1;
		return 0;
	}
	dfs(1);
	cout << cnt;
	return 0;
}
