#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define ll long long
#define maxn 20005
using namespace std;
int n, mo;
int buc[maxn][maxn / 6];
ll sum[maxn];
int prime[maxn], cnt, vis[maxn];
int pre[maxn / 6][505], pre2[maxn / 6][505], pw[maxn / 6][505];
void init() {	
	ru(i, 2, n) if(!vis[i]) {
		prime[++cnt] = i;
		int now = 1;
		pre[cnt][0] = 1;
		ru(j, 1, 500) {
			now = (ll)now * i % mo;
			pre[cnt][j] = (pre[cnt][j - 1] + now) % mo;
		}
		pw[cnt][0] = 1;
		pw[cnt][1] = now, pre2[cnt][1] = pre[cnt][499];
		ru(i, 2, 500) {
			pw[cnt][i] = (ll)pw[cnt][i - 1] * pw[cnt][1] % mo;
			pre2[cnt][i] = (pre2[cnt][i - 1] + (ll)pw[cnt][i - 1] * pre2[cnt][1] % mo) % mo;
		}
		for (int j = 2; j <= n / i; j++) vis[i * j] = 1;
	}
}
int main() {
	freopen("gonna.in", "r", stdin);
	freopen("gonna.out", "w", stdout);
	scanf("%d%d", &n, &mo);
	init();
	ru(i, 1, n) {
		int tmp = i;
		ru(j, 1, cnt) {
			if(prime[j] > i) break;
			if(i % prime[j] == 0) {
				buc[i][j] = buc[i / prime[j]][j] + 1;
			}
		}
	}
	ru(i, 1, n) {
		int tmp = i;
		ru(j, 1, cnt) {
			if(prime[j] > i) break;
			buc[i][j] += buc[i - 1][j];
		}
	}
	ll ans = 0;
	ru(i, 1, n) {
		int res = 1;
		ru(j, 1, cnt) {
			if(prime[j] > i) break;
			sum[j] += buc[i][j];
			int s = (i + 1) * buc[i][j] - sum[j] * 2;
			
			int id = s / 500;
			ll tmp = pre2[j][id] + (ll)pw[j][id] * pre[j][s % 500] % mo;
			res = (ll)res * tmp % mo;
		}
		ans += res;
	}
	printf("%d\n", ans % mo);
	return 0;
}