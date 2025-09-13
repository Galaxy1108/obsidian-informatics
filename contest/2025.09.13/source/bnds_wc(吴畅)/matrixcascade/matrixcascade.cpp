#include <bits/stdc++.h>
#define ru(i, l, r) for (int i = l; i <= r; i++)
#define rd(i, r, l) for (int i = r; i >= l; i--)
#define maxn 305
using namespace std;
const int INF = 2e18;
inline int read() {
	int x = 0; char ch = getchar();
	while(!isdigit(ch)) ch = getchar();
	while(isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return x;
}
int n, x, y, tot, a[maxn][maxn];
int t[maxn * maxn];
void add(int x) {
	for (; x <= n * n; x += x & (-x)) t[x]++;
}
int que(int x) {
	int res = 0;
	for (; x; x -= x & (-x)) res += t[x];
	return res;
}
int vis[maxn * maxn], ok;
int b[maxn * maxn];
void check() {
	int tot = 0;
	ru(i, 1, n) ru(j, 1, n) {
		b[++tot] = a[i][j];
	}
	int X = 0;
	ru(i, 1, tot) ru(j, i + 1, tot) {
		X += b[i] > b[j];
	}
	if(X != x) return;
	tot = 0;
	ru(i, 1, n) ru(j, 1, n) {
		b[++tot] = a[j][i];
	}
	int Y = 0;
	ru(i, 1, tot) ru(j, i + 1, tot) {
		Y += b[i] > b[j];
	}
	if(Y != y) return;
	ok = 1;
}
void dfs(int r, int c) {
	if(c > n) r++, c = 1;
	if(r > n) {
		check();
		return;
	}
	ru(j, 1, n * n) if(!vis[j]) {
		a[r][c] = j;
		vis[j] = 1;
		dfs(r, c + 1);
		if(ok) return;
		vis[j] = 0;
	}
}
void solve() {
	n = read(), x = read(), y = read();
	memset(vis, 0, sizeof(vis));
	if(n <= 3) {
		ok = 0;
		dfs(1, 1);
		if(!ok) {
			printf("NO\n");
		}
		else {
			printf("YES\n");
			ru(i, 1, n) {
				ru(j, 1, n) printf("%d ", a[i][j]); printf("\n");
			}
		}
		return;
	}
	memset(t, 0, sizeof(t)); tot = 0;
	if(x == 0) {
		ru(i, 1, n) ru(j, 1, n) a[i][j] = ++tot;
		ru(i, 1, n) ru(j, 1, n) {
			y -= que(n * n) - que(a[j][i]);
			add(a[j][i]);
		}
		if(y == 0) {
			printf("YES\n");
			ru(i, 1, n) {
				ru(j, 1, n) printf("%d ", a[i][j]); printf("\n");
			}
		}
		else {
			printf("NO\n");
		}
	}
	else if(y == 0) {
		ru(i, 1, n) ru(j, 1, n) a[j][i] = ++tot;
		ru(i, 1, n) ru(j, 1, n) {
			x -= que(n * n) - que(a[i][j]);
			add(a[i][j]);
		}
		if(x == 0) {
			printf("YES\n");
			ru(i, 1, n) {
				ru(j, 1, n) printf("%d ", a[i][j]); printf("\n");
			}
		}
		else {
			printf("NO\n");
		}
	}
	else {
		printf("NO\n");
	}
}
int main() {
	freopen("matrixcascade.in", "r", stdin);
	freopen("matrixcascade.out", "w", stdout);
	int T = read();
	while(T--) solve();
	return 0;
}