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

const int maxn = 1e5 + 10;
int n, q, w[maxn], b[maxn];

void work() {
	n = read();
	for (int i = 1; i <= n; i ++) w[i] = read(); 
	int t = w[2] - w[1];

	q = read();
	while (q --) {
		int l = read(), r = read();
		if (r - l + 1 <= 20) {
			bool fl = 0;
			for (int c = 1; c <= 10; c ++) if (!fl)
				for (int a = 0; a <= 10; a ++) if (!fl)
					for (int b = 0; b <= 10; b ++) if (!fl) {
						bool g = 1;
						for (int i = l; i <= r; i ++)
							g &= (a * (i - l) + b) / c == w[i];
						if (g) fl = 1, printf("%lld %lld %lld\n", a, b, c);
					}
		} else printf("%lld %lld %lld\n", 1, t, w[l]);
	}
}

signed main() {
	
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);
	
	int T = read();
	while (T --) work();
	
	return 0;
}