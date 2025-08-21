#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
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
}t, sum;
frac update(frac a){
	a.a = (a.a % mod + mod) % mod;
	a.b = (a.b % mod + mod) % mod;
	return a;
}
frac operator + (frac a, frac b){return update(frac(a.a * b.b + a.b * b.a, a.b * b.b));}
frac operator * (frac a, frac b){return update(frac(a.a * b.a, a.b * b.b));}
frac operator - (frac a, frac b){return update(frac(a.a * b.b - a.b * b.a, a.b * b.b));}
int qpow(int x, int p){
	if(p == 0)return 1;
	if(p & 1)return (qpow(x, p - 1) * x) % mod;
	int ans = qpow(x, p >> 1);
	return (ans * ans) % mod;
}
int a[5001];
signed main(){
	freopen("dice.in", "r", stdin);
	freopen("dice.out", "w", stdout);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 0; i < n; i++){
		t = frac();
		for(int j = a[i]; j < a[i + 1]; j++)t = t + frac(qpow(j, n - i), 1);
		for(int j = i + 1; j <= n; j++)t = t * frac(1, a[j]);
		sum = sum + t;
	}
	sum = frac(a[n], 1) - sum;
	cout << (sum.a * qpow(sum.b, mod - 2)) % mod;
	return 0;
}
