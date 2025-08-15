#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244353
int qread(){
	int x = 0, k = 1;
	char c;
	while(1){
		c = getchar();
		if(c == '-'){
			k = -1;
			break;
		}else if(c >= '0' && c <= '9'){
			x = c - '0';
			break;
		}
	}
	while(1){
		c = getchar();
		if(c >= '0' && c <= '9')x = x * 10 + c - '0';
		else break;
	}
	return x * k;
}
vector<int>p[100001];
int a[1000001], dp[1000001];
int getNext(int x, int k){
	if(p[k][p[k].size() - 1] <= x)return 0;
	int l = 0, r = p[k].size() - 1, mid;
	while(l < r){
		mid = (l + r) >> 1;
		if(p[k][mid] > x)r = mid;
		else l = mid + 1;
	}
	return p[k][r];
}
signed main(){
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
	int n, m, x, ans = 0, v = 0, pos = 0;
	n = qread();
	for(int i = 1; i <= n; i++){
		x = qread();
		v = max(v, x);
		p[x].push_back(i);
	}
	m = qread();
	for(int i = 1; i <= m; i++)a[i] = qread();
	for(int i = n; i >= 1; i--){
		dp[i] = 1;
		for(int j = 1; j <= v; j++)dp[i] = (dp[i] + dp[getNext(i, j)]) % mod;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j < a[i]; j++)ans = (ans + dp[getNext(pos, j)]) % mod;
		pos = getNext(pos, a[i]);
	}
	cout << ans + m;
	return 0;
}
