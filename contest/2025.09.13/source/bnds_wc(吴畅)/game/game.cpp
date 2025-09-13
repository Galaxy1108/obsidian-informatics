#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 1000005
#define ll long long
using namespace std;
const int mo = 998244353;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
int k, T, dp[maxn], sum[maxn], ssum[maxn], f[maxn];
int phi[maxn], pri[maxn], vis[maxn], cnt;
inline void upd(int &x, int y) {
	x += y; if(x >= mo) x -= mo;
}
inline int qpow(int x, int step) {
	int res = 1;
	for (; step; step >>= 1) {
		if(step & 1) res = (ll)res * x % mo;
		x = (ll)x * x % mo;
	}
	return res;
}
unordered_map<int, int> res;
int main() {
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
	k = read(), T = read();
	phi[1] = 1;
	ru(i, 2, maxn - 1) {
		if(!vis[i]) pri[++cnt] = i, phi[i] = i - 1;
		for (int j = 1; j <= cnt && pri[j] * i < maxn; j++) {
			vis[i * pri[j]] = 1;
			if(i % pri[j] == 0) {
				phi[i * pri[j]] = phi[i] * pri[j];
				break;
			}
			phi[i * pri[j]] = phi[i] * (pri[j] - 1);
		}
	}
	dp[0] = sum[0] = ssum[0] = 1;
	ru(i, 1, maxn - 1) {
		if(i > k) sum[i] = dp[i] = sum[i - k - 1];
		upd(sum[i], sum[i - 1]);
		ssum[i] = sum[i];
		upd(ssum[i], ssum[i - 1]);
	}
	ru(i, k + 1, maxn - 1) {
		f[i] = (ll)sum[i - k - 1] * k % mo;
		upd(f[i], ssum[i - k - 1]);
	}
	while(T--) {
		int n = read();
		printf("%d ", f[n]);
		int &ans = res[n];
		if(ans != 0) {printf("%d\n", ans); continue;}
		for (int j = 1; j * j <= n; j++) if(n % j == 0) {
			upd(ans, (ll)phi[n / j] * f[j] % mo);
			if(j * j != n) upd(ans, (ll)phi[j] * f[n / j] % mo);
		}
		ans = (ll)ans * qpow(n, mo - 2) % mo;
		printf("%d\n", ans);
	}
	return 0;
}