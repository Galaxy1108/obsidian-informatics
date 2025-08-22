#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, mod, ans;
signed main(){
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);
	scanf("%lld%lld%lld", &n, &m, &mod);
	if(n == 1){printf("%lld", (m * (m + 1) / 2) % mod); return 0;}
	if(m == 1){puts("1"); return 0;}
	int f[n + 10][m + 10][m + 10];
	memset(f, 0, sizeof f);
	for(int i = 1; i <= m; i++){
		for(int j = i; j <= m; j++){
			f[1][i][j] = 1;
		}
	}
	for(int i = 2; i <= n; i++){
		for(int l = 1; l <= m; l++){
			for(int r = l; r <= m; r++){
				for(int j = 1; j <= r; j++){
					for(int k = l; k <= m; k++){
						f[i][l][r] = (f[i][l][r] + f[i - 1][j][k]) % mod;
					}
				}
			}
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = i; j <= m; j++){
			ans += f[n][i][j];
			ans %= mod;
		}
	}	
	printf("%lld", ans);
	return 0;
}
