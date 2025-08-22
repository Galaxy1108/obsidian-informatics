#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e7 + 10;
int mod;
int mul(int x, int y) { return 1ll * x * y % mod; }
int sub(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
void adc(int &x, int y) { x = add(x, y); }
int n, m;
int chk(int l1, int r1, int l2, int r2) { return (r1 < l2 || r2 < l1) ? 0 : 1; }
signed main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &mod);
	if(n == 1) return printf("%lld", m * (m + 1) / 2 % mod), 0;
	if(m == 1) return printf("1"), 0;
	int f[n + 5][m + 5][m + 5];
	memset(f, 0, sizeof f);
	for(int i = 1; i <= m; i++) for(int j = i; j <= m; j++) f[1][i][j] = 1;
	for(int i = 2; i <= n; i++) 
		for(int l1 = 1; l1 <= m; l1++) 
			for(int r1 = l1; r1 <= m; r1++) 
				for(int l2 = 1; l2 <= m; l2++) 
					for(int r2 = l2; r2 <= m; r2++) 
						adc(f[i][l1][r1], mul(chk(l1, r1, l2, r2), f[i - 1][l2][r2])); 
	int ans = 0;
	for(int i = 1; i <= m; i++) 
		for(int j = i; j <= m; j++) 
			adc(ans, f[n][i][j]);
	printf("%lld", ans);
	return 0;
}

