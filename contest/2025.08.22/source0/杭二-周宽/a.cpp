#include <bits/stdc++.h>
#define PR(x) printf(x ? "YES\n" : "NO\n")
#define pr(x) printf(x ? "Yes\n" : "No\n")
#define mk make_pair
#define pb emplace_back
#define fi first
#define se second
#define pii pair<int, int>
#define fore(i, u, v) for (int i = h[u], v = e[i].v; i; v = e[i = e[i].nxt].v)
#define all(x) x.begin(), x.end()

using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (! isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

const int maxn = 1e7 + 10;

int n, m; long long P;
vector<int> f[2], g[2], sf[2], sg[2];
vector<int> s[2], fs[2], gs[2], s_[2];

void get(int id) {
	for (int i = 1; i <= m; i ++) s[id][i] = (s[id][i - 1] + f[id][i]) % P;
	
	for (int i = 2; i <= m; i ++)
		sf[id][i] = (1ll * sf[id][i - 1] + s[id][i - 2] + f[id][i - 1]) % P;
	for (int i = 1; i <= m; i ++)
		sg[id][i] = (sg[id][i - 1] + 1ll * g[id][i + 1] * i) % P;

	for (int i = m; i; i --) s_[id][i] = (s_[id][i + 1] + g[id][i]) % P;
	
	for (int i = m - 1; i; i --)
		gs[id][i] = (1ll * gs[id][i + 1] + s_[id][i + 2] + g[id][i + 1]) % P;
	for (int i = m; i; i --)
		fs[id][i] = (fs[id][i + 1] + 1ll * f[id][i - 1] * (m - i + 1)) % P;
}

signed main() {
	
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	n = read() - 1, m = read(), P = read();
	for (int i = 0; i < 2; i ++)
		f[i].resize(m + 2), g[i].resize(m + 2), 
		sf[i].resize(m + 2), sg[i].resize(m + 2),
		s[i].resize(m + 2), s_[i].resize(m + 2),
		fs[i].resize(m + 2), gs[i].resize(m + 2);

	for (int i = 1; i <= m; i ++)
		f[0][i] = 1ll * i * (i + 1) / 2 % P, 
		g[0][i] = 1ll * (m - i + 1) * (m - i + 2) / 2 % P;

	get(0);
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			f[i & 1][j] = 1ll * (j + 1) * j / 2 % P * f[i - 1 & 1][m] % P;
			f[i & 1][j] = (1ll * f[i & 1][j] - sf[i - 1 & 1][j] - sg[i - 1 & 1][j] + 2 * P) % P;

			g[i & 1][j] = 1ll * (m - j + 1) * (m - j + 2) / 2 % P * f[i - 1 & 1][m] % P;
			g[i & 1][j] = (1ll * g[i & 1][j] - fs[i - 1 & 1][j] - gs[i - 1 & 1][j] + 2 * P) % P;
		}

		get(i & 1);
	}

	printf("%lld", f[n & 1][m]);

	return 0;
}