#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
const int mod = 1e9 + 7;
int n;
int h[N],w[N];
int l[N],r[N];
int stk[N],top = 0;
int D;
int qpow(int x,int y){
	int res = 1;
	while(y){
		if(y & 1) res = (res * x) % mod,y--;
		else x = (x * x) % mod,y >>= 1;
	}return res;
}
int calc(int h,int n,int m,int k){
	n = (1ll + n) % mod;
	m = (1ll + m) % mod;
	int k1 = n * m - 1ll + mod;
	k1 %= mod;
	int k2 = h * (h + 1ll);
	k2 %= mod;
	k2 = (k2 * D) % mod;
	int res = (k1 * k2) % mod;
	k1 = ((k - 1) * (m - 1ll + mod)) % mod;
	res = (res + (k1 * k2)% mod) % mod;
	k1 = ((k - 1) * (n - 1ll + mod)) % mod;
	res = (res + (k1 * k2) % mod) % mod;
	return res;
}
int workans(int n,int m){
	int k1 = n * (n + 1ll);
	k1 %= mod;
	k1 = (k1 * D) % mod;
	int k2 = m * (m + 1ll);
	k2 %= mod;
	k2 = (k2 * D) % mod;
	return (k1 * k2) % mod;
}
signed main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	D = qpow(2,mod - 2);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin >> n;
	for(int i = 1;i <= n;++i) cin >> h[i];
	for(int i = 1;i <= n;++i) cin >> w[i],w[i] += w[i - 1];
	for(int i = 1;i <= n;++i){
		while(top && h[stk[top]] > h[i]){
			r[stk[top]] = i;
			top--;
		}
		stk[++top] = i;
	}
	while(top){
		r[stk[top]] = n + 1;
		top--;
	}
	for(int i = n;i >= 1;--i){
		while(top && h[stk[top]] >= h[i]){
			l[stk[top]] = i;
			top--;
		}
		stk[++top] = i;
	}
	while(top){
		l[stk[top]] = 0;
		top--;
	}
	int ans = 0;
	for(int i = 1;i <= n;++i){
		ans = (ans + workans(h[i],w[i] - w[i - 1])) % mod;
		int res = calc(h[i],w[i - 1] - w[l[i]],w[r[i] - 1] - w[i],w[i] - w[i - 1]);
//		cout << h[i] << " " << w[i - 1] - w[l[i]] << " " << w[r[i] - 1] - w[i] << "\n";
//		cout << res << "\n";
		ans = (ans + res) % mod; 
	}cout << ans;
	return 0;
} 
