#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, ht[5005], hh[5005], dis[5001][5001], cnt = 0, E[5005],
dv = 1, des, vl;
const int lzj = 998244353, inf = 1e18;
int qpow(int a, int b) {
	int ans = 1;
	for (; b; b >>= 1, a = a * a % lzj)
		if (b & 1) ans = ans * a % lzj;
	return ans;
}
struct edge {
	signed to, nxt;
} et[5000 * 5000 + 7], eh[5000 * 5000 + 7];
void add(int f, int s) {
	et[++cnt].to = s, et[cnt].nxt = ht[f], ht[f] = cnt;
	eh[cnt].to = f, eh[cnt].nxt = hh[s], hh[s] = cnt;
}
int addv(int u, int lst, bool fl) {
	if (u == des) return 1;
	int ans = 0;
	if (!fl) {
		for (signed i = hh[u]; i; i = eh[i].nxt) {
			signed v = eh[i].to;
			if (v == lst) continue;
			int tmp = addv(v, u, 0);
			ans = (ans + tmp) % lzj;
			if (tmp)
				dis[u][v] = dis[v][u] =
				(dis[u][v] + vl * tmp % lzj) % lzj;
		}
	}
	for (signed i = ht[u]; i; i = et[i].nxt) {
		signed v = et[i].to;
		if (v == lst) continue;
		int tmp = addv(v, u, 1);
		ans = (tmp + ans) % lzj;
		if (tmp)
			dis[u][v] = dis[v][u] =
			(dis[u][v] + vl * tmp % lzj) % lzj;
	}
	return ans;
}
void getans(int u) {
	for (signed i = ht[u]; i; i = et[i].nxt) {
		signed v = et[i].to;
		E[v] = (E[v] + dis[u][v]) % lzj;
		getans(v);
	}
}
signed main() {
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
	memset(dis, 0, sizeof(dis));
	memset(E, 0, sizeof(E));
	memset(ht, 0, sizeof(ht));
	memset(hh, 0, sizeof(hh));
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for (int i = 2; i <= n; ++i) {
		int l, r;
		cin >> l >> r;
		dv = dv * (r - l + 1) % lzj;
		for (int j = l; j <= r; ++j)
			add(j, i);
	}
	cin >> m;
	while (m--) {
		int u;
		cin >> u >> des >> vl;
		addv(u, 0, 0);
	}
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j)
//			cout << dis[i][j] << ' ';
//		cout << endl;
//	}
	getans(1);
	int inv = qpow(dv, lzj - 2);
	for (int i = 2; i <= n; ++i)
		cout << E[i] % lzj << ' ';
	return 0;
}
