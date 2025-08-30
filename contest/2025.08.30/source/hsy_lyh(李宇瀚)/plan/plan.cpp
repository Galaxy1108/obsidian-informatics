#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define pc(x) putchar(x)
#define fi first
#define se second

using namespace std;

inline int read() {
	int x = 0, f=1; char ch = getchar();
	while(ch < '0' || ch > '9') {
		f = ch == '-' ? -1 : f; ch = getchar();
	}
	while(ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

void write(int x) {
	if(x < 0) {x = -x; putchar('-');}
	if(x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

int n, m, ans, a[505];
vector<int>e[505];
unordered_map<int, int>f[505][505], g[505];

int gcd(int x, int y) {
	return y ? gcd(y, x % y) : x;
}

void dfs(int x, int FA) {
	f[x][1][a[x]] = a[x];
	for(int y : e[x]) {
		if(y == FA)continue;
		dfs(y, x);
		for(int i = 1; i <= m; ++i) unordered_map<int, int>().swap(g[i]);
		for(int i = 1; i <= m; ++i)
			for(int j = 1; i + j - 1 <= m; ++j) {
				for(auto k : f[x][i])
					for(auto l : f[y][j]) {
						if(i + j <= m) g[i + j][k.fi] = max(g[i + j][k.fi], k.se + l.se);
						g[i + j - 1][gcd(k.fi, l.fi)] = max(g[i + j - 1][gcd(k.fi, l.fi)], k.se - k.fi + l.se - l.fi + gcd(k.fi, l.fi));
					}
			}
		swap(f[x], g);
	}
}

int main() {
	freopen("plan.in", "r", stdin);
	freopen("plan.out", "w", stdout);
	// double t=clock();
	n = read(), m = read() + 1;
	for(int i = 1; i < n; ++i) {
		int u = read(), v = read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i = 1; i <= n; ++i) a[i] = read();
	dfs(1, 0);
	for(auto it : f[1][m]) ans = max(ans, it.se);
	write(ans), pc('\n');
	// cerr<<(double)clock()-t<<'\n';
	return 0;
}