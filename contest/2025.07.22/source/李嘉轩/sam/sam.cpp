#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
struct matrix{
	int n, m, a[114][514];
	matrix(int N, int M){
		n = N;
		m = M;
		memset(a, 0, sizeof(a));
	}
}ans(10, 1), mul(10, 10);
matrix operator * (matrix a, matrix b){
	matrix c(a.n, b.m);
	for(int i = 0; i < a.n; i++)for(int j = 0; j < a.m; j++)for(int k = 0; k < b.m; k++)c.a[i][k] = (c.a[i][k] + a.a[i][j] * b.a[j][k]) % mod;
	return c;
}
signed main(){
	freopen("sam.in", "r", stdin);
	freopen("sam.out", "w", stdout);
	for(int i = 1; i <= 9; i++)ans.a[i][0] = 1;
	for(int i = 0; i <= 9; i++){
		mul.a[i][i] = 1;
		if(i > 0)mul.a[i][i - 1] = 1;
		if(i > 1)mul.a[i][i - 2] = 1;
		if(i < 9)mul.a[i][i + 1] = 1;
		if(i < 8)mul.a[i][i + 2] = 1;
	}
	int k, res = 0;
	cin >> k;
	if((k--) == 1){
		cout << 10;
		return 0;
	}
	while(k){
		if(k & 1)ans = mul * ans;
		mul = mul * mul;
		k >>= 1;
	}
	for(int i = 0; i <= 9; i++)res = (res + ans.a[i][0]) % mod;
	cout << res;
	return 0;
}
