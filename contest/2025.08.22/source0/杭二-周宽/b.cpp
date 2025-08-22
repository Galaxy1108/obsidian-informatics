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
#define int long long

using namespace std;
inline int read() {
	int x = 0, f = 1;
	char ch = getchar();
	while (! isdigit(ch)) { if (ch == '-') f = -1; ch = getchar(); }
	while (isdigit(ch)) { x = x * 10 + ch - 48; ch = getchar(); }
	return x * f;
}

const int maxn = 2e3 + 10;

int n, en, mn = 1e10, w[maxn][maxn], d[maxn];
struct Node { int u, v, w; } e[maxn * maxn];

signed main() {
	
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	n = read();

	for (int i = 1; i <= n; i ++) d[i] = 1e18;
	for (int i = 1; i < n; i ++)
		for (int j = i + 1; j <= n; j ++)
			mn = min(mn, w[i][j] = read());
	
	for (int i = 1; i < n; i ++)
		for (int j = i + 1; j <= n; j ++) {
			w[i][j] -= mn;
			if (!w[i][j]) d[i] = d[j] = 0;
			else e[++ en] = Node {i, j, w[i][j]};
		}
	
	sort(e + 1, e + en + 1, [](Node a, Node b) { return a.w < b.w; });
	for (int i = 1; i <= en; i ++) {
		auto [u, v, w] = e[i];
		int x = d[u], y = d[v];
		d[u] = min({d[u], y + w, 2 * w});
		d[v] = min({d[v], x + w, 2 * w});
	}

	for (int i = 1; i <= n; i ++)
		printf("%lld\n", d[i] + mn * (n - 1));

	return 0;
}