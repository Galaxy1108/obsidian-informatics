//调代码的时候发现还要考虑条件概率
//浪费2.5h
//至少能过一个大样例了(大样例还没题面里给的强)
//并且每个都是最后rand()个正确
//建议给一个u和v不可能为祖先关系的部分分
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int l[5001], r[5001];
struct frac{
	int a, b;
	frac(){
		a = 0;
		b = 1;
	}
	frac(int x, int y){
		a = x;
		b = y;
	}
}dp[5001][5001], sum[5001], ans[5001];
frac operator * (frac a, frac b){return frac((a.a * b.a) % mod, (a.b * b.b) % mod);}
frac operator + (frac a, frac b){return frac((a.a * b.b + a.b * b.a) % mod, (a.b * b.b) % mod);}
frac operator - (frac a, frac b){return frac((a.a * b.b - (a.b * b.a) % mod + mod) % mod, (a.b * b.b) % mod);}
int inv(int x, int p = mod - 2){
	if(p == 0)return 1;
	if(p & 1)return (inv(x, p - 1) * x) % mod;
	int ans = inv(x, p >> 1);
	return (ans * ans) % mod;
}
signed main(){
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	int n, m, u, v, w;
	cin >> n;
	for(int i = 2; i <= n; i++)cin >> l[i] >> r[i];
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < i; j++)sum[j] = frac(0, 1);
		sum[i] = dp[i][i] = frac(1, 1);
		for(int j = i + 1; j <= n; j++){
			dp[i][j] = (sum[r[j]] - sum[l[j] - 1]) * frac(1, r[j] - l[j] + 1);
			sum[j] = sum[j - 1] + dp[i][j];
		}
	}
	cin >> m; 
	while(m--){
		cin >> u >> v >> w;
		if(u == v)continue;
		for(int i = 2; i <= n; i++)ans[i] = ans[i] + (dp[i][u] + dp[i][v] - frac(2, 1) * dp[i][u] * dp[i][v]) * frac(w, 1);
	}
	for(int i = 2; i <= n; i++)cout << (ans[i].a * inv(ans[i].b)) % mod << " ";
	return 0;
}
