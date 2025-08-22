#include <bits/stdc++.h>
#define N 10000005
using namespace std;
inline int read(){
	char ch = getchar(); int x = 0, f = 1;
	while(!isdigit(ch)){if(ch == '-') f = -1; ch = getchar();}
	while(isdigit(ch)){x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
bool m1;
int n, m, p, k, tot, ans;
int fac[N], inv[N], fav[N], kp[N];

inline int add(int x, int y){return (x + y >= p)? x - p + y : x + y;}
inline int sub(int x, int y){return (x < y)? x - y + p : x - y;}
inline int mul(int x, int y){return 1ll * x * y % p;}
inline int qpow(int x, int k){
	int res = 1;
	for(; k; k >>= 1, x = mul(x, x)) if(k & 1) res = mul(res, x);
	return res;
}

void init(){
	fac[0] = fac[1] = inv[0] = inv[1] = fav[0] = fav[1] = 1;
	kp[0] = 1, kp[1] = k;
	for(int i = 2; i <= max(n, m); i++){
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mul(p - p / i, inv[p % i]);
		fav[i] = mul(fav[i - 1], inv[i]);
		kp[i] = mul(kp[i - 1], k);
	}
}
int C(int x, int y){return mul(fac[x], mul(fav[y], fav[x - y]));}

bool m2;
int main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	cerr<<abs(&m1 - &m2) / 1024 / 1024 <<"MB"<<endl;
	n = read(), m = read(), p = read();
	k = (1ll * m * (m + 1) / 2ll) % p;
	if(n == 1){printf("%d", k); return 0;}
	if(m == 1){puts("1"); return 0;}
	if(1ll * n * m * m * m * m <= 1e7){
//		cerr<<"!!"<<endl;
		int f[n + 15][m + 15][m + 15];
		memset(f, 0, sizeof f);
		for(int i = 1; i <= m; i++)
			for(int j = i; j <= m; j++) f[1][i][j] = 1;
		for(int i = 2; i <= n; i++)
			for(int l1 = 1; l1 <= m; l1++)
				for(int r1 = l1; r1 <= m; r1++)
					for(int l2 = 1; l2 <= r1; l2++)
						for(int r2 = max(l1, l2); r2 <= m; r2++)
							f[i][l1][r1] = add(f[i][l1][r1], f[i - 1][l2][r2]);
		for(int i = 1; i <= m; i++)
			for(int j = i; j <= m; j++) ans = add(ans, f[n][i][j]);
		printf("%d", ans);
		return 0;
	}
	init();
	ans = qpow(k, n);
	for(int i = 1; i < n; i++){
		int opt = ((i & 1)? p - 1 : 1), tot1 = 0, tot2 = 0;
		for(int j = i + 1; j <= m; j++) tot1 = add(tot1, C(j - 1, i));
		int val = mul(n - i, mul(kp[n - i - 1], mul(fac[i + 1], tot1)));
		ans = add(ans, mul(opt, val));
	}
	printf("%d", ans);
	return 0;
}
